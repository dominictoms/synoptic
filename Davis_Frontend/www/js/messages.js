//To detect if we are on a mobile device I will use some code found here (https://stackoverflow.com/questions/3514784/what-is-the-best-way-to-detect-a-mobile-device)
if (
   /Android|webOS|iPhone|iPad|Mac|Macintosh|iPod|BlackBerry|IEMobile|Opera Mini/i.test(
      navigator.userAgent
   )
) {
   //If the device is on mobile the user is controlled by urlparameter at this point as the api use is unknown
   //This code will get the url parameter and change the header to display the contacts name
   const urlString = window.location.search;
   const userParam = new URLSearchParams(urlString);
   const userParamID = userParam.get("userId");
   const contactName = document.getElementById("header-contact-name");
   contactName.innerText = userParamID;


}

//Adding event listener to the submit button
/*
const submitButton = document.getElementById("submit");
submitButton.addEventListener("click", userMessage);
*/
//Send press on enter press
var isKeyDown = false;
document.addEventListener("keydown", function (event) {
   if (event.key == "Enter" && isKeyDown==true) {
      isKeyDown = true;
      document.addEventListener("keyup", function(event)
      {
         httpPost();
         isKeyDown = false;
      })
   }
});

//Error message - event of invalid message
function errorMessage(value) {
   //List of error messages
   const errorMessages = [
      "",
      "You cannot send a message with no body",
      "Message is too long, exceeds 2000 characters",
   ];

   var errorField = document.getElementById("error-field");
   var errorBox = document.getElementById("error-box");
   errorBox.style.display = "block";
   errorField.style.display = "block";

   errorBox.innerHTML =
      `<span class="close-button" id="error-close">&#10005</span>` + errorMessages[value];

   document.getElementById("error-close").addEventListener("click", errorMessageClose);
}

//Function to close the error message pop-up and field
function errorMessageClose() {
   var errorField = document.getElementById("error-field");
   var errorBox = document.getElementById("error-box");
   errorBox.style.display = "none";
   errorField.style.display = "none";
}

//Message from contact - left side
function contactMessage(messageText) {
   document.getElementById("chat").innerHTML +=
      `<div class="row no-gutters">
    <div class="col">
        <div class="message">
            <div class="message-left-first">` +
      messageText +
      `</div>
        </div>
    </div>
    </div>`;

   //Scroll to the most recent message
   document.getElementById("chat").scrollTop = document.getElementById("chat").scrollHeight;

}



function httpPost()
{

   var formData = new FormData(document.getElementById("send-message-form"));
	var http = new XMLHttpRequest();
	http.open("POST", "/sendMessages", true);
   http.setRequestHeader("Content-Type", "application/x-www-form-urlencoded"); 




   const userState = "";
   http.onreadystatechange = function() { // Call a function when the state changes.
      if (this.readyState === XMLHttpRequest.DONE && this.status === 200) {
          userMessageVar(formData.get("message-input"));

         }
      }
      
 
 
   console.log(userState);
   http.send("text="+formData.get("message-input"));



   return formData.get("message-input");
   
}



/* insert message bubble */
function userMessageVar(input) {
   document.getElementById("chat").innerHTML +=
      `
      <div class="row no-gutters">
          <div class="col">
              <div class="message">
                  <div class="message-right-first float-end">` +
      input +
      `</div>
                  <div class="message-time-right float-end">` +
      getTime() +
      `</div>
              </div>
          </div>
      </div>
      `;

   //Scroll to the most recent message
   document.getElementById("chat").scrollTop = document.getElementById("chat").scrollHeight;

   //Clear the input box as the message successfully sent
   document.getElementById("message-input").value = "";
}

//Message from user - right side
function userMessage() {
   //Get form value

   var messageText = document.getElementById("message-input").value;

   var validResult = validate();

   if (validResult == 0) {
      //Get the current time

      //Add the html to the page
      document.getElementById("chat").innerHTML +=
         `
            <div class="row no-gutters">
                <div class="col">
                    <div class="message">
                        <div class="message-right-first float-end">` +
         messageText +
         `</div>
                        <div class="message-time-right float-end">` +
         getTime() +
         `</div>
                    </div>
                </div>
            </div>
            `;

      //Scroll to the most recent message
      document.getElementById("chat").scrollTop = document.getElementById("chat").scrollHeight;

      //Clear the input box as the message successfully sent
      document.getElementById("message-input").value = "";
   } else {
      errorMessage(validResult);
   }
}

function clearMessages() {
   document.getElementById("chat").innerHTML = "";
}
