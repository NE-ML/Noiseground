#ifndef APP_HTTPSERVER_HTTPSERVER_MANAGERS_USERMANAGER_H_
#define APP_HTTPSERVER_HTTPSERVER_MANAGERS_USERMANAGER_H_

#include <memory>
#include <string>

#include "user.h"
#include "reply.h"
#include "request.h"
#include "userModel.h"
#include "serializer.h"

class UserManager {
 public:
    UserManager();
    void createUser(const Request &req, Reply& rep);
    void loginUser(const std::string &request_path, Reply& rep);
 private:
    std::shared_ptr<UserModel> userModel;
    std::shared_ptr<Serializer> serializer;
    static std::string get_param(const std::string& path, const std::string& name);
};

#endif  // APP_HTTPSERVER_HTTPSERVER_MANAGERS_USERMANAGER_H_
