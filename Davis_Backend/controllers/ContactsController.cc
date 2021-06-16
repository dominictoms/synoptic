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

             
            auto user = app().getDbClient()->execSqlSync("select * from account where accountId=" + std::to_string(userID));
        
        mJson[i]["imageURL"] = user[0][6].as<std::string>();
	    mJson[i]["contactName"] = user[0][2].as<std::string>();
	    mJson[i]["lastMessage"] = "I like elephants and God likes elephants.";
	    mJson[i]["userId"] = 22;

     
    }


    
    // send the json off
	resp = HttpResponse::newHttpJsonResponse(mJson);

    resp->setStatusCode(k200OK);
    callback(resp);


}