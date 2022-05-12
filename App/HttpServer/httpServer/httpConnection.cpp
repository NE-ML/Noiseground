#include "httpConnection.h"

#include <boost/bind.hpp>

HttpConnection::HttpConnection(boost::asio::io_service& io_service,
                       Router& handler)
        : strand_(io_service),
          socket_(io_service),
          router_(handler) {}

boost::asio::ip::tcp::socket& HttpConnection::socket() {
    return socket_;
}

void HttpConnection::start() {
    socket_.async_read_some(boost::asio::buffer(buffer_),
                            strand_.wrap(
                                    boost::bind(&HttpConnection::handle_read, shared_from_this(),
                                                boost::asio::placeholders::error,
                                                boost::asio::placeholders::bytes_transferred)));
}

void HttpConnection::handle_read(const boost::system::error_code& e,
                             std::size_t bytes_transferred) {
    if (!e) {
        boost::tribool result;
        boost::tie(result, boost::tuples::ignore) = parser_.parse(
                request_, buffer_.data(), buffer_.data() + bytes_transferred);

        if (result) {
            router_.handle_request(request_, reply_);
            boost::asio::async_write(socket_, reply_.to_buffers(),
                                     strand_.wrap(
                                             boost::bind(&HttpConnection::handle_write, shared_from_this(),
                                                         boost::asio::placeholders::error)));
        } else if (!result) {
            reply_ = Reply::stock_reply(Reply::bad_request);
            boost::asio::async_write(socket_, reply_.to_buffers(),
                                     strand_.wrap(
                                             boost::bind(&HttpConnection::handle_write, shared_from_this(),
                                                         boost::asio::placeholders::error)));
        } else {
            socket_.async_read_some(boost::asio::buffer(buffer_),
                                    strand_.wrap(
                                            boost::bind(&HttpConnection::handle_read, shared_from_this(),
                                                        boost::asio::placeholders::error,
                                                        boost::asio::placeholders::bytes_transferred)));
        }
    }
}

void HttpConnection::handle_write(const boost::system::error_code& e) {
    if (!e) {
        boost::system::error_code ignored_ec;
        socket_.shutdown(boost::asio::ip::tcp::socket::shutdown_both, ignored_ec);
    }
}