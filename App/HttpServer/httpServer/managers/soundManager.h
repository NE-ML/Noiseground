#ifndef NOISEGROUND_SOUNDMANAGER_H
#define NOISEGROUND_SOUNDMANAGER_H

#include "reply.h"
#include "request.h"
#include "soundModel.h"
#include "serializer.h"

class SoundManager {
public:
    SoundManager() = default;
    void createSound(const Request &req, Reply& rep);
    void getUserSounds(const std::string &request_path, Reply& rep);
    void getStdSounds(Reply& rep);
//    ResponseServer changeSound(const Request &request);
    void deleteSound(const Request &req, Reply& rep);
    ~SoundManager() {
        delete serializer;
        delete soundModel;
    }
private:
    Serializer* serializer = new Serializer();
    SoundModel* soundModel = new SoundModel();
    static std::string get_param(const std::string& path, const std::string& name);
};

#endif //NOISEGROUND_SOUNDMANAGER_H
