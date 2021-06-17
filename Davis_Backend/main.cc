#include <drogon/drogon.h>
#include <chrono>
#include <functional>
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <aws/core/Aws.h>
#include <aws/s3/S3Client.h>
#include <aws/s3/model/PutObjectRequest.h>
#include <awsdoc/s3/s3_examples.h>         
#include "profile.h"

using namespace drogon;
using namespace std::chrono_literals;

using namespace davis;

void initDb(const std::string& dbType, const std::string& dbHost, const ushort port, const std::string& dbName, 
        const std::string& userName, const std::string& password)
{
    LOG_INFO << "Initializing DB Client...\n";
    app().createDbClient(dbType, dbHost, port, dbName, userName, password);
    if(app().areAllDbClientsAvailable())
        LOG_INFO << "DB Client Available!\n";
}

// used to upload images to s3 bucket
bool AwsDoc::S3::PutObject(const Aws::String& bucketName,
    const Aws::String& objectName,
    const Aws::String& region)
{
	// does the file exist?
    struct stat buffer;

    if (stat(objectName.c_str(), &buffer) == -1)
    {
        std::cout << "Error: PutObject: File '" <<
            objectName << "' does not exist." << std::endl;

        return false;
    }

	// does the reigon exist?
    Aws::Client::ClientConfiguration config;

    if (!region.empty())
    {
        config.region = region;
    }

	// i have no idea what this does
    Aws::S3::S3Client s3_client(config);

    Aws::S3::Model::PutObjectRequest request;
    request.SetBucket(bucketName);
    request.SetKey(objectName);

    std::shared_ptr<Aws::IOStream> input_data =
        Aws::MakeShared<Aws::FStream>("SampleAllocationTag",
            objectName.c_str(),
            std::ios_base::in | std::ios_base::binary);

    request.SetBody(input_data);

    Aws::S3::Model::PutObjectOutcome outcome =
        s3_client.PutObject(request);

	// image upload succesful
    if (outcome.IsSuccess()) {

        std::cout << "Added object '" << objectName << "' to bucket '"
            << bucketName << "'.";
        return true;
    }

	// image upload failed
    else
    {
        std::cout << "Error: PutObject: " <<
            outcome.GetError().GetMessage() << std::endl;

        return false;
    }
}

int main()
{

	// log into pg database
    initDb("postgresql", "davisdbinstance.cbzc59oyz4iz.us-east-2.rds.amazonaws.com", 5432, "davisdb", "davis", "synoptic123");
       
	// grab the frontend
    app().setDocumentRoot("../../Davis_Frontend/www");
    app().enableDynamicViewsLoading({"../../Davis_Frontend/www"});
    app().setHomePage("signup.html");

    app().registerHandler("/signout", [](const HttpRequestPtr& req, std::function<void(const HttpResponsePtr &)> &&callback)
    {
        auto resp = HttpResponse::newRedirectionResponse("login.html?state=signedout");
        for(auto& cookies : resp->getCookies())
        {
            resp->removeCookie(cookies.first);
        }

        callback(resp);
    },
    {Get}
    );
    
    app().registerHandler("/profile", [](const HttpRequestPtr& req, std::function<void(const HttpResponsePtr &)> &&callback)
    {
    },
        {Get}
    );


    app().registerHandler("/addContact", [](const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& callback)
    {
        HttpResponsePtr resp;
         if(req->cookies().size() <= 1)    
        {
            resp = HttpResponse::newRedirectionResponse("login.html");
            callback(resp);  
            return;
        }     
        std::string newContactUserName = req->getParameter("username");


        auto query = app().getDbClient()->execSqlSync("SELECT accountId FROM account WHERE username=\'" + newContactUserName + "\'");
        if(query.size() < 1)
        {
            std::cout << "User does not exist!\n";
        }
        else
        {
            std::string accountId = query[0][0].as<std::string>();
            /* checks if current user is trying to add themselves to the contact list */
            if(accountId == req->getCookie("accountId"))
            {
                resp = HttpResponse::newRedirectionResponse("/contactMessages.html?state=contactInvalid");
                callback(resp);
                return;
            }
            auto friendship= app().getDbClient()->execSqlSync("select * from relationship where (account1=" + req->getCookie("accountId") 
                + " and account2=" +accountId + ") or (account2 =" + req->getCookie("accountId") 
                        + " and account1=" + accountId + ")");
            if(friendship.size() >= 1)
            {
                resp = HttpResponse::newRedirectionResponse("/contactMessages.html?state=contactAlreadyExists");
                callback(resp);
                return;
            }
            else
            {
                /* send temporary welcome message! */
                auto tempInsert = app().getDbClient()->execSqlSync("insert into message(sender, recipient, body) VALUES(" 
                + req->getCookie("accountId") + ", " + accountId + ",\'hi nice to meet you!\')");

                auto insertFriend = app().getDbClient()->execSqlSync("insert into relationship(account1, account2) VALUES(\'" 
                + req->getCookie("accountId") + "\',\'" + accountId + "\')");
            }
        }

        resp = HttpResponse::newRedirectionResponse("/contactMessages");
        callback(resp);
        
    },
    {Post}
    );

    
    app().registerHandler("/contactMessages", [](const HttpRequestPtr& req, std::function<void(const HttpResponsePtr &)> && callback)
    {
        HttpResponsePtr resp;
    			
        if(req->cookies().size() <= 1)    
        {
            resp = HttpResponse::newRedirectionResponse("login.html");
            callback(resp); 
            return; 
        }     
        try
	    {

		auto query = app().getDbClient()->execSqlSync("SELECT DISTINCT accountId from account where username=\'" 
	 			+ req->getCookie("username") + "\'");

        
        // checks if the account id in the cookie is valid 
     	std::string dbAccountId =query[0][0].as<std::string>();
		if(req->getCookie("accountId") != dbAccountId)
		{
			resp = HttpResponse::newRedirectionResponse("login.html");
            callback(resp);
		}
        else
        {
            resp = HttpResponse::newRedirectionResponse("contactMessages.html");  
            callback(resp);
        }
	} catch(const orm::DrogonDbException& e)
	{
		LOG_ERROR << e.base().what() << '\n';
	}
        callback(resp);

    },
    {Get}
    );
    
   
    app().registerHandler("/login",
        [](const HttpRequestPtr &req,
           std::function<void(const HttpResponsePtr &)> &&callback) mutable {
            auto resp = HttpResponse::newHttpResponse();
            std::string user = req->getParameter("username");
            std::string passwd = req->getParameter("password");
      
            try
            {

                // temporary insert check
                auto check = app().getDbClient()->execSqlSync("select * from account where username=\'" + user + "\'");
        		// check if user exists
                if(check.size() == 0)
                {
					// set signup page to failed state if account already exits
                    resp = HttpResponse::newRedirectionResponse("login.html?state=badusername");
                    
                    callback(resp);
                }

				// the user exists
				else
				{

					orm::Result query = app().getDbClient()->execSqlSync("SELECT * from account WHERE username =\'" + user + "\'");
        
                    profile* userProfile;
					for(const auto& rows : query)
					{           
						userProfile = new profile(rows);
					}

                    /* check the password entered is correct */
					if(userProfile->getPassword() == utils::getMd5(userProfile->getHashsalt() + passwd))
					{
                        std::cout << "hello\n";
                        resp = HttpResponse::newRedirectionResponse("contactMessages.html");

                        /* generate a bunch of cookies for user */ 
                        std::vector<Cookie> cookies{{"accountId", std::to_string(userProfile->getAccountId())}, 
                        {"username",userProfile->getUsername()}, {"forename",userProfile->getForename()}, 
                                {"surname",userProfile->getSurname()},{"email",userProfile->getEmail()},
                                    {"longitude",std::to_string(userProfile->getLongitude())}, {"latitude",std::to_string(userProfile->getLatitude())}, 
                                    {"profilePic", userProfile->getProfilePic()}};

                        
                        for(auto& c : cookies)
                        {
                            c.setHttpOnly(false);
                            resp->addCookie(c);
                        }
                        callback(resp);
					}
					else
					{
						resp = HttpResponse::newRedirectionResponse("login.html?state=badpassword");
             			callback(resp);
					}
				}
            }

            catch(const orm::DrogonDbException& e)
            {
                    LOG_ERROR << e.base().what() << '\n';
            }
                       
            },
            {Post}
           );
          
		app().registerHandler("/signup", [](const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& callback)
        {
            auto params = req->getParameters();
            auto resp = HttpResponse::newHttpResponse();   
            req->session()->insert("registered", true);
            std::string hashsalt = utils::genRandomString(32);
           
            try
            {
                /* temporary insert check */
                auto check = app().getDbClient()->execSqlSync("select * from account where username=\'" + params["username"] + "\'");
               

                if(check.size() > 0)
                {
					// set signup page to failed state if account already exits
                    resp = HttpResponse::newRedirectionResponse("signup.html?state=existingaccount");
                    callback(resp);
                    return;
                }

                else
                {
					// otherwise add new user to the database
                    auto insert = app().getDbClient()->execSqlSync(
                    "insert into account (username, forename, surname, password, profilepic, latitude, longitude, hashsalt, email) "
                       "VALUES(\'" + params["username"] + "\'" + ",\'" + params["forename"] + "\',\'" + params["surname"] 
                       + "\',\'" + utils::getMd5(hashsalt + params["password"]) + "\',\'" 
                       + "https://daviss3bucket.s3.eu-west-2.amazonaws.com/default-avatar.png" + "\',36.1699, 115.1398,\'" + hashsalt + "\',\'" +  params["email"] + "\')"); 
                }
            }
			
			catch(orm::DrogonDbException& e)
            {
                LOG_ERROR << e.base().what() << '\n';
            }
            
			// output account table after adding new user
			/*
            app().getDbClient()->execSqlAsync("SELECT * FROM account", [](const orm::Result& r)
            {
                for(const auto& rows : r)
                {
                    for(const auto& fields : rows)
                    {
                        std::cout << fields.as<std::string>() << '\t';
                    }
                    std::cout << '\n';
                }
            },

            [](const orm::DrogonDbException& e)
            {
                LOG_ERROR << e.base().what() << '\n';
            });
			*/
            
			// redirect to login page after adding new user
            resp = HttpResponse::newRedirectionResponse("/login.html");
            callback(resp);
        },
        {
            Post
        }
    );

    /* add http listener */ 
    LOG_INFO << "Server running on 127.0.0.1:8869";
    app().enableSession(24h).addListener("127.0.0.1", 8869).run();
}

