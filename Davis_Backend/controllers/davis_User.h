#pragma once
#include <drogon/HttpSimpleController.h>
using namespace drogon;
namespace davis
{
class User:public drogon::HttpSimpleController<User>
{
  public:
    virtual void asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) override;
    PATH_LIST_BEGIN
    //list path definitions here;
    PATH_ADD("/profile", Get);

    PATH_ADD("/login", Get);
    PATH_LIST_END
};
}
