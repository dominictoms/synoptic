const mapDiv = document.getElementById("map");

function sendLocation(position) {
   console.log(position.coords.latitude + " | " + position.coords.longitude);
   mapDiv.innerHTML =
      `<iframe
   width="100%"
   height="600"
   src="https://maps.google.com/maps?width=100%25&amp;height=600&amp;hl=en&amp;q=` +
      position.coords.latitude +
      `,` +
      position.coords.longitude +
      `+()&amp;t=h&amp;z=14&amp;ie=UTF8&amp;iwloc=B&amp;output=embed"
></iframe>`;
}

//Function to set the html map via two parameters
function setLocation(lat, long) {
   mapDiv.innerHTML =
      `<iframe
   width="100%"
   height="600"
   src="https://maps.google.com/maps?width=100%25&amp;height=600&amp;hl=en&amp;q=` +
      lat +
      `,` +
      long +
      `+()&amp;t=h&amp;z=14&amp;ie=UTF8&amp;iwloc=B&amp;output=embed"
></iframe>`;
}

navigator.geolocation.watchPosition(sendLocation);
