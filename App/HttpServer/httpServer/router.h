#ifndef HTTPCLIENT_ROUTER_H
#define HTTPCLIENT_ROUTER_H

#include <string>
#include <boost/noncopyable.hpp>

#include "soundManager.h"
#include "userManager.h"
#include "reply.h"
#include "request.h"

class Router : private boost::noncopyable {
public:
    explicit Router(std::string doc_root);
    void handle_request(const Request& req, Reply& rep);
private:
    std::string doc_root_;
    SoundManager* soundManager = new SoundManager();
    UserManager* userManager = new UserManager();
    static bool url_decode(const std::string& in, std::string& out);
    static std::string get_header(const std::string& path, const std::string& name);
};


#endif //HTTPCLIENT_ROUTER_H
