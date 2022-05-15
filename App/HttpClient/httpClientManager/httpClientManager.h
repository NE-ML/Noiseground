#ifndef HTTPCLIENT_HTTPCLIENTMANAGER_H
#define HTTPCLIENT_HTTPCLIENTMANAGER_H

#include "httpClient.h"

class HttpClientManager {
public:
    HttpClientManager(const std::string &domain, const std::string &ip, const unsigned short &port,
                      std::string saved_path_);
    unsigned int getStdSounds();
    unsigned int loginUser(const std::string &login, const std::string &password);
    unsigned int registerUser(const std::string &login, const std::string &password);
    unsigned int uploadSound(const std::string &login, const std::string &path_to_sound);
    unsigned int getUserSounds(const std::string &login);
    unsigned int deleteSound(const std::string &login, const std::string &sound_name);
private:
    std::string saved_path;
    Host host;
    HttpClient client;
    Serializer serializer;

//    void saveSounds(const std::vector<Sound> &sounds);
};


#endif //HTTPCLIENT_HTTPCLIENTMANAGER_H
