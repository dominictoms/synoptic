"use strict";

const urlString = window.location.search;
const userParam = new URLSearchParams(urlString);
const userState = userParam.get("state");
const error = document.getElementById("error");

if (userState === "failed")
{
	error.style.display = "block";
}

function displayErrorMessage(userState)
{
	if (!userState) return;

	// display the error message
	error.style.display = "block";

	// grab the header
	var errortxt = document.getElementById("invalidlogintxt");

	switch(userState)
	{
		case "badusername":
			errortxt.innerHTML = "Invalid username.";
			break;

		case "badpassword":
			errortxt.innerHTML = "Invalid password.";
			break;

		case "existingaccount":
			errortxt.innerHTML = "Username isn't available.";
			break;
	}
}

displayErrorMessage(userState);
