#include "MessageController.h"
#include <cstdio>
void MessageController::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    std::cout << req->getParameter("text") << '\n';
    app().getDbClient()->execSqlSync("insert into message(sender, recipient, body) VALUES(28, 29,\'" + req->getParameter("text") + "\')");
    auto resp = HttpResponse::newHttpResponse();
    callback(resp);

}