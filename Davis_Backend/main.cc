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
    profile* userProfile;

	// log into pg database
    initDb("postgresql", "davisdbinstance.cbzc59oyz4iz.us-east-2.rds.amazonaws.com", 5432, "davisdb", "davis", "synoptic123");
       
	// grab the frontend
    app().setDocumentRoot("../../Davis_Frontend/www");
    app().enableDynamicViewsLoading({"../../Davis_Frontend/www"});
    app().setHomePage("signup.html");

    app().registerHandler("/", [](const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) 
    {

        bool registered = req->session()->getOptional<bool>("registered").value_or(false);
        HttpResponsePtr resp;
        
        if(!registered)
            resp = HttpResponse::newHttpViewResponse("signup");
        else
        {
            bool logined = req->session()->getOptional<bool>("logined").value_or(false);
            if (!logined)
                resp = HttpResponse::newHttpViewResponse("login");
            else
            {

                resp = HttpResponse::newHttpViewResponse("profile");
            }
       
        }
        callback(resp);
    });
 
    app().registerHandler("/logout", [userProfile](const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) mutable
        {
            userProfile = nullptr;
            HttpResponsePtr resp = HttpResponse::newHttpResponse();
            req->session()->erase("logined");
            resp->setBody("<script>window.location.href = \"/\";</script>");
            
            callback(resp);
            
    
        },
            {Get}
        );
    
    app().registerHandler("/profile", [userProfile](const HttpRequestPtr& req, std::function<void(const HttpResponsePtr &)> &&callback)
    {


        auto resp = HttpResponse::newRedirectionResponse("profile.html");
        callback(resp);
            
    },
        {Get}
    );
   
    app().registerHandler("/login",
        [userProfile](const HttpRequestPtr &req,
           std::function<void(const HttpResponsePtr &)> &&callback) mutable {
            auto resp = HttpResponse::newHttpResponse();
            std::string user = req->getParameter("userName");
            std::string passwd = req->getParameter("password");
      
            try
            {
                orm::Result query = app().getDbClient()->execSqlSync("SELECT * from account WHERE username =\'" + user + "\'");
                for(const auto& rows : query)
                {           
                    
                    userProfile = new profile(rows);
                }

                if(userProfile->getPassword() == utils::getMd5(userProfile->getHashsalt() + passwd))
                {
                    
                    Json::Value json;
                    json["username"] = userProfile->getUsername();
                    json["surname"] = userProfile->getSurname();
                    json["forename"] = userProfile->getForename();
                    json["email"] = userProfile->getEmail();
                    json["longitude"] = userProfile->getLongitude();
                    json["latitude"] = userProfile->getLatitude();
                    resp = HttpResponse::newRedirectionResponse("contactMessages.html");
                    callback(resp);
                }
                else
                {
                 
                    resp = HttpResponse::newRedirectionResponse("login.html?state=failed");
                    callback(resp);
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
                auto check = app().getDbClient()->execSqlSync("select * from account where username=\'" + params["userName"] + "\'");
                std::cout << check.size() << '\n';

                if(check.size() > 0)
                {
					// set signup page to failed state if account already exits
                    resp = HttpResponse::newRedirectionResponse("signup.html?state=failed");
                    callback(resp);
                }

                else
                {
					// otherwise add new user to the database
                    auto insert = app().getDbClient()->execSqlSync(
                    "insert into account (username, forename, surname, password, profilepic, latitude, longitude, hashsalt, email) "
                       "VALUES(\'" + params["userName"] + "\'" + ",\'" + params["forename"] + "\',\'" + params["surname"] 
                       + "\',\'" + utils::getMd5(hashsalt + params["password"]) + "\',\'" 
                       + params["profile_picture"] + "\',36.1699, 115.1398,\'" + hashsalt + "\',\'" +  params["email"] + "\')"); 
                }
            }
			
			catch(orm::DrogonDbException& e)
            {
                LOG_ERROR << e.base().what() << '\n';
            }
            
			// output account table after adding new user
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
            
			// redirect to login page after adding new user
            resp = HttpResponse::newRedirectionResponse("/login");
            callback(resp);
        },
        {
            Post
        }
    );
 
    LOG_INFO << "Server running on 127.0.0.1:8848";
    app().enableSession(24h).addListener("127.0.0.1", 8848).run();
}

