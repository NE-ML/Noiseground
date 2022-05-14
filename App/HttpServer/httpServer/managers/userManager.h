#ifndef HTTPCLIENT_USERMANAGER_H
#define HTTPCLIENT_USERMANAGER_H

#include "user.h"
#include "reply.h"
#include "request.h"
#include "userModel.h"
#include "serializer.h"

class UserManager {
public:
    UserManager() = default;
    void createUser(const Request &req, Reply& rep);
    void loginUser(const std::string &request_path, Reply& rep);
//    ResponseServer changeUser(const Request &request);
    ~UserManager() {
        delete serializer;
        delete userModel;
    }
private:
    UserModel* userModel = new UserModel();
    Serializer* serializer = new Serializer();
    static std::string get_param(const std::string& path, const std::string& name);
};

#endif //HTTPCLIENT_USERMANAGER_H
