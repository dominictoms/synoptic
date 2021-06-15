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
	json = JSON.parse(json);

	// add the new user
	addContact(json.imageURL, json.contactName, json.lastMessage, json.userId);
}
