#include "userModel.h"

#include <fstream>

std::vector<User> UserModel::FindUserWithLogin(const std::string& login) {
    std::ifstream f("../data/" + dataName);
    std::string log, pass;
    std::vector<User> res;
    while (f >> log >> pass) {
        if (log == login) {
            f.close();
            User tmp;
            tmp.login = log;
            tmp.password = pass;
            res.push_back(tmp);
        }
    }
    f.close();
    return res;
}

void UserModel::addUser(const User& new_user) {
    std::ofstream f;
    f.open("../data/" + dataName, std::ios_base::out | std::ios_base::app);
    f << "\n" << new_user.login << " " << new_user.password;
    f.close();
}
