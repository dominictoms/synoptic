//Adding event listener to the submit button
const submitButton = document.getElementById("submit");
submitButton.addEventListener("click", userMessage);

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
