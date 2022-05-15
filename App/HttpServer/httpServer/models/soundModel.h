#ifndef NOISEGROUND_SOUNDMODEL_H
#define NOISEGROUND_SOUNDMODEL_H

#include <vector>
#include <utility>

#include "sound.h"

class SoundModel {
public:
    std::vector<Sound> getStdSounds();
    bool createNewSound(const std::pair<std::string, Sound> &new_sound);
    bool deleteSound(const std::pair<std::string, std::string> &sound);
    std::vector<Sound> getUserSounds(const std::string& login);
private:
    std::string readFile(const std::string& fileName);
};


#endif //NOISEGROUND_SOUNDMODEL_H
