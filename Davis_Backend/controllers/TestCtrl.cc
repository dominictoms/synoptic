#include "TestCtrl.h"
#include <iostream>

void TestCtrl::asyncHandleHttpRequest(const HttpRequestPtr &req,
                                      std::function<void (const HttpResponsePtr &)> &&callback)
{
	// this is scuffed but just a placeholder
	Json::Value json;
	json["imageURL"] = "https://daviss3bucket.s3.eu-west-2.amazonaws.com/lum.jpg";
	json["contactName"] = "Terry Davis";
	json["lastMessage"] = "I like elephants and God likes elephants.";
	json["userId"] = 69;

	// send the json off
	auto resp = HttpResponse::newHttpJsonResponse(json);

	try
	{
		
		auto query = app().getDbClient()->execSqlSync("SELECT accountId, hashsalt from account where userName = \'" 
	 			+ resp->getCookie("username").getValue() + "\'");

		std::string hashedAccountId = utils::getMd5(query[0][0].as<std::string>() + query[0][1].as<std::string>());
		if(resp->getCookie("accountId").getValue() != hashedAccountId)
		{
			std::cout << "AccountID not found!\n";
			resp = HttpResponse::newRedirectionResponse("login.html");
			for(auto const& cookies : resp->getCookies())
			{
				resp->removeCookie(cookies.first);
			}
			callback(resp);
		}
		else if(resp->cookies().empty())
		{
			resp = HttpResponse::newRedirectionResponse("login.html");
			callback(resp);
		}
	} catch(const orm::DrogonDbException& e)
	{
		LOG_ERROR << e.base().what() << '\n';
	}


    resp->setStatusCode(k200OK);
    callback(resp);
}
