#include <iostream>
#include <boost/bind.hpp>
#include <boost/lexical_cast.hpp>

#include "httpServer.h"

using namespace std;

int main(int argc, char* argv[]) {
    std::cout << 2;
    try
    {
        if (argc != 5)
        {
            std::cerr << "Usage: http_server <address> <port> <threads> <doc_root>\n";
            std::cerr << "  For IPv4, try:\n";
            std::cerr << "    receiver 0.0.0.0 80 1 .\n";
            std::cerr << "  For IPv6, try:\n";
            std::cerr << "    receiver 0::0 80 1 .\n";
            return 1;
        }

        std::cout << 1;

        auto num_threads = boost::lexical_cast<std::size_t>(argv[3]);
        HttpServer s(argv[1], argv[2], argv[4], num_threads);

        std::cout << 1;

        s.run();
    }
    catch (std::exception& e)
    {
        std::cerr << "exception: " << e.what() << "\n";
    }

    return 0;
}