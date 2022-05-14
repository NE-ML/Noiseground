#include "userManager.h"

void UserManager::loginUser(const std::string &request_path, Reply& rep) {
    std::string passwd = get_header(request_path, "password");
    std::string login = get_header(request_path, "login");
    std::vector<User> res = userModel->FindUserWithLogin(login);
    for (auto& i : res) {
        if (i.password == passwd) {
            rep.status = Reply::ok;
            return;
        }
    }
    rep.status = Reply::forbidden;
};

std::string UserManager::get_header(const std::string& path, const std::string& name) {
    std::size_t pos = path.find(name, 0);
    std::size_t pos_equal = path.find('=', pos);
    std::size_t pos_and = path.find('&', pos_equal);
    if (pos_and == std::string::npos) {
        pos_and = path.size();
    }
    return path.substr(pos_equal + 1, pos_and - pos_equal - 1);
}