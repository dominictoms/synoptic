"use strict";

var mapDiv = document.getElementById("map");

function sendLocation(position) {
  console.log(position.coords.latitude + " | " + position.coords.longitude);
  mapDiv.innerHTML = "<iframe\n   width=\"100%\"\n   height=\"600\"\n   src=\"https://maps.google.com/maps?width=100%25&amp;height=600&amp;hl=en&amp;q=" + position.coords.latitude + "," + position.coords.longitude + "+()&amp;t=h&amp;z=14&amp;ie=UTF8&amp;iwloc=B&amp;output=embed\"\n></iframe>";
}

navigator.geolocation.watchPosition(sendLocation, {
  enableHighAccuracy: true
});