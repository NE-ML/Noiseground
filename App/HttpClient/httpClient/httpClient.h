#ifndef NOISEGROUND_HTTPCLIENT_H
#define NOISEGROUND_HTTPCLIENT_H


#include <boost/asio.hpp>
#include <utility>

#include "clientTypes.h"

class HttpClient {
public:
    HttpClient();
    ResponseStruct makeGetRequest(const Host& host, const std::string& target,
                                  Params* params = nullptr, Params* headers = nullptr);
    ResponseStruct makePostRequest(const Host& host, const std::string& target, Params* body,
                                  Params* params = nullptr, Params* headers = nullptr);
    ResponseStruct makeDeleteRequest(const Host& host, const std::string& target,
                                  Params* params = nullptr, Params* headers = nullptr);
private:
    ResponseStruct parseResponse(Response response);
    std::string createURL(const Host& host, const std::string& target, Params* params = nullptr);
    bool connect(unsigned short port);

    boost::asio::ip::tcp::resolver resolver;
    boost::asio::ip::tcp::socket socket;
    std::string ip;
    boost::beast::flat_buffer flat_buffer;
};


#endif //NOISEGROUND_HTTPCLIENT_H
