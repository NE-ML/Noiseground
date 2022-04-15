#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>
#include <boost/asio.hpp>
#include <boost/beast.hpp>

#include "httpClient.h"
#include "httpConnection.h"
#include "httpServer.h"

class MockHttpConnection : public HttpConnection {
public:
    explicit MockHttpConnection(boost::asio::ip::tcp::socket socket, Router* router) :
            HttpConnection(std::move(socket), router) {};

    MOCK_METHOD(void, start, ());
    MOCK_METHOD(void, doRead, ());
    MOCK_METHOD(void, onRead, ());
    MOCK_METHOD(void, doWrite, ());
};

class MockHttpClient : public HttpClient {
public:
    explicit MockHttpClient() :
            HttpClient() {};

};

class MockHttpServer : public HttpServer {
public:
    explicit MockHttpServer(std::string &address, unsigned short port) :
            HttpServer(address, port) {};

    MOCK_METHOD(void, run, ());
    MOCK_METHOD(void, accept, ());
};

class MockRouter : public Router {
public:
    MockRouter(UserManager *userManager, SoundManager *soundManager) :
            Router(userManager, soundManager) {}

    MOCK_METHOD(RequestServer, execute, (RequestServer&));
};

class MockUserManager : public UserManager {
public:
    MockUserManager() : UserManager() {}
    MOCK_METHOD(ResponseServer , createUser, (RequestServer &));
    MOCK_METHOD(ResponseServer , changeUser, (RequestServer &));
    MOCK_METHOD(ResponseServer , loginUser, (RequestServer &));
};

class MockSoundManager : public SoundManager {
public:
    MockSoundManager() = default;

    MOCK_METHOD(ResponseServer, createSound, (RequestServer &));
    MOCK_METHOD(ResponseServer, getUserSounds, (RequestServer &));
    MOCK_METHOD(ResponseServer, getStdSounds, (RequestServer &));
    MOCK_METHOD(ResponseServer, changeSound, (RequestServer &));
    MOCK_METHOD(ResponseServer, deleteSound, (RequestServer &));
};

TEST(serverTest, startServerConnection) {
    boost::asio::io_service context(1);
    boost::asio::ip::tcp::socket socket(context);
    Router *router = nullptr;
    MockHttpConnection connection(std::move(socket), router);

    EXPECT_CALL(connection, start()).Times(testing::AtLeast(1));

    std::string address;
    unsigned short port = 8000;
    HttpServer server(address, port);
    server.run();
}


int main(int argc, char *argv[]) {
    std::cout << 3 << std::endl;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}