"use strict";

//location of name in header
var contactName = document.getElementById("header-contact-name"); //the blank "start messaging" panel

var blankPanel = document.getElementById("blank-panel"); //Giving the contact clickability

var footer = document.getElementById("footer");
var chat = document.getElementById("chat");
var contact = document.getElementsByClassName("contact");

var _loop = function _loop(i) {
  contact[i].addEventListener("click", function () {
    function1(i);
  });
};

for (var i = 0; i < contact.length; i++) {
  _loop(i);
} //Changing the message panel


function function1(contactID) {
  var data = contact[contactID].innerText.split("\n"); //To detect if we are on a mobile device I will use some code found here (https://stackoverflow.com/questions/3514784/what-is-the-best-way-to-detect-a-mobile-device)

  if (/Android|webOS|iPhone|iPad|Mac|Macintosh|iPod|BlackBerry|IEMobile|Opera Mini/i.test(navigator.userAgent)) {
    //If the user is on a phone we need to instead change the page
    window.location.replace("messages.html?userId=" + data[0] + "");
  } else {
    //If the user is on a desktop we can use the split display
    //currently using the name to go the the message page
    contactName.innerText = data[0]; //If the user has clicked on a contact we can remove this panel for this session

    footer.style.display = "block";
    chat.style.height = "calc(100% - 118px)";
    blankPanel.remove();
    console.log("pog");
  }
}

function addContact(imageURL, contactName, lastMessage) {
  document.getElementById("contact-panel").innerHTML += '\n   <div class="row contact-row flex-nowrap">\n      <a href="profile.html">\n         <div class="col-3 contact-left">\n            <img src="' + imageURL + '" alt="" />\n         </div>\n      </a>\n      <a class="contact">\n         <div class="col-9 contact-right">\n            <div class="contact-name">' + contactName + '</div>\n            <div class="contact-message">\n                  ' + lastMessage + "\n            </div>\n         </div>\n      </a>\n   </div>\n   ";
  console.log("works");
  var contact = document.getElementsByClassName("contact");

  var _loop = function _loop(i) {
    contact[i].addEventListener("click", function () {
      function1(i);
    });
  };

  for (var i = 0; i < contact.length; i++) {
    _loop(i);
  }
}