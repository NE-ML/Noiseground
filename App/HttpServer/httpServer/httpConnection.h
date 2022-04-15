#ifndef HTTPCLIENT_HTTPCONNECTION_H
#define HTTPCLIENT_HTTPCONNECTION_H

#include <boost/asio.hpp>
#include <boost/beast.hpp>

#include "router.h"
#include "serverTypes.h"

class HttpConnection : public boost::enable_shared_from_this<HttpConnection>{
public:
    HttpConnection(boost::asio::ip::tcp::socket socket, Router* router);
    ~HttpConnection() = default;
    void start();
protected:
    void doRead();
    void onRead();
    void doWrite();

    boost::beast::flat_buffer buffer;
    RequestServer request;
    ResponseServer response;
    boost::asio::ip::tcp::socket socket;
    Router* router;
};

#endif //HTTPCLIENT_HTTPCONNECTION_H
