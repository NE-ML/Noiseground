#ifndef HTTPCLIENT_ROUTER_H
#define HTTPCLIENT_ROUTER_H

#include "userManager.h"
#include "soundManager.h"
#include "serverTypes.h"

class Router {
public:
    Router(UserManager *userManager, SoundManager *soundManager);
    Router() = default;
    virtual ~Router() = default;
    ResponseServer execute(RequestServer &request);
private:
    UserManager *userManager = new UserManager();
    SoundManager *soundManager = new SoundManager();

    const std::string userPath = "/user";
    const std::string soundPath = "/sound";
};


#endif //HTTPCLIENT_ROUTER_H
