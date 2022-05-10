#include <iostream>

#include "httpClient.h"

int main() {
    const std::string domainExample;
    const std::string ipExample = "127.0.0.1";
    const unsigned short portExample = 8000;
    const std::string targetExample = "/sound/get_standart";

    auto *client = new HttpClient();

    ResponseStruct result = client->makeGetRequest(
            Host(domainExample, ipExample, portExample), targetExample);

    std::cout << result.status << std::endl;
    std::cout << result.body << std::endl;

    delete client;
    return 0;
}
