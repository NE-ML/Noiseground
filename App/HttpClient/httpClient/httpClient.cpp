#include <iostream>
#include <boost/lexical_cast.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/system/error_code.hpp>
#include <utility>

#include "httpClient.h"

using Error = boost::system::system_error;

std::string HttpClient::createURL(const std::string& target, Params* params) {
    if (!params) return target;
    std::string url = target + "?";
    for (const auto& item: *params) {
        url += item.first + "=" + item.second + "&";
    }
    url.pop_back();
    std::cout << url << std::endl;
    return url;
}

bool HttpClient::connect(unsigned short port = 80) {
    auto const results =
            resolver.resolve(HttpClient::ip, std::to_string(port));
    try {
        boost::asio::connect(socket, results.begin(), results.end());
        return true;
    } catch (const boost::wrapexcept<Error>& error) {
        std::cout << error.what() << std::endl;
        return false;
    }
}

HttpClient::HttpClient() : socket(context), resolver(context) {}

ResponseStruct HttpClient::parseResponse(Response response) {
    ResponseStruct res = ResponseStruct();
    res.status = response.result_int();
    std::string tmp;
    for (auto seq : response.body().data()) {
        const char* cbuf = boost::asio::buffer_cast<const char*>(seq);
        tmp.append(cbuf, boost::asio::buffer_size(seq));
    }
    res.body = tmp;
    return res;
}

ResponseStruct HttpClient::makeGetRequest(const Host &host, const std::string &target,
                                          Params *params, Params *headers) {
    HttpClient::ip = host.ip;

    bool connected = connect(host.port);
    if (!connected) {
        return {};
    }
    std::string url = target;
    if (params && !params->empty()) {
        url = createURL(target, params);
    }

    const int version = 11;
    Request request{boost::beast::http::verb::get, url, version};
    request.set(boost::beast::http::field::host, HttpClient::ip);
    request.set(boost::beast::http::field::user_agent, BOOST_BEAST_VERSION_STRING);

    if (headers && !headers->empty()) {
        for (const auto& iter: *headers) {
            request.set(iter.first, iter.second);
        }
    }
    boost::beast::http::write(socket, request);

    Response result;
    boost::beast::http::read(socket, flat_buffer, result);
    boost::system::error_code ec;
    socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both, ec);
    if (ec && ec != boost::system::errc::not_connected)
        std::cout << "Connection error" << std::endl;
    return parseResponse(result);
}
