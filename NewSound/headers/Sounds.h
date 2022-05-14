#ifndef NOISEGROUND_SOUND_SOUNDS_H
#define NOISEGROUND_SOUND_SOUNDS_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>


using namespace sf;
using namespace std;

class Sounds {
public:
    void loadMusic(const string& pathFile);
    void playMusic();  // проигрывание музыки
    void pauseMusic();  // пауза
    void stopMusic();  // стоп
    void setVolume(int volume);  // изменение громкости
    void setTime(int time);  // изменение время проигрывания
    SoundSource::Status getStatus();  // получение статуса музыки
    static vector<string> getSounds();  // получение названия звуков
    int getCount;
private:
    int time{};
    int volume{};
    Music music;
    static string PATH;
};

class Musics {
public:
    void loadMusics(const string& pathFile);
    void play(int id, int volume);
    void pause(int id);
    void changeVolume(int id, int volume);
private:
    map<int, Sounds> musicMap;
};

#endif //NOISEGROUND_SOUND_SOUNDS_H
