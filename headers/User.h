#ifndef NOISEGROUND_SOUND_USER_H
#define NOISEGROUND_SOUND_USER_H

#include <Sound.h>

class User {
public:
    User(string login, int id);
    int getId();
    string getLogin();
    bool isEnable();
    void setLogin(string new_login);
    string idToLogin(int id);
    ~User() = default;

private:
    string login;
    int id;
    bool enabled;
};

#endif //NOISEGROUND_SOUND_USER_H
