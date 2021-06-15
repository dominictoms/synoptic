"use strict";

function validateForm() {
  var signupform = document.forms.signupform;
  var signupformData = new FormData(signupform);
  var formEmail = signupformData.get("email");
  var formForename = signupformData.get("forename");
  var formSurname = signupformData.get("surname");
  var formUsername = signupformData.get("username");

  if (formEmail.length > 255 | formUsername.length > 20 | formSurname.length > 20 | formForename.length > 20) {
    console.log("invalid");
    return false;
  } else {
    return true;
  }
}