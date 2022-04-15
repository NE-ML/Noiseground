#ifndef HTTPCLIENT_SERVERTYPES_H
#define HTTPCLIENT_SERVERTYPES_H

#include <boost/beast.hpp>
#include <map>

struct UserModel {};
struct SoundModel {};

using namespace boost::beast;

typedef http::response<http::string_body> ResponseServer;
typedef http::request<http::string_body> RequestServer;

#endif //HTTPCLIENT_SERVERTYPES_H
