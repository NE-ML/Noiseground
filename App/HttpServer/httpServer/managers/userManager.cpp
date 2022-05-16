#include "userManager.h"

UserManager::UserManager()
        : userModel(std::make_shared<UserModel>()),
        serializer(std::make_shared<Serializer>()) {}

void UserManager::loginUser(const std::string &request_path, Reply& rep) {
    std::string passwd = get_param(request_path, "password");
    std::string login = get_param(request_path, "login");
    std::vector<User> res = userModel->FindUserWithLogin(login);
    if (!res.empty()) {
        rep.status = Reply::ok;
        return;
    }
    rep.status = Reply::forbidden;
};

void UserManager::createUser(const Request &req, Reply &rep) {
    auto body = std::find_if(req.headers.begin(), req.headers.end(),
                             [](const Header& i) {return i.name == "Body";});
    User new_user = serializer->deserialRegisterData(body->value);
    std::vector<User> res = userModel->FindUserWithLogin(new_user.login);
    if (res.empty()) {
        userModel->addUser(new_user);
        rep.status = Reply::ok;
        return;
    }
    rep.status = Reply::forbidden;
}

std::string UserManager::get_param(const std::string &path, const std::string &name) {
    std::size_t pos = path.find(name, 0);
    std::size_t pos_equal = path.find('=', pos);
    std::size_t pos_and = path.find('&', pos_equal);
    if (pos_and == std::string::npos) {
        pos_and = path.size();
    }
    return path.substr(pos_equal + 1, pos_and - pos_equal - 1);
}