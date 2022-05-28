#ifndef APP_HTTPSERVER_HTTPSERVER_MODELS_SOUNDMODEL_H_
#define APP_HTTPSERVER_HTTPSERVER_MODELS_SOUNDMODEL_H_

#include <vector>
#include <utility>
#include <string>

#include "sound.h"

class SoundModel {
 public:
    std::vector<Sound> getStdSounds();
    bool createNewSound(const std::pair<std::string, Sound> &new_sound);
    bool changeSound(const std::pair<std::string, Sound> &sound);
    bool deleteSound(const std::pair<std::string, std::string> &sound);
    std::vector<Sound> getUserSounds(const std::string& login);
 private:
    std::string readFile(const std::string& fileName);
};


#endif  // APP_HTTPSERVER_HTTPSERVER_MODELS_SOUNDMODEL_H_
