//location of name in header
const contactName = document.getElementById("header-contact-name");
//the blank "start messaging" panel
const blankPanel = document.getElementById("blank-panel");

//Giving the contact clickability
const contact = document.getElementsByClassName("contact");
for (let i = 0; i < contact.length; i++) {
   contact[i].addEventListener("click", function () {
      function1(i);
   });
}

//Changing the message panel
function function1(contactID) {
   var data = contact[contactID].innerText.split("\n");
   //To detect if we are on a mobile device I will use some code found here (https://stackoverflow.com/questions/3514784/what-is-the-best-way-to-detect-a-mobile-device)
   if (
      /Android|webOS|iPhone|iPad|Mac|Macintosh|iPod|BlackBerry|IEMobile|Opera Mini/i.test(
         navigator.userAgent
      )
   ) {
      //If the user is on a phone we need to instead change the page
      window.location.replace("messages.html?userId=" + data[0] + "");
   } else {
      //If the user is on a desktop we can use the split display

      //currently using the name to go the the message page

      contactName.innerText = data[0];
      //If the user has clicked on a contact we can remove this panel for this session
      blankPanel.remove();
   }
}

function addContact(imageURL, contactName, lastMessage) {
   document.getElementById("contact-panel").innerHTML +=
      `
   <div class="row contact-row flex-nowrap">
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
            <div class="contact-message">
                  ` +
      lastMessage +
      `
            </div>
         </div>
      </a>
   </div>
   `;
}
