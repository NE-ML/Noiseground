#include "Core.h"

#include "Sounds.h"
#include "httpClientManager.h"

Musics musics;
HttpClientManager client("", "0.0.0.0", 80, "../music_example/");

void Core::play(int soundId, int volume) {
    if (musics.isEmpty()) {
        musics.loadMusics("../music_example/");
    }
    musics.play(soundId, volume);
}

void Core::changeVolume(int soundId, int value) {
    musics.changeVolume(soundId, value);
}

void Core::pause(int soundId) {
    musics.pause(soundId);
}

void Core::loadMusic(const std::string& path) {
    musics.loadMusics(path);
}

bool Core::signUp(const string &login, const string &pass) {
    if (client.registerUser(login, pass) != 200) {
        std::cerr << "Register failed\n";
        return false;
    }
    return true;
}

unsigned Core::login(const string &login, const string &pass) {
    return client.loginUser(login, pass);
}

unsigned Core::getStdSounds() {
    return client.getStdSounds();
}
