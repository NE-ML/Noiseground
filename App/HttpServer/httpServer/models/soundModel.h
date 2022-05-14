#ifndef NOISEGROUND_SOUNDMODEL_H
#define NOISEGROUND_SOUNDMODEL_H

#include "sound.h"
#include <vector>

class SoundModel {
public:
    std::vector<Sound> getStdSounds();
private:
    std::vector<std::string> standardNames = {"Sound_22378.mp3", "Sound_23375.mp3", "forest.mp3"};
    std::string readFile(const std::string& fileName);
};


#endif //NOISEGROUND_SOUNDMODEL_H
