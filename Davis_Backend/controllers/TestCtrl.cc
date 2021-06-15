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

    resp->setStatusCode(k200OK);
    callback(resp);
}
