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
        if (request_path == "/sounds/standard") {
            rep.status = Reply::ok;
            rep.content = SoundManager().getStdSounds();
            rep.headers.resize(1);
            rep.headers[0].name = "Content-Length";
            rep.headers[0].value = boost::lexical_cast<std::string>(rep.content.size());
        }
    }
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