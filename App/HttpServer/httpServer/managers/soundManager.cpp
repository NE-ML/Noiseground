#include "soundManager.h"

#include <fstream>
#include <sstream>

std::string SoundManager::readFile(const std::string& fileName) {
    std::ifstream f(fileName);
    std::stringstream ss;
    ss << f.rdbuf();
    f.close();
    return ss.str();
}

std::string SoundManager::getStdSounds() {
    std::vector<Sound> res(standardNames.size());
    int k = 0;
    for (auto &i : standardNames) {
        res[k].name = i;
        res[k].content = readFile("../data/sounds" + i);
        k++;
    }
    return serializer->serialSounds(res);
}