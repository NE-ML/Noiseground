#include "soundModel.h"

#include <fstream>
#include <sstream>
#include <boost/filesystem.hpp>

std::string SoundModel::readFile(const std::string& fileName) {
    std::ifstream f(fileName);
    std::stringstream ss;
    ss << f.rdbuf();
    f.close();
    return ss.str();
}

std::vector<Sound> SoundModel::getStdSounds() {
    std::vector<Sound> res(standardNames.size());
    int k = 0;
    for (auto &i : standardNames) {
        res[k].name = i;
        res[k].content = readFile("../data/sounds_standard" + i);
        k++;
    }
    return res;
};

bool SoundModel::createNewSound(const std::pair<std::string, Sound> &new_sound) {
    boost::filesystem::create_directory("../data/sounds_" + new_sound.first);
    if (boost::filesystem::exists("../data/sounds_" + new_sound.first + "/" + new_sound.second.name))
        return false;
    std::ofstream fout("../data/sounds_" + new_sound.first + "/" + new_sound.second.name);
    fout << new_sound.second.content;
    fout.close();
    return true;
};

