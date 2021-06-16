#include "MessageController.h"
#include <cstdio>
void MessageController::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    for(auto const key : req->getParameters())
    {
        std::cout << key.second << '\n';
    }
    app().getDbClient()->execSqlSync("insert into message(send, recipient, body) VALUES(28, 29,'\'" + req->getParameter("message-input") + "\')");
    
    auto resp = HttpResponse::newHttpResponse();
    resp->setStatusCode(k200OK);
    callback(resp);
}