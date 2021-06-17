#include "ContactsController.h"
void ContactsController::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    /* insert friends into contacts list */

	auto query = app().getDbClient()->execSqlSync("select account1, account2 from relationship where account1=" + req->getCookie("accountId") + " or account2=" + req->getCookie("accountId"));
	// get friend of account1 
    HttpResponsePtr resp;
    if(query.size() < 1)
    {
        resp = HttpResponse::newRedirectionResponse("contactMessages.html");
        callback(resp);
        return;
    }
    for(int i=0; i < query.size(); i++)
    {

        int userID = -1;
        
	    if(query[i][0].as<std::string>() == req->getCookie("accountId"))
	    {
		    userID = query[i][1].as<int>();
    	}
	// get friend of account 2 
	    else if(query[i][1].as<std::string>() == req->getCookie("accountId"))
	    {
		    userID = query[i][0].as<int>();
	    }

        std::string userIdStr = std::to_string(userID);
        

        auto user = app().getDbClient()->execSqlSync("select profilepic, forename, surname, body" 
        " from account, message where accountId=" + userIdStr + " and (sender=" + userIdStr + " or recipient=" + userIdStr + 
        ") and (sender=" + req->getCookie("accountId") + " or recipient=" + req->getCookie("accountId") + ") order by deliverytime desc limit 1;");

        
        mJson[i]["imageURL"] = user[0][0].as<std::string>();
	    mJson[i]["contactName"] = user[0][1].as<std::string>() + " " + user[0][2].as<std::string>();
	    mJson[i]["lastMessage"] =user[0][3].as<std::string>();
	    mJson[i]["userId"] = userID;
    }


    // send the json off
	resp = HttpResponse::newHttpJsonResponse(mJson);

	std::cout<<mJson<<"\n";

    callback(resp);


}
