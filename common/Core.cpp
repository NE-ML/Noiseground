#include "Core.h"

#include "Sounds.h"
#include "httpClientManager.h"

const std::string CLIENT_DOMAIN = "";
const std::string CLIENT_IP = "0.0.0.0";
const unsigned CLIENT_PORT = 80;
const std::string SOUNDS_PATH = "../std_sounds/";

Musics musics;
HttpClientManager client(CLIENT_DOMAIN, CLIENT_IP, CLIENT_PORT, SOUNDS_PATH);

void Core::play(int soundId, int volume) {
    if (musics.isEmpty()) {
        musics.loadMusics(SOUNDS_PATH);
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

unsigned Core::downloadStdSounds() {
    return client.getStdSounds();
}

std::vector<std::string> Core::getStdSounds() {
    return Sounds::getSounds(SOUNDS_PATH);
}
