//this file is generated by program(drogon_ctl) automatically,don't modify it!
#include "profile.h"
#include <drogon/utils/OStringStream.h>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <list>
#include <deque>
#include <queue>
using namespace drogon;
std::string profile::genText(const DrTemplateData& profile_view_data)
{
	drogon::OStringStream profile_tmp_stream;
	std::string layoutName{""};
	profile_tmp_stream << "<!DOCTYPE html>\n";
	profile_tmp_stream << "<!--\n";
	profile_tmp_stream << "    Licensed to the Apache Software Foundation (ASF) under one\n";
	profile_tmp_stream << "    or more contributor license agreements.  See the NOTICE file\n";
	profile_tmp_stream << "    distributed with this work for additional information\n";
	profile_tmp_stream << "    regarding copyright ownership.  The ASF licenses this file\n";
	profile_tmp_stream << "    to you under the Apache License, Version 2.0 (the\n";
	profile_tmp_stream << "    \"License\"); you may not use this file except in compliance\n";
	profile_tmp_stream << "    with the License.  You may obtain a copy of the License at\n";
profile_tmp_stream<<"\n";
	profile_tmp_stream << "    http://www.apache.org/licenses/LICENSE-2.0\n";
profile_tmp_stream<<"\n";
	profile_tmp_stream << "    Unless required by applicable law or agreed to in writing,\n";
	profile_tmp_stream << "    software distributed under the License is distributed on an\n";
	profile_tmp_stream << "    \"AS IS\" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY\n";
	profile_tmp_stream << "     KIND, either express or implied.  See the License for the\n";
	profile_tmp_stream << "    specific language governing permissions and limitations\n";
	profile_tmp_stream << "    under the License.\n";
	profile_tmp_stream << "-->\n";
	profile_tmp_stream << "<html>\n";
	profile_tmp_stream << "   <head>\n";
	profile_tmp_stream << "      <meta charset=\"utf-8\" />\n";
	profile_tmp_stream << "      <!--\n";
	profile_tmp_stream << "        Customize this policy to fit your own app's needs. For more guidance, see:\n";
	profile_tmp_stream << "            https://github.com/apache/cordova-plugin-whitelist/blob/master/README.md#content-security-policy\n";
	profile_tmp_stream << "        Some notes:\n";
	profile_tmp_stream << "            * gap: is required only on iOS (when using UIWebView) and is needed for JS->native communication\n";
	profile_tmp_stream << "            * https://ssl.gstatic.com is required only on Android and is needed for TalkBack to function properly\n";
	profile_tmp_stream << "            * Disables use of inline scripts in order to mitigate risk of XSS vulnerabilities. To change this:\n";
	profile_tmp_stream << "                * Enable inline JS: add 'unsafe-inline' to default-src\n";
	profile_tmp_stream << "        -->\n";
	profile_tmp_stream << "      <meta\n";
	profile_tmp_stream << "         http-equiv=\"Content-Security-Policy\"\n";
	profile_tmp_stream << "         content=\"default-src 'self' data: gap: https://ssl.gstatic.com 'unsafe-eval';\n";
	profile_tmp_stream << "          style-src 'self' 'unsafe-inline'; media-src *; img-src 'self' data: content:;\n";
	profile_tmp_stream << "           script-src 'self' https://maps.google.com/ 'unsafe-inline' 'unsafe-eval';\n";
	profile_tmp_stream << "            frame-src https://maps.google.com/ https://www.google.com/;\"\n";
	profile_tmp_stream << "      />\n";
	profile_tmp_stream << "      <meta name=\"format-detection\" content=\"telephone=no\" />\n";
	profile_tmp_stream << "      <meta name=\"msapplication-tap-highlight\" content=\"no\" />\n";
	profile_tmp_stream << "      <meta name=\"viewport\" content=\"initial-scale=1, width=device-width, viewport-fit=cover\" />\n";
	profile_tmp_stream << "      <meta name=\"color-scheme\" content=\"light dark\" />\n";
	profile_tmp_stream << "      <title>Davis | Chat</title>\n";
	profile_tmp_stream << "      <link rel=\"stylesheet\" href=\"css/bootstrap.min.css\" />\n";
	profile_tmp_stream << "      <link rel=\"stylesheet\" href=\"css/profile.min.css\" />\n";
	profile_tmp_stream << "   </head>\n";
	profile_tmp_stream << "   <body>\n";
	profile_tmp_stream << "      <!--Navigation Bar-->\n";
	profile_tmp_stream << "      <nav class=\"navbar navbar-dark nav-colour fixed-top\">\n";
	profile_tmp_stream << "         <div class=\"container-fluid\">\n";
	profile_tmp_stream << "            <span class=\"navbar-brand mb-0 h1\"\n";
	profile_tmp_stream << "               ><a id=\"back\" href=\"contactMessages.html\"><-</a></span\n";
	profile_tmp_stream << "            >\n";
	profile_tmp_stream << "            <span class=\"navbar-brand mb-0 h1\">Mike Johnson</span>\n";
	profile_tmp_stream << "            <div class=\"dropdown\">\n";
	profile_tmp_stream << "               <button\n";
	profile_tmp_stream << "                  class=\"btn btn-secondary transparent\"\n";
	profile_tmp_stream << "                  type=\"button\"\n";
	profile_tmp_stream << "                  id=\"dropdownMenuButton2\"\n";
	profile_tmp_stream << "                  data-bs-toggle=\"dropdown\"\n";
	profile_tmp_stream << "                  aria-expanded=\"false\"\n";
	profile_tmp_stream << "               >\n";
	profile_tmp_stream << "                  <img class=\"icon dropdown-icon\" src=\"images/menu.svg\" alt=\"Send\" />\n";
	profile_tmp_stream << "               </button>\n";
	profile_tmp_stream << "               <ul\n";
	profile_tmp_stream << "                  class=\"dropdown-menu dropdown-menu-dark dropdown-menu-right\"\n";
	profile_tmp_stream << "                  aria-labelledby=\"dropdownMenuButton2\"\n";
	profile_tmp_stream << "               >\n";
	profile_tmp_stream << "                  <li><a class=\"dropdown-item\" href=\"#\">Send message</a></li>\n";
	profile_tmp_stream << "                  <li><a class=\"dropdown-item\" href=\"#\">Send location</a></li>\n";
	profile_tmp_stream << "                  <li><a class=\"dropdown-item\" href=\"#\">Send SOS</a></li>\n";
	profile_tmp_stream << "                  <li><hr class=\"dropdown-divider\" /></li>\n";
	profile_tmp_stream << "                  <li><a class=\"dropdown-item\" href=\"login.html\">Log out</a></li>\n";
	profile_tmp_stream << "               </ul>\n";
	profile_tmp_stream << "            </div>\n";
	profile_tmp_stream << "         </div>\n";
	profile_tmp_stream << "      </nav>\n";
	profile_tmp_stream << "      <div class=\"container-fluid profile-container no-margin\">\n";
	profile_tmp_stream << "         <div class=\"profile-mobile\">\n";
	profile_tmp_stream << "            <div class=\"col-sm-12\">\n";
	profile_tmp_stream << "               <div class=\"profile-picture\">\n";
	profile_tmp_stream << "                  <img src=\"images/demos/men/man1.jpg\" alt=\"\" />\n";
	profile_tmp_stream << "               </div>\n";
	profile_tmp_stream << "               <div class=\"profile-info\">\n";
	profile_tmp_stream << "                  <div class=\"center\">\n";
	profile_tmp_stream << "                     <div class=\"text-large\">Mike Johnson</div>\n";
	profile_tmp_stream << "                     <div class=\"text-small\">#LivingInPeru, welcome to my profile! 👌</div>\n";
	profile_tmp_stream << "                     <hr />\n";
	profile_tmp_stream << "                     <div class=\"text-medium\">Contact information:</div>\n";
	profile_tmp_stream << "                     <div class=\"text-small\">\n";
	profile_tmp_stream << "                        Phone: <a href=\"tel:+44(0)7700 900799\">+44(0)7700 900799</a>\n";
	profile_tmp_stream << "                     </div>\n";
	profile_tmp_stream << "                     <div class=\"text-small\">\n";
	profile_tmp_stream << "                        Email: <a href=\"mailto:fake@fake.com\">Mike.Johnson@gmail.com</a>\n";
	profile_tmp_stream << "                     </div>\n";
	profile_tmp_stream << "                     <hr />\n";
	profile_tmp_stream << "                     <div class=\"text-medium\">Last seen location:</div>\n";
	profile_tmp_stream << "                     <div class=\"map\">\n";
	profile_tmp_stream << "                        <iframe\n";
	profile_tmp_stream << "                           src=\"https://maps.google.com/maps?width=100%25&amp;height=600&amp;hl=en&amp;q=-4.452793,-81.2777126+()&amp;t=h&amp;z=14&amp;ie=UTF8&amp;iwloc=B&amp;output=embed\"\n";
	profile_tmp_stream << "                        ></iframe>\n";
	profile_tmp_stream << "                     </div>\n";
	profile_tmp_stream << "                  </div>\n";
	profile_tmp_stream << "               </div>\n";
	profile_tmp_stream << "            </div>\n";
	profile_tmp_stream << "         </div>\n";
	profile_tmp_stream << "         <div class=\"profile-desktop\">\n";
	profile_tmp_stream << "            <div class=\"row\">\n";
	profile_tmp_stream << "               <div class=\"col-lg-6\">\n";
	profile_tmp_stream << "                  <div class=\"profile-picture\">\n";
	profile_tmp_stream << "                     <img src=\"images/demos/men/man1.jpg\" alt=\"\" />\n";
	profile_tmp_stream << "                     <img class=\"overlay\" src=\"images/demos/men/man1.jpg\" alt=\"\" />\n";
	profile_tmp_stream << "                  </div>\n";
	profile_tmp_stream << "               </div>\n";
	profile_tmp_stream << "               <div class=\"col-lg-6\">\n";
	profile_tmp_stream << "                  <div class=\"profile-info\">\n";
	profile_tmp_stream << "                     <div class=\"center\">\n";
	profile_tmp_stream << "                        <div class=\"text-large\">Mike Johnson</div>\n";
	profile_tmp_stream << "                        <div class=\"text-small\">#LivingInPeru, welcome to my profile! 👌</div>\n";
	profile_tmp_stream << "                        <hr />\n";
	profile_tmp_stream << "                        <div class=\"text-medium\">Contact information:</div>\n";
	profile_tmp_stream << "                        <div class=\"text-small\">\n";
	profile_tmp_stream << "                           Phone: <a href=\"tel:+44(0)7700 900799\">+44(0)7700 900799</a>\n";
	profile_tmp_stream << "                        </div>\n";
	profile_tmp_stream << "                        <div class=\"text-small\">\n";
	profile_tmp_stream << "                           Email: <a href=\"mailto:fake@fake.com\">Mike.Johnson@gmail.com</a>\n";
	profile_tmp_stream << "                        </div>\n";
	profile_tmp_stream << "                        <hr />\n";
	profile_tmp_stream << "                        <div class=\"text-medium\">Last seen location:</div>\n";
	profile_tmp_stream << "                        <div class=\"map\" id=\"map\"></div>\n";
	profile_tmp_stream << "                     </div>\n";
	profile_tmp_stream << "                  </div>\n";
	profile_tmp_stream << "               </div>\n";
	profile_tmp_stream << "            </div>\n";
	profile_tmp_stream << "         </div>\n";
	profile_tmp_stream << "      </div>\n";
	profile_tmp_stream << "      <script src=\"js/bootstrap.min.js\"></script>\n";
	profile_tmp_stream << "      <script src=\"js/location.js\"></script>\n";
	profile_tmp_stream << "   </body>\n";
	profile_tmp_stream << "</html>\n";
if(layoutName.empty())
{
std::string ret{std::move(profile_tmp_stream.str())};
return ret;
}else
{
auto templ = DrTemplateBase::newTemplate(layoutName);
if(!templ) return "";
HttpViewData data = profile_view_data;
auto str = std::move(profile_tmp_stream.str());
if(!str.empty() && str[str.length()-1] == '\n') str.resize(str.length()-1);
data[""] = std::move(str);
return templ->genText(data);
}
}