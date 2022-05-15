#ifndef NOISEGROUND_SERIALIZER_H
#define NOISEGROUND_SERIALIZER_H

#include <vector>
#include <utility>

#include "sound.h"
#include "user.h"

class Serializer {
public:
    std::string serialSounds(std::vector<Sound> &sounds);
    User deserialRegisterData(const std::string& val);
    std::pair<std::string, Sound> deserialNewSoundData(const std::string& val);
    std::pair<std::string, Sound> deserialChangedSoundData(const std::string& val);
    std::pair<std::string, std::string> deserialDeletedSoundData(const std::string& val);
    std::string decode64(const std::string &val);
private:
    std::string encode64(const std::string &val);
};


#endif //NOISEGROUND_SERIALIZER_H
