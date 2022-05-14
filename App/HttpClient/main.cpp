#include <iostream>
#include <fstream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "httpClient.h"

int main() {
    const std::string domainExample;
    const std::string ipExample = "0.0.0.0";
    const unsigned short portExample = 80;
    const std::string targetExample = "/sounds/standard";

    auto *client = new HttpClient();

    ResponseStruct result = client->makeGetRequest(
            Host(domainExample, ipExample, portExample), targetExample);

    std::cout << result.status << std::endl;
    std::cout << result.body << std::endl;

//    std::istringstream in(result.body);
//    boost::property_tree::ptree json;
//    boost::property_tree::read_json(in, json);
//    int count = json.get<int>("count");
//    std::vector<std::pair<std::string, std::string>> sounds;
//    for (auto &sound : json.get_child("sounds")) {
//        std::string name = sound.second.data();
//        std::string data = "data";
//        sounds.push_back(std::make_pair(name, data));
//    }
//
//    for (auto &i : sounds) {
//        std::cout << i.first << "\n";
//    }
//
//
//    std::ofstream f("res.mp3");
//
//    f << res;
//
//    f.close();

    delete client;
    return 0;
}
