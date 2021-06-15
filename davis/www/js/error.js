const urlString = window.location.search;
const userParam = new URLSearchParams(urlString);
const userState = userParam.get("state");
const error = document.getElementById("error");

if (userState === "failed") {
   error.style.display = "block";
}

console.log(userState);
