#ifndef HTTPSERVER_HEADER_H
#define HTTPSERVER_HEADER_H

#include <string>

struct Header
{
    std::string name;
    std::string value;
};

#endif // HTTPSERVER_HEADER_H