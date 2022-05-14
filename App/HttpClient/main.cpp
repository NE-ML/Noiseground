#include <iostream>
#include <fstream>

#include "httpClient.h"
#include "serializer.h"

int main() {
    const std::string domainExample;
    const std::string ipExample = "0.0.0.0";
    const unsigned short portExample = 80;
    auto *client = new HttpClient();
    auto *serializer = new Serializer();

//    const std::string targetExample1 = "/sound/standard";
//
//    ResponseStruct result1 = client->makeGetRequest(
//            Host(domainExample, ipExample, portExample), targetExample1);
//
//    if (result1.status == 200) {
//        std::vector<Sound> sounds = serializer->deserialSounds(result1.body);
//        for (auto &i : sounds) {
//            std::ofstream fout(i.name);
//            fout << i.content;
//            fout.close();
//        }
//        std::cout << "Saved";
//    } else {
//        std::cout << "Fail with status " << result1.status;
//    }
//
//    std::cout << "\n------------\n";
//
//    const std::string targetExample2 = "/user/auth";
//    auto* params2 = new Params;
//    params2->insert({"login", "a"});
//    params2->insert({"password", "b"});
//
//    ResponseStruct result2 = client->makeGetRequest(
//            Host(domainExample, ipExample, portExample), targetExample2, params2);
//
//    std::cout << result2.status;

//    std::cout << "\n------------\n";
//
    const std::string targetExample3 = "/user/register";
    auto* body3 = new Params;
    body3->insert({"login", "f"});
    body3->insert({"password", "g"});

    ResponseStruct result3 = client->makePostRequest(
            Host(domainExample, ipExample, portExample), targetExample3, body3);

    std::cout << result3.status;

    delete serializer;
    delete client;
    return 0;
}
