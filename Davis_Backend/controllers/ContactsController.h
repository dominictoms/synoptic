#pragma once
#include <drogon/HttpSimpleController.h>
using namespace drogon;
class ContactsController:public drogon::HttpSimpleController<ContactsController>
{
  private:
    Json::Value mJson;
  public:
    virtual void asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) override;
    PATH_LIST_BEGIN
    //list path definitions here;
    PATH_ADD("/contacts", Get);
    PATH_ADD("/chatlog", Get);
    PATH_LIST_END
};
