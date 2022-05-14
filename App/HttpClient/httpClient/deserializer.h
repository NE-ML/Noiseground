#ifndef HTTPCLIENT_DESERIALIZER_H
#define HTTPCLIENT_DESERIALIZER_H

#include <vector>

#include "sound.h"

class Deserializer {
public:
    std::vector<Sound> deserialSounds(std::string &val);
private:
    std::string decode64(const std::string &val);
};


#endif //HTTPCLIENT_DESERIALIZER_H
