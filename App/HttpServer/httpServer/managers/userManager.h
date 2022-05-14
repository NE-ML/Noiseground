#ifndef HTTPCLIENT_USERMANAGER_H
#define HTTPCLIENT_USERMANAGER_H

#include "user.h"

class UserManager {
public:
    UserManager() = default;
//    ResponseServer createUser(const Request &request);
    bool loginUser(std::string &login, std::string &password);
//    ResponseServer changeUser(const Request &request);
private:
//    UserModel* userModel = new UserModel();
    std::string dataName = "users.txt";
};

#endif //HTTPCLIENT_USERMANAGER_H
