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
                                  const std::shared_ptr<Params>& params = nullptr,
                                  const std::shared_ptr<Params>& headers = nullptr);
    ResponseStruct makePostRequest(const Host& host, const std::string& target, const std::shared_ptr<Params>& body,
                                   const std::shared_ptr<Params>& headers = nullptr);
    ResponseStruct makeDeleteRequest(const Host& host, const std::string& target, const std::shared_ptr<Params>& body,
                                     const std::shared_ptr<Params>& headers = nullptr);
    ResponseStruct makePutRequest(const Host& host, const std::string& target, const std::shared_ptr<Params>& body,
                                  const std::shared_ptr<Params>& headers = nullptr);
private:
    static ResponseStruct parseResponse(Response response);
    static std::string createURL(const std::string& target, const std::shared_ptr<Params>& params = nullptr);
    bool connect(unsigned short port);
    ResponseStruct makeRequest(const Host& host, const std::string& target, boost::beast::http::verb method,
                               const std::shared_ptr<Params>& params = nullptr,
                               const std::shared_ptr<Params>& body = nullptr,
                               const std::shared_ptr<Params>& headers = nullptr);

    boost::asio::io_context context;
    boost::asio::ip::tcp::resolver resolver;
    boost::asio::ip::tcp::socket socket;
    std::string ip;
    boost::beast::flat_buffer flat_buffer;
    Serializer serializer;
};


#endif //NOISEGROUND_HTTPCLIENT_H
