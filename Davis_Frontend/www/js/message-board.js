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
   var data = contact[contactID].innerHTML.split("\n");
   var data2 = contact[contactID].innerText.split("\n");
   console.log(data2[0]); //To detect if we are on a mobile device I will use some code found here (https://stackoverflow.com/questions/3514784/what-is-the-best-way-to-detect-a-mobile-device)
   var replace = data[5];
   id = replace.replace('<div style="visibility: hidden;">', "");
   id = id.replace(" </div>", "");
   id = id.trim();
   console.log(id);
   if (
      /Android|webOS|iPhone|iPad|Mac|Macintosh|iPod|BlackBerry|IEMobile|Opera Mini/i.test(
         navigator.userAgent
      )
   ) {
      //If the user is on a phone we need to instead change the page
      window.location.replace("messages.html?userId=" + data2[0] + "");
   } else {
      //If the user is on a desktop we can use the split display
      //currently using the name to go the the message page
      contactName.innerText = data2[0]; //If the user has clicked on a contact we can remove this panel for this session
      footer.style.display = "block";
      chat.style.height = "calc(100% - 118px)";
      blankPanel.remove();
      clearMessages();
   }
}

function getUserMessages(userId) {
   const getCookie = (name) => {
      return document.cookie.split("; ").reduce((r, v) => {
         const parts = v.split("=");
         return parts[0] === name ? decodeURIComponent(parts[1]) : r;
      }, "");
   };
   var cookieUserId = getCookie("accountId");

   var httpReq = new XMLHttpRequest();
   httpReq.open("POST", "/displayMessages");
   http.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");

   http.onreadystatechange = function () {
      // Call a function when the state changes.
      if (this.readyState === XMLHttpRequest.DONE && this.status === 200) {
      }
   };

   http.send("cookieID=" + cookieUserId + "&" + "userId=" + userId);
}

function addContact(imageURL, contactName, lastMessage, userID) {
   document.getElementById("contact-panel").innerHTML +=
      `<div class="row contact-row flex-nowrap">
         <a href="profile.html">
            <div class="col-3 contact-left">
               <img src="` +
      imageURL +
      `" alt="" />
            </div>
         </a>
         <a class="contact">
            <div class="col-9 contact-right">
               <div class="contact-name">` +
      contactName +
      `</div>
               <div class="contact-message">` +
      lastMessage +
      `</div>
            </div> 
         <div style="visibility: hidden;">` +
      userID +
      ` </div>
      </a>
   </div>`;

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
