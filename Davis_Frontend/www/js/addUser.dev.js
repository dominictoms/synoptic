"use strict";

function addUserClose() {
  var addUserPanel = document.getElementById("add-user-panel");
  var darkenPanel = document.getElementById("darken-panel");
  addUserPanel.style.display = "none";
  darkenPanel.style.display = "none";
}

function addUserShow() {
  //List of error messages
  var addUserPanel = document.getElementById("add-user-panel");
  var darkenPanel = document.getElementById("darken-panel");
  addUserPanel.style.display = "block";
  darkenPanel.style.display = "block";
  document.getElementById("add-user-close").addEventListener("click", addUserClose);
}