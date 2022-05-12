#include "httpServer.h"

#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <vector>

HttpServer::HttpServer(const std::string& address, const std::string& port,
               const std::string& doc_root, std::size_t thread_pool_size)
        : thread_pool_size_(thread_pool_size),
          signals_(io_service_),
          acceptor_(io_service_),
          connection_(),
          router_(doc_root)
{
    signals_.add(SIGINT);
    signals_.add(SIGTERM);
#if defined(SIGQUIT)
    signals_.add(SIGQUIT);
#endif // defined(SIGQUIT)
    signals_.async_wait(boost::bind(&HttpServer::handle_stop, this));

    // Open the acceptor with the option to reuse the address (i.e. SO_REUSEADDR).
    boost::asio::ip::tcp::resolver resolver(io_service_);
    boost::asio::ip::tcp::resolver::query query(address, port);
    boost::asio::ip::tcp::endpoint endpoint = *resolver.resolve(query);
    acceptor_.open(endpoint.protocol());
    acceptor_.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));
    acceptor_.bind(endpoint);
    acceptor_.listen();

    start_accept();
}

void HttpServer::run()
{
    std::vector<boost::shared_ptr<boost::thread> > threads;
    for (std::size_t i = 0; i < thread_pool_size_; ++i)
    {
        boost::shared_ptr<boost::thread> thread(new boost::thread(
                boost::bind(&boost::asio::io_service::run, &io_service_)));
        threads.push_back(thread);
    }

    for (auto & thread : threads)
        thread->join();
}

void HttpServer::start_accept()
{
    connection_.reset(new HttpConnection(io_service_, router_));
    acceptor_.async_accept(connection_->socket(),
                           boost::bind(&HttpServer::handle_accept, this,
                                       boost::asio::placeholders::error));
}

void HttpServer::handle_accept(const boost::system::error_code& e) {
    if (!e) {
        connection_->start();
    }
    start_accept();
}

void HttpServer::handle_stop() {
    io_service_.stop();
}