#ifndef NOISEGROUND_SERIALIZER_H
#define NOISEGROUND_SERIALIZER_H

#include <vector>

#include "sound.h"

class Serializer {
public:
    std::string serialSounds(std::vector<Sound> &sounds);
private:
    std::string encode64(const std::string &val);
};


#endif //NOISEGROUND_SERIALIZER_H
