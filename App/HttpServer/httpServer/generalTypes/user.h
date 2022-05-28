#ifndef APP_HTTPSERVER_HTTPSERVER_GENERALTYPES_USER_H_
#define APP_HTTPSERVER_HTTPSERVER_GENERALTYPES_USER_H_

#include <string>

struct User {
    std::string login;
    std::string password;
};

#endif  // APP_HTTPSERVER_HTTPSERVER_GENERALTYPES_USER_H_
