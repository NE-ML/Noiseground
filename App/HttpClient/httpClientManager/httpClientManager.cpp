#include "httpClientManager.h"

#include <fstream>
#include <utility>

HttpClientManager::HttpClientManager(const std::string &domain, const std::string &ip, const unsigned short &port,
                                     std::string saved_path_)
                : host(domain, ip, port), client(), serializer(), saved_path(std::move(saved_path_)) {}

//void HttpClientManager::saveSounds(const std::vector<Sound> &sounds) {
//    for (auto &i : sounds) {
//        std::ofstream fout(saved_path + i.name);
//        fout << i.content;
//        fout.close();
//    }
//}

unsigned int HttpClientManager::getStdSounds() {
    const std::string target = "/sound/standard";
    ResponseStruct result = client.makeGetRequest(host, target);
    if (result.status == 200) {
        std::vector<Sound> sounds = serializer.deserialSounds(result.body);
//        saveSounds(sounds);
        for (auto &i : sounds) {
            std::ofstream fout(saved_path + i.name);
            fout << i.content;
            fout.close();
        }
    }
    return result.status;
}

unsigned int HttpClientManager::loginUser(const std::string &login, const std::string &password) {
    const std::string target = "/user/auth";
    auto* params = new Params;
    params->insert({"login", login});
    params->insert({"password", password});
    ResponseStruct result = client.makeGetRequest(host, target, params);
    delete params;
    return result.status;
}

unsigned int HttpClientManager::registerUser(const std::string &login, const std::string &password) {
    const std::string target = "/user/register";
    auto* body = new Params;
    body->insert({"login",  login});
    body->insert({"password", password});
    ResponseStruct result = client.makePostRequest(host, target, body);
    delete body;
    return result.status;
}

unsigned int HttpClientManager::uploadSound(const std::string &login, const std::string &path_to_sound) {
    std::string target = "/sound/upload";
    std::size_t slash_pos = path_to_sound.rfind('/');
    std::string name = path_to_sound.substr(slash_pos + 1, path_to_sound.size() - slash_pos - 1);
    std::ifstream f(path_to_sound);
    std::stringstream ss;
    ss << f.rdbuf();
    f.close();
    std::string f_content = ss.str();
    auto* body = new Params;
    body->insert({"username", login});
    body->insert({"name", name});
    body->insert({"data", serializer.encode64(f_content)});
    ResponseStruct result = client.makePostRequest(host, target, body);
    delete body;
    return result.status;
}

unsigned int HttpClientManager::getUserSounds(const std::string &login) {
    const std::string target = "/sound/get";
    auto* params = new Params;
    params->insert({"username", login});
    ResponseStruct result = client.makeGetRequest(host, target, params);
    if (result.status == 200) {
        std::vector<Sound> sounds = serializer.deserialSounds(result.body);
//        saveSounds(sounds);
        for (auto &i : sounds) {
            std::ofstream fout(saved_path + i.name);
            fout << i.content;
            fout.close();
        }
    }
    delete params;
    return result.status;
}

unsigned int HttpClientManager::deleteSound(const std::string &login, const std::string &sound_name) {
    const std::string target = "/sound/";
    auto* body = new Params;
    body->insert({"username", login});
    body->insert({"name", sound_name});
    ResponseStruct result = client.makeDeleteRequest(host, target, body);
    delete body;
    return result.status;
}

unsigned int HttpClientManager::changeSound(const std::string &login, const std::string &sound_name,
                                            const std::string &path_to_new_sound) {
    std::string target = "/sound";
    std::ifstream f(path_to_new_sound);
    std::stringstream ss;
    ss << f.rdbuf();
    f.close();
    std::string f_content = ss.str();
    auto* body = new Params;
    body->insert({"username", login});
    body->insert({"name", sound_name});
    body->insert({"new_data", serializer.encode64(f_content)});
    ResponseStruct result = client.makePutRequest(host, target, body);
    delete body;
    return result.status;
}