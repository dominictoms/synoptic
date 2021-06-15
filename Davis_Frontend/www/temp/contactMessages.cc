//this file is generated by program(drogon_ctl) automatically,don't modify it!
#include "contactMessages.h"
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
std::string contactMessages::genText(const DrTemplateData& contactMessages_view_data)
{
	drogon::OStringStream contactMessages_tmp_stream;
	std::string layoutName{""};
	contactMessages_tmp_stream << "<!DOCTYPE html>\n";
	contactMessages_tmp_stream << "<!--\n";
	contactMessages_tmp_stream << "    Licensed to the Apache Software Foundation (ASF) under one\n";
	contactMessages_tmp_stream << "    or more contributor license agreements.  See the NOTICE file\n";
	contactMessages_tmp_stream << "    distributed with this work for additional information\n";
	contactMessages_tmp_stream << "    regarding copyright ownership.  The ASF licenses this file\n";
	contactMessages_tmp_stream << "    to you under the Apache License, Version 2.0 (the\n";
	contactMessages_tmp_stream << "    \"License\"); you may not use this file except in compliance\n";
	contactMessages_tmp_stream << "    with the License.  You may obtain a copy of the License at\n";
contactMessages_tmp_stream<<"\n";
	contactMessages_tmp_stream << "    http://www.apache.org/licenses/LICENSE-2.0\n";
contactMessages_tmp_stream<<"\n";
	contactMessages_tmp_stream << "    Unless required by applicable law or agreed to in writing,\n";
	contactMessages_tmp_stream << "    software distributed under the License is distributed on an\n";
	contactMessages_tmp_stream << "    \"AS IS\" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY\n";
	contactMessages_tmp_stream << "     KIND, either express or implied.  See the License for the\n";
	contactMessages_tmp_stream << "    specific language governing permissions and limitations\n";
	contactMessages_tmp_stream << "    under the License.\n";
	contactMessages_tmp_stream << "-->\n";
	contactMessages_tmp_stream << "<html>\n";
	contactMessages_tmp_stream << "   <head>\n";
	contactMessages_tmp_stream << "      <meta charset=\"utf-8\" />\n";
	contactMessages_tmp_stream << "      <!--\n";
	contactMessages_tmp_stream << "        Customize this policy to fit your own app's needs. For more guidance, see:\n";
	contactMessages_tmp_stream << "            https://github.com/apache/cordova-plugin-whitelist/blob/master/README.md#content-security-policy\n";
	contactMessages_tmp_stream << "        Some notes:\n";
	contactMessages_tmp_stream << "            * gap: is required only on iOS (when using UIWebView) and is needed for JS->native communication\n";
	contactMessages_tmp_stream << "            * https://ssl.gstatic.com is required only on Android and is needed for TalkBack to function properly\n";
	contactMessages_tmp_stream << "            * Disables use of inline scripts in order to mitigate risk of XSS vulnerabilities. To change this:\n";
	contactMessages_tmp_stream << "                * Enable inline JS: add 'unsafe-inline' to default-src\n";
	contactMessages_tmp_stream << "        -->\n";
	contactMessages_tmp_stream << "      <meta name=\"format-detection\" content=\"telephone=no\" />\n";
	contactMessages_tmp_stream << "      <meta name=\"msapplication-tap-highlight\" content=\"no\" />\n";
	contactMessages_tmp_stream << "      <meta name=\"viewport\" content=\"initial-scale=1, width=device-width, viewport-fit=cover\" />\n";
	contactMessages_tmp_stream << "      <meta name=\"color-scheme\" content=\"light dark\" />\n";
	contactMessages_tmp_stream << "      <title>Davis | Chat</title>\n";
	contactMessages_tmp_stream << "      <link rel=\"stylesheet\" href=\"css/bootstrap.min.css\" />\n";
	contactMessages_tmp_stream << "      <link rel=\"stylesheet\" href=\"css/contactMessages.css\" />\n";
	contactMessages_tmp_stream << "   </head>\n";
	contactMessages_tmp_stream << "   <body>\n";
	contactMessages_tmp_stream << "      <div class=\"container-fluid contact-panel\">\n";
	contactMessages_tmp_stream << "         <!--To contain contact code only-->\n";
	contactMessages_tmp_stream << "         <nav class=\"navbar navbar-dark nav-colour static-top\">\n";
	contactMessages_tmp_stream << "            <div class=\"container-fluid\">\n";
	contactMessages_tmp_stream << "               <span class=\"navbar-brand mb-0 h1\">Davis</span>\n";
	contactMessages_tmp_stream << "               <span class=\"navbar-brand mb-0 h1\">Contacts</span>\n";
	contactMessages_tmp_stream << "               <div class=\"dropdown\">\n";
	contactMessages_tmp_stream << "                  <button\n";
	contactMessages_tmp_stream << "                     class=\"btn btn-secondary transparent\"\n";
	contactMessages_tmp_stream << "                     type=\"button\"\n";
	contactMessages_tmp_stream << "                     id=\"dropdownMenuButton2\"\n";
	contactMessages_tmp_stream << "                     data-bs-toggle=\"dropdown\"\n";
	contactMessages_tmp_stream << "                     aria-expanded=\"false\"\n";
	contactMessages_tmp_stream << "                  >\n";
	contactMessages_tmp_stream << "                     <img class=\"icon dropdown-icon\" src=\"images/menu.svg\" alt=\"Send\" />\n";
	contactMessages_tmp_stream << "                  </button>\n";
	contactMessages_tmp_stream << "                  <ul\n";
	contactMessages_tmp_stream << "                     class=\"dropdown-menu dropdown-menu-dark dropdown-menu-right\"\n";
	contactMessages_tmp_stream << "                     aria-labelledby=\"dropdownMenuButton2\"\n";
	contactMessages_tmp_stream << "                  >\n";
	contactMessages_tmp_stream << "                     <li><a class=\"dropdown-item\" href=\"#\">Add contact</a></li>\n";
	contactMessages_tmp_stream << "                     <li><a class=\"dropdown-item\" href=\"#\">Send message</a></li>\n";
	contactMessages_tmp_stream << "                     <li><hr class=\"dropdown-divider\" /></li>\n";
	contactMessages_tmp_stream << "                     <li><a class=\"dropdown-item\" href=\"login.html\">Log out</a></li>\n";
	contactMessages_tmp_stream << "                  </ul>\n";
	contactMessages_tmp_stream << "               </div>\n";
	contactMessages_tmp_stream << "            </div>\n";
	contactMessages_tmp_stream << "         </nav>\n";
	contactMessages_tmp_stream << "         <div class=\"container-fluid contact-container\" id=\"contact-panel\">\n";
	contactMessages_tmp_stream << "            <div class=\"row contact-row flex-nowrap\">\n";
	contactMessages_tmp_stream << "               <a href=\"profile.html\">\n";
	contactMessages_tmp_stream << "                  <div class=\"col-3 contact-left\">\n";
	contactMessages_tmp_stream << "                     <img src=\"images/demos/men/man1.jpg\" alt=\"\" />\n";
	contactMessages_tmp_stream << "                  </div>\n";
	contactMessages_tmp_stream << "               </a>\n";
	contactMessages_tmp_stream << "               <a class=\"contact\">\n";
	contactMessages_tmp_stream << "                  <div class=\"col-9 contact-right\">\n";
	contactMessages_tmp_stream << "                     <div class=\"contact-name\">Mike Johnson</div>\n";
	contactMessages_tmp_stream << "                     <div class=\"contact-message\">\n";
	contactMessages_tmp_stream << "                        Hiya mate, just seeing how that meeting went...\n";
	contactMessages_tmp_stream << "                     </div>\n";
	contactMessages_tmp_stream << "                  </div>\n";
	contactMessages_tmp_stream << "               </a>\n";
	contactMessages_tmp_stream << "            </div>\n";
	contactMessages_tmp_stream << "            <div class=\"row contact-row flex-nowrap\">\n";
	contactMessages_tmp_stream << "               <a href=\"profile.html\">\n";
	contactMessages_tmp_stream << "                  <div class=\"col-3 contact-left\">\n";
	contactMessages_tmp_stream << "                     <img src=\"images/demos/women/woman1.jpg\" alt=\"\" />\n";
	contactMessages_tmp_stream << "                  </div>\n";
	contactMessages_tmp_stream << "               </a>\n";
	contactMessages_tmp_stream << "               <a class=\"contact\">\n";
	contactMessages_tmp_stream << "                  <div class=\"col-9 contact-right\">\n";
	contactMessages_tmp_stream << "                     <div class=\"contact-name\">Ava Leday</div>\n";
	contactMessages_tmp_stream << "                     <div class=\"contact-message\">\n";
	contactMessages_tmp_stream << "                        Did you get the package I sent the other day?\n";
	contactMessages_tmp_stream << "                     </div>\n";
	contactMessages_tmp_stream << "                  </div>\n";
	contactMessages_tmp_stream << "               </a>\n";
	contactMessages_tmp_stream << "            </div>\n";
	contactMessages_tmp_stream << "            <div class=\"row contact-row flex-nowrap\">\n";
	contactMessages_tmp_stream << "               <a href=\"profile.html\">\n";
	contactMessages_tmp_stream << "                  <div class=\"col-3 contact-left\">\n";
	contactMessages_tmp_stream << "                     <img src=\"images/demos/men/man2.jpg\" alt=\"\" />\n";
	contactMessages_tmp_stream << "                  </div>\n";
	contactMessages_tmp_stream << "               </a>\n";
	contactMessages_tmp_stream << "               <a href=\"messages.html\">\n";
	contactMessages_tmp_stream << "                  <div class=\"col-9 contact-right\">\n";
	contactMessages_tmp_stream << "                     <div class=\"contact-name\">Tom McAllister</div>\n";
	contactMessages_tmp_stream << "                     <div class=\"contact-message\">Go to the discord vc, big news!!!</div>\n";
	contactMessages_tmp_stream << "                  </div>\n";
	contactMessages_tmp_stream << "               </a>\n";
	contactMessages_tmp_stream << "            </div>\n";
	contactMessages_tmp_stream << "            <div class=\"row contact-row flex-nowrap\">\n";
	contactMessages_tmp_stream << "               <a href=\"profile.html\">\n";
	contactMessages_tmp_stream << "                  <div class=\"col-3 contact-left\">\n";
	contactMessages_tmp_stream << "                     <img src=\"images/demos/women/woman2.jpg\" alt=\"\" />\n";
	contactMessages_tmp_stream << "                  </div>\n";
	contactMessages_tmp_stream << "               </a>\n";
	contactMessages_tmp_stream << "               <a href=\"messages.html\">\n";
	contactMessages_tmp_stream << "                  <div class=\"col-9 contact-right\">\n";
	contactMessages_tmp_stream << "                     <div class=\"contact-name\">Tracey Amar</div>\n";
	contactMessages_tmp_stream << "                     <div class=\"contact-message\">\n";
	contactMessages_tmp_stream << "                        Make sure you get the work done before Thursday\n";
	contactMessages_tmp_stream << "                     </div>\n";
	contactMessages_tmp_stream << "                  </div>\n";
	contactMessages_tmp_stream << "               </a>\n";
	contactMessages_tmp_stream << "            </div>\n";
	contactMessages_tmp_stream << "            <div class=\"row contact-row flex-nowrap\">\n";
	contactMessages_tmp_stream << "               <a href=\"profile.html\">\n";
	contactMessages_tmp_stream << "                  <div class=\"col-3 contact-left\">\n";
	contactMessages_tmp_stream << "                     <img src=\"images/demos/men/man3.jpg\" alt=\"\" />\n";
	contactMessages_tmp_stream << "                  </div>\n";
	contactMessages_tmp_stream << "               </a>\n";
	contactMessages_tmp_stream << "               <a href=\"messages.html\">\n";
	contactMessages_tmp_stream << "                  <div class=\"col-9 contact-right\">\n";
	contactMessages_tmp_stream << "                     <div class=\"contact-name\">Bruce Oneal</div>\n";
	contactMessages_tmp_stream << "                     <div class=\"contact-message\">Go to the discord vc, big news!!!</div>\n";
	contactMessages_tmp_stream << "                  </div>\n";
	contactMessages_tmp_stream << "               </a>\n";
	contactMessages_tmp_stream << "            </div>\n";
	contactMessages_tmp_stream << "            <div class=\"row contact-row flex-nowrap\">\n";
	contactMessages_tmp_stream << "               <a href=\"profile.html\">\n";
	contactMessages_tmp_stream << "                  <div class=\"col-3 contact-left\">\n";
	contactMessages_tmp_stream << "                     <img src=\"images/demos/women/woman3.jpg\" alt=\"\" />\n";
	contactMessages_tmp_stream << "                  </div>\n";
	contactMessages_tmp_stream << "               </a>\n";
	contactMessages_tmp_stream << "               <a href=\"messages.html\">\n";
	contactMessages_tmp_stream << "                  <div class=\"col-9 contact-right\">\n";
	contactMessages_tmp_stream << "                     <div class=\"contact-name\">Vanessa Clark</div>\n";
	contactMessages_tmp_stream << "                     <div class=\"contact-message\">\n";
	contactMessages_tmp_stream << "                        Did you see that ludicrous display last night?\n";
	contactMessages_tmp_stream << "                     </div>\n";
	contactMessages_tmp_stream << "                  </div>\n";
	contactMessages_tmp_stream << "               </a>\n";
	contactMessages_tmp_stream << "            </div>\n";
	contactMessages_tmp_stream << "            <div class=\"row contact-row flex-nowrap\">\n";
	contactMessages_tmp_stream << "               <a href=\"profile.html\">\n";
	contactMessages_tmp_stream << "                  <div class=\"col-3 contact-left\">\n";
	contactMessages_tmp_stream << "                     <img src=\"images/demos/men/man4.jpg\" alt=\"\" />\n";
	contactMessages_tmp_stream << "                  </div>\n";
	contactMessages_tmp_stream << "               </a>\n";
	contactMessages_tmp_stream << "               <a href=\"messages.html\">\n";
	contactMessages_tmp_stream << "                  <div class=\"col-9 contact-right\">\n";
	contactMessages_tmp_stream << "                     <div class=\"contact-name\">Jon Wells</div>\n";
	contactMessages_tmp_stream << "                     <div class=\"contact-message\">Try turning it off and on again</div>\n";
	contactMessages_tmp_stream << "                  </div>\n";
	contactMessages_tmp_stream << "               </a>\n";
	contactMessages_tmp_stream << "            </div>\n";
	contactMessages_tmp_stream << "            <div class=\"row contact-row flex-nowrap\">\n";
	contactMessages_tmp_stream << "               <a href=\"profile.html\">\n";
	contactMessages_tmp_stream << "                  <div class=\"col-3 contact-left\">\n";
	contactMessages_tmp_stream << "                     <img src=\"images/demos/women/woman4.jpg\" alt=\"\" />\n";
	contactMessages_tmp_stream << "                  </div>\n";
	contactMessages_tmp_stream << "               </a>\n";
	contactMessages_tmp_stream << "               <a href=\"messages.html\">\n";
	contactMessages_tmp_stream << "                  <div class=\"col-9 contact-right\">\n";
	contactMessages_tmp_stream << "                     <div class=\"contact-name\">Jessica Miles</div>\n";
	contactMessages_tmp_stream << "                     <div class=\"contact-message\">\n";
	contactMessages_tmp_stream << "                        I'm calling in sick tomorrow, don't want to do the work\n";
	contactMessages_tmp_stream << "                     </div>\n";
	contactMessages_tmp_stream << "                  </div>\n";
	contactMessages_tmp_stream << "               </a>\n";
	contactMessages_tmp_stream << "            </div>\n";
	contactMessages_tmp_stream << "            <div class=\"row contact-row flex-nowrap\">\n";
	contactMessages_tmp_stream << "               <a href=\"profile.html\">\n";
	contactMessages_tmp_stream << "                  <div class=\"col-3 contact-left\">\n";
	contactMessages_tmp_stream << "                     <img src=\"images/demos/men/man4.jpg\" alt=\"\" />\n";
	contactMessages_tmp_stream << "                  </div>\n";
	contactMessages_tmp_stream << "               </a>\n";
	contactMessages_tmp_stream << "               <a href=\"messages.html\">\n";
	contactMessages_tmp_stream << "                  <div class=\"col-9 contact-right\">\n";
	contactMessages_tmp_stream << "                     <div class=\"contact-name\">Simon Miles</div>\n";
	contactMessages_tmp_stream << "                     <div class=\"contact-message\">I think your mam is on TV!! Channel 4!!</div>\n";
	contactMessages_tmp_stream << "                  </div>\n";
	contactMessages_tmp_stream << "               </a>\n";
	contactMessages_tmp_stream << "            </div>\n";
	contactMessages_tmp_stream << "         </div>\n";
	contactMessages_tmp_stream << "      </div>\n";
	contactMessages_tmp_stream << "      <div class=\"container-fluid message-panel\" id=\"message-panel\">\n";
	contactMessages_tmp_stream << "         <nav class=\"navbar navbar-expand-lg navbar-dark nav-colour\">\n";
	contactMessages_tmp_stream << "            <div class=\"container-fluid\">\n";
	contactMessages_tmp_stream << "               <span class=\"navbar-brand mb-0 h1\"><a id=\"back\" href=\"contactMessages.html\"><-</a></span>\n";
	contactMessages_tmp_stream << "               <span class=\"navbar-brand mb-0 h1\" id=\"header-contact-name\"></span>\n";
	contactMessages_tmp_stream << "               <div class=\"dropdown\">\n";
	contactMessages_tmp_stream << "                  <button\n";
	contactMessages_tmp_stream << "                     class=\"btn btn-secondary transparent\"\n";
	contactMessages_tmp_stream << "                     type=\"button\"\n";
	contactMessages_tmp_stream << "                     id=\"dropdownMenuButton2\"\n";
	contactMessages_tmp_stream << "                     data-bs-toggle=\"dropdown\"\n";
	contactMessages_tmp_stream << "                     aria-expanded=\"false\"\n";
	contactMessages_tmp_stream << "                  >\n";
	contactMessages_tmp_stream << "                     <img class=\"icon dropdown-icon\" src=\"images/menu.svg\" alt=\"Send\" />\n";
	contactMessages_tmp_stream << "                  </button>\n";
	contactMessages_tmp_stream << "                  <ul\n";
	contactMessages_tmp_stream << "                     class=\"dropdown-menu dropdown-menu-dark dropdown-menu-right\"\n";
	contactMessages_tmp_stream << "                     aria-labelledby=\"dropdownMenuButton2\"\n";
	contactMessages_tmp_stream << "                  >\n";
	contactMessages_tmp_stream << "                     <li><a class=\"dropdown-item\" href=\"#\">View contact info</a></li>\n";
	contactMessages_tmp_stream << "                     <li><hr class=\"dropdown-divider\" /></li>\n";
	contactMessages_tmp_stream << "                     <li><a class=\"dropdown-item\" href=\"#\">Send location</a></li>\n";
	contactMessages_tmp_stream << "                     <li><a class=\"dropdown-item\" href=\"#\">Send SOS</a></li>\n";
	contactMessages_tmp_stream << "                     <li><a class=\"dropdown-item\" href=\"#\">Send prayers</a></li>\n";
	contactMessages_tmp_stream << "                  </ul>\n";
	contactMessages_tmp_stream << "               </div>\n";
	contactMessages_tmp_stream << "            </div>\n";
	contactMessages_tmp_stream << "         </nav>\n";
	contactMessages_tmp_stream << "         \n";
	contactMessages_tmp_stream << "         <div class=\"error-field\" id=\"error-field\"></div>\n";
	contactMessages_tmp_stream << "         <div class=\"chat container-fluid\" id=\"chat\">\n";
	contactMessages_tmp_stream << "         <div class=\"blank-panel\" id=\"blank-panel\">\n";
	contactMessages_tmp_stream << "            <div class=\"image\"><img src=\"images/background/emptyPanel.jpg\" alt=\"\"></div>\n";
	contactMessages_tmp_stream << "            <div class=\"text\">Click on a contact or add a new one to start messaging</div>\n";
	contactMessages_tmp_stream << "         </div>\n";
	contactMessages_tmp_stream << "            <div class=\"error\" id=\"error-box\">\n";
	contactMessages_tmp_stream << "               <span class=\"close-button\" id=\"error-close\">&#10005</span>\n";
	contactMessages_tmp_stream << "            </div>\n";
	contactMessages_tmp_stream << "         </div>\n";
	contactMessages_tmp_stream << "         <footer class=\"footer\">\n";
	contactMessages_tmp_stream << "            <div class=\"container-fluid\">\n";
	contactMessages_tmp_stream << "               <div class=\"row\">\n";
	contactMessages_tmp_stream << "                  <div class=\"col-12 no-margin\">\n";
	contactMessages_tmp_stream << "                     <div class=\"message-row\">\n";
	contactMessages_tmp_stream << "                        <input\n";
	contactMessages_tmp_stream << "                           type=\"text\"\n";
	contactMessages_tmp_stream << "                           class=\"form-control\"\n";
	contactMessages_tmp_stream << "                           name=\"message-input\"\n";
	contactMessages_tmp_stream << "                           id=\"message-input\"\n";
	contactMessages_tmp_stream << "                           placeholder=\"Your message here...\"\n";
	contactMessages_tmp_stream << "                        />\n";
	contactMessages_tmp_stream << "                        <button\n";
	contactMessages_tmp_stream << "                           type=\"submit\"\n";
	contactMessages_tmp_stream << "                           class=\"btn btn-primary submit-button transparent\"\n";
	contactMessages_tmp_stream << "                           id=\"submit\"\n";
	contactMessages_tmp_stream << "                        >\n";
	contactMessages_tmp_stream << "                           <img class=\"icon\" src=\"images/send.svg\" alt=\"Send\" />\n";
	contactMessages_tmp_stream << "                        </button>\n";
	contactMessages_tmp_stream << "                     </div>\n";
	contactMessages_tmp_stream << "                  </div>\n";
	contactMessages_tmp_stream << "               </div>\n";
	contactMessages_tmp_stream << "            </div>\n";
	contactMessages_tmp_stream << "         </footer>\n";
	contactMessages_tmp_stream << "      </div>\n";
	contactMessages_tmp_stream << "      <script src=\"js/bootstrap.min.js\"></script>\n";
	contactMessages_tmp_stream << "      <script src=\"js/message-board.js\"></script>\n";
	contactMessages_tmp_stream << "      <script src=\"js/validator.min.js\"></script>\n";
	contactMessages_tmp_stream << "      <script src=\"js/time.min.js\"></script>\n";
	contactMessages_tmp_stream << "      <script src=\"js/messages.js\"></script>\n";
	contactMessages_tmp_stream << "   </body>\n";
	contactMessages_tmp_stream << "</html>\n";
if(layoutName.empty())
{
std::string ret{std::move(contactMessages_tmp_stream.str())};
return ret;
}else
{
auto templ = DrTemplateBase::newTemplate(layoutName);
if(!templ) return "";
HttpViewData data = contactMessages_view_data;
auto str = std::move(contactMessages_tmp_stream.str());
if(!str.empty() && str[str.length()-1] == '\n') str.resize(str.length()-1);
data[""] = std::move(str);
return templ->genText(data);
}
}