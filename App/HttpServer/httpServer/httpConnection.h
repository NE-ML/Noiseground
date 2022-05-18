#ifndef APP_HTTPSERVER_HTTPSERVER_HTTPCONNECTION_H_
#define APP_HTTPSERVER_HTTPSERVER_HTTPCONNECTION_H_


#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

#include "reply.h"
#include "request.h"
#include "router.h"
#include "parser.h"

class HttpConnection :public boost::enable_shared_from_this<HttpConnection>,
                      private boost::noncopyable {
 public:
    explicit HttpConnection(boost::asio::io_service& io_service,
    Router& handler);
    boost::asio::ip::tcp::socket& socket();
    void start();
 protected:
    void handle_read(const boost::system::error_code& e,
                     std::size_t bytes_transferred);
    void handle_write(const boost::system::error_code& e);

    boost::asio::io_service::strand strand_;
    boost::asio::ip::tcp::socket socket_;
    Router& router_;
    boost::array<char, 100000> buffer_{};
    Request request_;
    Parser parser_;
    Reply reply_;
};

typedef boost::shared_ptr<HttpConnection> HttpConnection_ptr;

#endif  // APP_HTTPSERVER_HTTPSERVER_HTTPCONNECTION_H_
