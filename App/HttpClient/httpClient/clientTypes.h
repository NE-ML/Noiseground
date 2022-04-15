#ifndef HTTPCLIENT_CLIENTTYPES_H
#define HTTPCLIENT_CLIENTTYPES_H

#include <boost/beast.hpp>
#include <map>

using namespace boost::beast;

typedef http::response<http::dynamic_body> Response;
typedef http::request<http::string_body> Request;

typedef std::map<std::string, std::string> Params;

struct ResponseStruct {
    unsigned int status;
    std::string body;
};

struct Host {
    std::string domain;
    std::string ip;
    unsigned short port;
    Host(std::string domain, std::string ip, unsigned short port)
            : domain(std::move(domain)), ip(ip), port(port) {}
};

#endif //HTTPCLIENT_CLIENTTYPES_H
