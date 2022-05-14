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
//    ResponseServer getUserSounds(const Request &request);
    void getStdSounds(Reply& rep);
//    ResponseServer changeSound(const Request &request);
//    ResponseServer deleteSound(const Request &request);
    ~SoundManager() {
        delete serializer;
        delete soundModel;
    }
private:
//    SoundModel* soundModel = new SoundModel();
    Serializer* serializer = new Serializer();
    SoundModel* soundModel = new SoundModel();
};

#endif //NOISEGROUND_SOUNDMANAGER_H
