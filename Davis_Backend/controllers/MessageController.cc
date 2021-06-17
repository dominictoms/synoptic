#include "MessageController.h"
#include <cstdio>
void MessageController::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{

    app().getDbClient()->execSqlSync("insert into message(sender, recipient, body) VALUES(" + req->getCookie("accountId") + "," +  req->getCookie("sendID") + ",\'" + req->getParameter("text") + "\')");
    auto resp = HttpResponse::newHttpResponse();
   
    callback(resp);

}