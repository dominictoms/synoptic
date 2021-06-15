// send a get request when the page loads
onload=addContacts(httpGet("test"));

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
	console.log(json);
}
