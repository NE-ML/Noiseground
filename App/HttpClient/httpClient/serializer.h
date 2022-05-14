#ifndef HTTPCLIENT_DESERIALIZER_H
#define HTTPCLIENT_DESERIALIZER_H

#include <vector>

#include "sound.h"
#include "clientTypes.h"

class Serializer {
public:
    std::vector<Sound> deserialSounds(const std::string &val);
    std::string serialData(const Params* body);
    std::string encode64(const std::string &val);
private:
    std::string decode64(const std::string &val);
};



#endif //HTTPCLIENT_DESERIALIZER_H
