// lets go boys
"use strict";

// send a get request when the page loads
onload=addContacts(httpGet("contacts"));

// send a get request and return the response
function httpGet(url)
{
	var http = new XMLHttpRequest();
	http.open("GET", url, false);
	http.send(null);
	return http.responseText;
}

// loop through contacts json and add the contacts
function addContacts(json)
{
	// convert from json to object
	if(!json)
		return;
	json = JSON.parse("{\"arr\":"+json+"}");
	console.log(json);
	for(var i = 0; i < json.arr.length; i++)
	{

		addContact(json.arr[i].imageURL, json.arr[i].contactName, json.arr[i].lastMessage, json.arr[i].userId);
	}

	// add the new user
}
