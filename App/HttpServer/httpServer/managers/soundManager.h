#ifndef NOISEGROUND_SOUNDMANAGER_H
#define NOISEGROUND_SOUNDMANAGER_H

#include "serializer.h"
#include "sound.h"

class SoundManager {
public:
    SoundManager() = default;
//    ResponseServer createSound(const Request &request);
//    ResponseServer getUserSounds(const Request &request);
    std::string getStdSounds();
//    ResponseServer changeSound(const Request &request);
//    ResponseServer deleteSound(const Request &request);
private:
//    SoundModel* soundModel = new SoundModel();
    Serializer* serializer = new Serializer();
    std::vector<std::string> standardNames = {"Sound_22378.mp3", "Sound_23375.mp3", "forest.mp3"};
    static std::string readFile(const std::string& fileName);
};

#endif //NOISEGROUND_SOUNDMANAGER_H
