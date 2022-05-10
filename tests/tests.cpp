#include <gtest/gtest.h>
#include <algorithm>
#include <boost/asio.hpp>

#include "httpClient.h"
#include "httpConnection.h"
#include "httpServer.h"
#include "router.h"
#include "userManager.h"
#include "soundManager.h"


TEST(serverTest, startServerConnection) {
    boost::asio::io_service context(1);
    boost::asio::ip::tcp::socket socket(context);
    Router *router = nullptr;
    HttpConnection connection(std::move(socket), router);

    std::string address;
    unsigned short port = 8000;
    HttpServer server(address, port);
    EXPECT_NO_FATAL_FAILURE(server.run());
}

int main(int argc, char *argv[]) {
    std::cout << 3 << std::endl;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}