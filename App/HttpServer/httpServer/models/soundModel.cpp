#include "soundModel.h"

#include <iostream>
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
    std::string path = "../data/sounds_standard";
    std::vector<Sound> res;
    for (const auto & entry : boost::filesystem::directory_iterator(path)) {
        Sound tmp;
        std::string path_string = entry.path().string();
        std::size_t slash_pos = path_string.rfind("/");
        tmp.name = path_string.substr(slash_pos + 1, path_string.size() - slash_pos - 1);
        tmp.content = readFile(path_string);
        res.push_back(tmp);
    }
    return res;
}

std::vector<Sound> SoundModel::getUserSounds(const std::string& login) {
    std::string path = "../data/sounds_" + login;
    std::vector<Sound> res;
    for (const auto & entry : boost::filesystem::directory_iterator(path)) {
        Sound tmp;
        std::string path_string = entry.path().string();
        std::size_t slash_pos = path_string.rfind("/");
        tmp.name = path_string.substr(slash_pos + 1, path_string.size() - slash_pos - 1);
        tmp.content = readFile(path_string);
        res.push_back(tmp);
    }
    return res;
}

bool SoundModel::createNewSound(const std::pair<std::string, Sound> &new_sound) {
    boost::filesystem::create_directory("../data/sounds_" + new_sound.first);
    if (boost::filesystem::exists("../data/sounds_" + new_sound.first + "/" + new_sound.second.name))
        return false;
    std::ofstream fout("../data/sounds_" + new_sound.first + "/" + new_sound.second.name);
    fout << new_sound.second.content;
    fout.close();
    return true;
}

bool SoundModel::changeSound(const std::pair<std::string, Sound> &sound) {
    if (!boost::filesystem::exists("../data/sounds_" + sound.first + "/" + sound.second.name))
        return false;
    std::ofstream fout("../data/sounds_" + sound.first + "/" + sound.second.name);
    fout << sound.second.content;
    fout.close();
    return true;
}

bool SoundModel::deleteSound(const std::pair<std::string, std::string> &sound) {
    if (!boost::filesystem::exists("../data/sounds_" + sound.first + "/" + sound.second))
        return false;
    boost::filesystem::remove("../data/sounds_" + sound.first + "/" + sound.second);
    return true;
}

