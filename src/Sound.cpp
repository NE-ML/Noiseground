#include <utility>

#include "Sounds.h"

//string Sounds::getPath() {
//    PATH = "music_example/";
//    return PATH;
//}

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

SoundSource::Status Sounds::getStatus() {
    return music.getStatus();
}


vector<string> Sounds::getSounds() {
    map<int, string> tracks = {
            {1, "birds.wav"},
            {2, "killdeer.wav"},
            {3, "ding.flac"}
    };
    vector<string> vector_of_sound_names;
    for(auto & track : tracks)
        vector_of_sound_names.push_back(track.second);

    return vector_of_sound_names;
}

//Sounds::Sounds(int count, string path) : count(count) {
//    PATH = move(path);
//    musics = new Music[count];
//    for(int i = 0; i < count; i++)
//        musics[i].
//}


