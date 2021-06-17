#include "MessageBubbleController.h"
#include <iostream>

void MessageBubbleController::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    std::cout << "display messages!\n";
    std::string cookieID = req->getCookie("cookieID");
    std::string userId = req->getCookie("userId");

    std::cout << cookieID << userId << "endl\n";

    auto messages = app().getDbClient()->execSqlSync("select * from message where (sender=28 and recipient=29) or (sender=29 and recipient=28) order by deliverytime");

    Json::Value json;
    for(int i=0; i < messages.size(); i++)
    {
        json[i]["sender"] = messages[i][1].as<std::string>();
        json[i]["recipient"] = messages[i][2].as<std::string>();
        json[i]["body"] = messages[i][3].as<std::string>();
        json[i]["deliverytime"] = messages[i][4].as<std::string>();
        
    }
    auto resp = HttpResponse::newHttpJsonResponse(json);
    callback(resp);
}
