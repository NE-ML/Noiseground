#ifndef NOISEGROUND_SOUNDMANAGER_H
#define NOISEGROUND_SOUNDMANAGER_H

#include <memory>

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

#endif //NOISEGROUND_SOUNDMANAGER_H
