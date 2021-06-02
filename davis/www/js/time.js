function getTime() {
   var time = new Date();
   hour = time.getHours();
   var minutes;

   if (time.getMinutes() < 10) {
      minutes = "0" + time.getMinutes();
   } else {
      minutes = time.getMinutes();
   }

   if (hour > 12) {
      hour = hour - 12;
      minutes += " pm";
   } else {
      minutes += " am";
   }

   return hour + ":" + minutes;
}
