#ifndef HTTPCLIENT_USERMANAGER_H
#define HTTPCLIENT_USERMANAGER_H

#include "user.h"
#include "userModel.h"
#include "reply.h"

class UserManager {
public:
    UserManager() = default;
//    ResponseServer createUser(const Request &request);
    void loginUser(const std::string &request_path, Reply& rep);
//    ResponseServer changeUser(const Request &request);
    ~UserManager() {
//        delete serializer;
        delete userModel;
    }
private:
    UserModel* userModel = new UserModel();
    static std::string get_header(const std::string& path, const std::string& name);
};

#endif //HTTPCLIENT_USERMANAGER_H
