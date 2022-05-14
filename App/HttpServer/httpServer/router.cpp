#include "router.h"

#include <iostream>
#include <fstream>
#include <string>
#include <boost/lexical_cast.hpp>
#include <utility>

#include "mime_types.h"
#include "reply.h"

Router::Router(std::string doc_root)
        : doc_root_(std::move(doc_root)) {}

void Router::handle_request(const Request& req, Reply& rep) {
    std::string request_path;
    if (!url_decode(req.uri, request_path)) {
        rep = Reply::stock_reply(Reply::bad_request);
        return;
    }

    if (request_path.empty() || request_path[0] != '/' || request_path.find("..") != std::string::npos) {
        rep = Reply::stock_reply(Reply::bad_request);
        return;
    }

    if (req.method == "GET") {
        if (request_path == "/sound/standard") {
            rep.status = Reply::ok;
            rep.content = soundManager->getStdSounds();
            rep.headers.resize(1);
            rep.headers[0].name = "Content-Length";
            rep.headers[0].value = boost::lexical_cast<std::string>(rep.content.size());
        }
        if (request_path.find("/user/auth") != std::string::npos) {
            std::string passwd = get_header(request_path, "password");
            std::string login = get_header(request_path, "login");
            if (userManager->loginUser(login, passwd))
                rep.status = Reply::ok;
            else
                rep.status = Reply::forbidden;
        }
    }
}

std::string Router::get_header(const std::string& path, const std::string& name) {
    std::size_t pos = path.find(name, 0);
    std::size_t pos_equal = path.find('=', pos);
    std::size_t pos_and = path.find('&', pos_equal);
    if (pos_and == std::string::npos) {
        pos_and = path.size();
    }
    return path.substr(pos_equal + 1, pos_and - pos_equal - 1);
}

bool Router::url_decode(const std::string& in, std::string& out) {
    out.clear();
    out.reserve(in.size());
    for (std::size_t i = 0; i < in.size(); ++i) {
        if (in[i] == '%') {
            if (i + 3 <= in.size()) {
                int value = 0;
                std::istringstream is(in.substr(i + 1, 2));
                if (is >> std::hex >> value) {
                    out += static_cast<char>(value);
                    i += 2;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        } else if (in[i] == '+') {
            out += ' ';
        } else {
            out += in[i];
        }
    }
    return true;
}