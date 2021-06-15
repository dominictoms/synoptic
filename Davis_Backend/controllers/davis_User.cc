#include "davis_User.h"
using namespace davis;
void User::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    //write your application logic here

   std::string accountID = req->getCookie("accountId");
   std::cout << accountID << '\n';
   auto resp = HttpResponse::newRedirectionResponse("profile.html");
   callback(resp);
}