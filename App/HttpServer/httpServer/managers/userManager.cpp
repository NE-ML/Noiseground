#include "userManager.h"

#include <fstream>

bool UserManager::loginUser(std::string &login, std::string &password) {
    std::ifstream f("../data/" + dataName);
    std::string log, pass;
    while (f >> log >> pass) {
        if (log == login && pass == password) {
            f.close();
            return true;
        }
    }
    f.close();
    return false;
}