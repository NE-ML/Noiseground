#ifndef NOISEGROUND_SOUNDMANAGER_H
#define NOISEGROUND_SOUNDMANAGER_H

#include "serializer.h"
#include "sound.h"
#include <vector>

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
    std::vector<std::string> standardNames = {"../sounds/Sound_22378.mp3", "../sounds/Sound_23375.mp3"};
    static std::string readFile(const std::string& fileName);
};

#endif //NOISEGROUND_SOUNDMANAGER_H
