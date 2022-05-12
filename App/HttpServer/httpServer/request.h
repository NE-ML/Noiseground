#ifndef HTTPCLIENT_SERVERTYPES_H
#define HTTPCLIENT_SERVERTYPES_H

#include <string>
#include <vector>

#include "header.h"

struct UserModel {};
struct SoundModel {};

struct Request
{
    std::string method;
    std::string uri;
    int http_version_major;
    int http_version_minor;
    std::vector<Header> headers;
};

#endif //HTTPCLIENT_SERVERTYPES_H
