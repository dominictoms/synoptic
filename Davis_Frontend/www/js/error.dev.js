"use strict";

var urlString = window.location.search;
var userParam = new URLSearchParams(urlString);
var userState = userParam.get("state");
var error = document.getElementById("error");

if (userState === "failed") {
  error.style.display = "block";
}

console.log(userState);