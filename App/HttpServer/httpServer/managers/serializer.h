#ifndef NOISEGROUND_SERIALIZER_H
#define NOISEGROUND_SERIALIZER_H

#include <vector>

#include "sound.h"
#include "user.h"

class Serializer {
public:
    std::string serialSounds(std::vector<Sound> &sounds);
    User deserialRegisterData(const std::string& val);
private:
    std::string encode64(const std::string &val);
};


#endif //NOISEGROUND_SERIALIZER_H
