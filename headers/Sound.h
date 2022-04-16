#ifndef NOISEGROUND_SOUND_SOUND_H
#define NOISEGROUND_SOUND_SOUND_H

#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

class Sound {
public:
    Sound(string path);
    void playMusic();
    void pauseMusic();
    void stopMusic();
    void setVolume(int volume);
    void setTime(int time);
    ~Sound() = default;
private:
    int time;
    int volume;
    Music loadMusic(string);
};

#endif //NOISEGROUND_SOUND_SOUND_H
