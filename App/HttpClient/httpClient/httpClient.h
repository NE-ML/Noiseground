#ifndef NOISEGROUND_HTTPCLIENT_H
#define NOISEGROUND_HTTPCLIENT_H

#include <boost/asio.hpp>
#include <utility>

#include "clientTypes.h"
#include "serializer.h"

class HttpClient {
public:
    HttpClient();
    ResponseStruct makeGetRequest(const Host& host, const std::string& target,
                                  Params* params = nullptr, Params* headers = nullptr);
    ResponseStruct makePostRequest(const Host& host, const std::string& target, Params* body,
                                   Params* headers = nullptr);
    ResponseStruct makeDeleteRequest(const Host& host, const std::string& target, Params* body,
                                     Params* headers = nullptr);
private:
    static ResponseStruct parseResponse(Response response);
    static std::string createURL(const std::string& target, Params* params = nullptr);
    bool connect(unsigned short port);

    boost::asio::io_context context;
    boost::asio::ip::tcp::resolver resolver;
    boost::asio::ip::tcp::socket socket;
    std::string ip;
    boost::beast::flat_buffer flat_buffer;
    Serializer serializer;
};


#endif //NOISEGROUND_HTTPCLIENT_H
