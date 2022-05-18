#ifndef APP_HTTPSERVER_HTTPSERVER_HTTPSERVER_H_
#define APP_HTTPSERVER_HTTPSERVER_HTTPSERVER_H_

#include <string>
#include <vector>
#include <boost/asio.hpp>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>

#include "httpConnection.h"
#include "router.h"

class HttpServer : private boost::noncopyable {
 public:
    HttpServer(const std::string& address, const std::string& port,
               const std::string& doc_root, std::size_t thread_pool_size);
    void run();
 private:
    void start_accept();
    void handle_accept(const boost::system::error_code& e);
    void handle_stop();

    std::size_t thread_pool_size_;
    boost::asio::io_service io_service_;
    boost::asio::signal_set signals_;
    boost::asio::ip::tcp::acceptor acceptor_;
    HttpConnection_ptr connection_;
    Router router_;
};


#endif  // APP_HTTPSERVER_HTTPSERVER_HTTPSERVER_H_
