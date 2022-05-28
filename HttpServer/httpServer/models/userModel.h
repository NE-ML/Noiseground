#ifndef APP_HTTPSERVER_HTTPSERVER_MODELS_USERMODEL_H_
#define APP_HTTPSERVER_HTTPSERVER_MODELS_USERMODEL_H_

#include <vector>
#include <string>

#include "user.h"

class UserModel {
 public:
    std::vector<User> FindUserWithLogin(const std::string& login);
    void addUser(const User& new_user);
 private:
    std::string dataName = "users.txt";
};


#endif  // APP_HTTPSERVER_HTTPSERVER_MODELS_USERMODEL_H_
