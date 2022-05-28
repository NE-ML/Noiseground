#ifndef APP_HTTPCLIENT_HTTPCLIENT_SERIALIZER_H_
#define APP_HTTPCLIENT_HTTPCLIENT_SERIALIZER_H_

#include <vector>
#include <memory>
#include <string>

#include "sound.h"
#include "clientTypes.h"

class Serializer {
 public:
    std::vector<Sound> deserialSounds(const std::string &val);
    std::string serialData(const std::shared_ptr<Params>& body);
    std::string encode64(const std::string &val);
 private:
    std::string decode64(const std::string &val);
};



#endif  // APP_HTTPCLIENT_HTTPCLIENT_SERIALIZER_H_
