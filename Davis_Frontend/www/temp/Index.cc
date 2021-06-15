//this file is generated by program(drogon_ctl) automatically,don't modify it!
#include "Index.h"
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
std::string Index::genText(const DrTemplateData& Index_view_data)
{
	drogon::OStringStream Index_tmp_stream;
	std::string layoutName{""};
	Index_tmp_stream << "<!DOCTYPE html>\n";
	Index_tmp_stream << "<html lang=\"en\">\n";
	Index_tmp_stream << "   <head>\n";
	Index_tmp_stream << "      <meta charset=\"UTF-8\" />\n";
	Index_tmp_stream << "      <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\" />\n";
	Index_tmp_stream << "      <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\" />\n";
	Index_tmp_stream << "      <title>Document</title>\n";
	Index_tmp_stream << "   </head>\n";
	Index_tmp_stream << "   <body>\n";
	Index_tmp_stream << "      <h1>Temporary index.html page</h1>\n";
	Index_tmp_stream << "      <h3>Navigation to made pages</h3>\n";
	Index_tmp_stream << "      <a href=\"contactOnly.html\">Contact Page only</a>\n";
	Index_tmp_stream << "      <br />\n";
	Index_tmp_stream << "      <a href=\"contactMessages.html\">Contact and message combo page</a>\n";
	Index_tmp_stream << "      <br />\n";
	Index_tmp_stream << "      <a href=\"messages.csp\">Message page only</a>\n";
	Index_tmp_stream << "      <br />\n";
	Index_tmp_stream << "      <a href=\"profile.csp\">Profile page only</a>\n";
	Index_tmp_stream << "      <br />\n";
	Index_tmp_stream << "      <a href=\"signup.csp\">Sign up page</a>\n";
	Index_tmp_stream << "      <br />\n";
	Index_tmp_stream << "      <a href=\"login.csp\">Login page</a>\n";
	Index_tmp_stream << "   </body>\n";
	Index_tmp_stream << "</html>\n";
if(layoutName.empty())
{
std::string ret{std::move(Index_tmp_stream.str())};
return ret;
}else
{
auto templ = DrTemplateBase::newTemplate(layoutName);
if(!templ) return "";
HttpViewData data = Index_view_data;
auto str = std::move(Index_tmp_stream.str());
if(!str.empty() && str[str.length()-1] == '\n') str.resize(str.length()-1);
data[""] = std::move(str);
return templ->genText(data);
}
}
