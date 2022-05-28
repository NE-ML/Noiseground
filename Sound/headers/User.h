#ifndef NOISEGROUND_SOUND_USER_H
#define NOISEGROUND_SOUND_USER_H

#include <Sounds.h>

class User {
public:
    User(string login, int id);
    int getId() const;
    string getLogin() const;
    bool isEnable();
    void setLogin(string new_login);
    string idToLogin(int id);
    ~User() = default;

private:
    string login;
    int id;
    bool enabled;
    map<int, string> tracks;
};

#endif //NOISEGROUND_SOUND_USER_H
