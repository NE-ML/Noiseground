#ifndef APP_HTTPSERVER_HTTPSERVER_MANAGERS_SOUNDMANAGER_H_
#define APP_HTTPSERVER_HTTPSERVER_MANAGERS_SOUNDMANAGER_H_

#include <memory>
#include <string>

#include "reply.h"
#include "request.h"
#include "soundModel.h"
#include "serializer.h"

class SoundManager {
 public:
    SoundManager();
    void createSound(const Request &req, Reply& rep);
    void getUserSounds(const std::string &request_path, Reply& rep);
    void getStdSounds(Reply& rep);
    void changeSound(const Request &req, Reply& rep);
    void deleteSound(const Request &req, Reply& rep);
 private:
    std::shared_ptr<Serializer> serializer;
    std::shared_ptr<SoundModel> soundModel;
    static std::string get_param(const std::string& path, const std::string& name);
};

#endif  // APP_HTTPSERVER_HTTPSERVER_MANAGERS_SOUNDMANAGER_H_
