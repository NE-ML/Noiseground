#ifndef NOISEGROUND_USERMODEL_H
#define NOISEGROUND_USERMODEL_H

#include "user.h"
#include <vector>

class UserModel {
public:
    std::vector<User> FindUserWithLogin(const std::string& login);
    void addUser(const User& new_user);
private:
    std::string dataName = "users.txt";
};


#endif //NOISEGROUND_USERMODEL_H
