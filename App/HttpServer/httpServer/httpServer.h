#ifndef HTTPCLIENT_HTTPSERVER_H
#define HTTPCLIENT_HTTPSERVER_H

#include <boost/asio.hpp>

#include "router.h"

class HttpServer {
public:
    HttpServer(const std::string& address, int port);
    void run();
private:
    void accept();
    boost::asio::ip::tcp::endpoint endpoint;
    boost::asio::io_service io_service;
    boost::asio::ip::tcp::socket socket;
    boost::asio::ip::tcp::acceptor acceptor;

    UserManager* user_manager;
    SoundManager* sound_manager;

    Router router;
};


#endif //HTTPCLIENT_HTTPSERVER_H
