#ifndef HTTPCLIENT_CLIENTTYPES_H
#define HTTPCLIENT_CLIENTTYPES_H

#include <boost/beast.hpp>
#include <map>
#include <utility>
#include <vector>

using Response = boost::beast::http::response<boost::beast::http::dynamic_body>;
using Request = boost::beast::http::request<boost::beast::http::string_body>;

using Params = std::map<std::string, std::string>;

struct Header {
    std::string name;
    std::string values;
};

struct ResponseStruct {
    unsigned int status;
    std::string body;
    std::vector<Header> headers;
};

struct Host {
    std::string domain;
    std::string ip;
    unsigned short port;
    Host(std::string domain, std::string ip, unsigned short port)
            : domain(std::move(domain)), ip(std::move(ip)), port(port) {}
};

#endif //HTTPCLIENT_CLIENTTYPES_H
