#include "Sounds.h"

#include <filesystem>
/// Sounds

void Sounds::playMusic() {
    music.play();
}

void Sounds::pauseMusic() {
    music.pause();
}

void Sounds::stopMusic() {
    music.stop();
}

void Sounds::setVolume(int vol) {
    music.setVolume(vol);
}

void Sounds::setTime(int time) {
}

void Sounds::loadMusic(const string& pathFile) {
    try {
        if (!music.openFromFile(pathFile))
            throw "File does not exist";
    }
    catch (const char* msg) {
        cerr << msg << endl;
    }
    music.setLoop(true);
}

sf::SoundSource::Status Sounds::getStatus() {
    return music.getStatus();
}


vector<string> Sounds::getSounds(const std::string &path) {
    std::vector<std::string> res;
    if (!std::filesystem::exists(path)) {
        std::filesystem::create_directory(path);
    }
    for (const auto & entry : std::filesystem::directory_iterator(path)) {
        std::string tmp;
        std::string path_string = entry.path().string();
        std::size_t slash_pos = path_string.rfind('/');
        tmp = path_string.substr(slash_pos + 1, path_string.size() - slash_pos - 1);
        res.push_back(tmp);
    }
    return res;
}


/// Musics
void Musics::loadMusics(const string& pathFile) {
    vector<string> musicNames = Sounds::getSounds(pathFile);
    for (int i = 0; i < musicNames.size(); i++)
        musicMap[i + 1].loadMusic(pathFile + musicNames[i]);
}

void Musics::play(int id, int volume) {
    musicMap[id].setVolume(volume);
    musicMap[id].playMusic();
}

void Musics::pause(int id) {
    musicMap[id].pauseMusic();
}

void Musics::changeVolume(int id, int volume) {
    musicMap[id].setVolume(volume);
}

