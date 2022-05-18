#ifndef APP_HTTPSERVER_HTTPSERVER_ROUTER_H_
#define APP_HTTPSERVER_HTTPSERVER_ROUTER_H_

#include <string>
#include <memory>
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
    std::shared_ptr<SoundManager> soundManager;
    std::shared_ptr<UserManager> userManager;
    static bool url_decode(const std::string& in, std::string& out);
};


#endif  // APP_HTTPSERVER_HTTPSERVER_ROUTER_H_
