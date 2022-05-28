#include "httpClient.h"

#include <iostream>
#include <string>
#include <memory>
#include <utility>
#include <boost/lexical_cast.hpp>
#include <boost/system/error_code.hpp>

using Error = boost::system::system_error;

std::string HttpClient::createURL(const std::string& target, const std::shared_ptr<Params>& params) {
    if (!params)
        return target;
    std::string url = target + "?";
    for (const auto& item : *params) {
        url += item.first + "=" + item.second + "&";
    }
    url.pop_back();
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

ResponseStruct HttpClient::makeRequest(const Host &host, const std::string &target,
                                       const boost::beast::http::verb method,
                                       const std::shared_ptr<Params>& params,
                                       const std::shared_ptr<Params>& body,
                                       const std::shared_ptr<Params>& headers) {
    HttpClient::ip = host.ip;

    bool connected = connect(host.port);
    if (!connected) {
        return {};
    }
    std::string url = target;
    if (params) {
        url = createURL(target, params);
    }

    const int version = 11;
    Request request{method, url, version};
    request.set(boost::beast::http::field::host, HttpClient::ip);
    request.set(boost::beast::http::field::user_agent, BOOST_BEAST_VERSION_STRING);

    if (headers) {
        for (const auto& iter : *headers) {
            request.set(iter.first, iter.second);
        }
    }

    if (body) {
        std::string json = serializer.serialData(body);
        request.set(boost::beast::http::field::content_type, "application/json; charset=utf-8");
        request.set(boost::beast::http::field::content_length,
                    boost::lexical_cast<std::string>(json.size()));
        if (json[json.size() - 1] == '\n') {
            json.pop_back();
        }
        request.set(boost::beast::http::field::body, json);
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
                                          const std::shared_ptr<Params>& params,
                                          const std::shared_ptr<Params>& headers) {
    return makeRequest(host, target, boost::beast::http::verb::get, params, nullptr, headers);
}

ResponseStruct HttpClient::makePostRequest(const Host &host, const std::string &target,
                                           const std::shared_ptr<Params>& body,
                                           const std::shared_ptr<Params>& headers) {
    return makeRequest(host, target, boost::beast::http::verb::post, nullptr, body, headers);
}

ResponseStruct HttpClient::makeDeleteRequest(const Host &host, const std::string &target,
                                             const std::shared_ptr<Params>& body,
                                             const std::shared_ptr<Params>& headers) {
    return makeRequest(host, target, boost::beast::http::verb::delete_, nullptr, body, headers);
}

ResponseStruct HttpClient::makePutRequest(const Host &host, const std::string &target,
                                          const std::shared_ptr<Params>& body,
                                          const std::shared_ptr<Params>& headers) {
    return makeRequest(host, target, boost::beast::http::verb::put, nullptr, body, headers);
}
