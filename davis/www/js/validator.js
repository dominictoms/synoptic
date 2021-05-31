function validate() {
   var messageText = document.getElementById("message-input").value;

   var valid = 0;

   //Check if empty
   if (!messageText) {
      valid = 1;
   }

   if (messageText.length > 2000) {
      valid = 2;
   }

   return valid;
}
