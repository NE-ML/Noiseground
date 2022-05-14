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

    const std::string targetExample1 = "/sound/standard";

    ResponseStruct result1 = client->makeGetRequest(
            Host(domainExample, ipExample, portExample), targetExample1);

    std::cout << targetExample1 << "\n";

    if (result1.status == 200) {
        std::vector<Sound> sounds = serializer->deserialSounds(result1.body);
        for (auto &i : sounds) {
            std::ofstream fout(i.name);
            fout << i.content;
            fout.close();
        }
        std::cout << "Saved";
    } else {
        std::cout << "Fail with status " << result1.status;
    }

    std::cout << "\n------------\n";

    const std::string targetExample2 = "/user/auth";

    std::cout << targetExample2 << "?login=a&password=b" << "\n";

    auto* params2 = new Params;
    std::string login = "a";
    params2->insert({"login", login});
    params2->insert({"password", "b"});

    ResponseStruct result2 = client->makeGetRequest(
            Host(domainExample, ipExample, portExample), targetExample2, params2);

    std::cout << result2.status;

    std::cout << "\n------------\n";

    const std::string targetExample3 = "/user/register";

    std::cout << targetExample3 << "\n";

    auto* body3 = new Params;
    body3->insert({"login", "f"});
    body3->insert({"password", "g"});

    ResponseStruct result3 = client->makePostRequest(
            Host(domainExample, ipExample, portExample), targetExample3, body3);

    std::cout << result3.status;

    result3 = client->makePostRequest(
            Host(domainExample, ipExample, portExample), targetExample3, body3);

    std::cout << "\n" << result3.status;

    std::cout << "\n------------\n";

    const std::string targetExample4 = "/sound/upload";
    const std::string sound_name = "forest1.mp3";
    const std::string sound_path = "../sounds_to_upload/" + sound_name;
    std::ifstream f(sound_path);
    std::stringstream ss;
    ss << f.rdbuf();
    f.close();
    std::string f_content = ss.str();

    std::cout << targetExample4 << "\n";

    auto* body4 = new Params;
    body4->insert({"username", login});
    body4->insert({"name", sound_name});
    body4->insert({"data", serializer->encode64(f_content)});

    ResponseStruct result4 = client->makePostRequest(
            Host(domainExample, ipExample, portExample), targetExample4, body4);

    std::cout << "\n" << result4.status;

    delete body3;
    delete body4;
    delete serializer;
    delete client;
    return 0;
}
