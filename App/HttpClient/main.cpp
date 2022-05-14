#include <iostream>
#include <fstream>

#include "httpClient.h"
#include "deserializer.h"

int main() {
    const std::string domainExample;
    const std::string ipExample = "0.0.0.0";
    const unsigned short portExample = 80;
    const std::string targetExample = "/sounds/standard";

    auto *client = new HttpClient();
    auto *deserializer = new Deserializer();

    ResponseStruct result = client->makeGetRequest(
            Host(domainExample, ipExample, portExample), targetExample);

    if (result.status == 200) {
        std::vector<Sound> sounds = deserializer->deserialSounds(result.body);
        for (auto &i : sounds) {
            std::ofstream fout(i.name);
            fout << i.content;
            fout.close();
        }
        std::cout << "Saved";
    } else {
        std::cout << "Fail with status " << result.status;
    }

    delete deserializer;
    delete client;
    return 0;
}
