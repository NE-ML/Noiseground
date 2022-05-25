#include "Sounds.h"
#include <iostream>

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

void Sounds::loadMusic(const std::string &pathFile) {
    try {
        if (!music.openFromFile(pathFile))
            throw "File does not exist";
    }
    catch (const char *msg) {
        std::cerr << msg << std::endl;
    }
    music.setLoop(true);
}

sf::SoundSource::Status Sounds::getStatus() {
    return music.getStatus();
}


std::vector<std::string> Sounds::getSounds() {
    std::map<int, std::string> tracks = {
            {1, "birds.wav"},
            {2, "killdeer.wav"},
            {3, "waves.wav"},
            {4, "rain.wav"},
    };
    std::vector<std::string> vector_of_sound_names;
    for (auto &track: tracks)
        vector_of_sound_names.push_back(track.second);

    return vector_of_sound_names;
}


/// Musics
void Musics::loadMusics(const std::string &pathFile) {
    std::vector<std::string> musicNames = Sounds::getSounds();
    for (int i = 0; i < musicNames.size(); i++)
        musicMap[i].loadMusic(pathFile + musicNames[i]);
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

