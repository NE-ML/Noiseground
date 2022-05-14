#ifndef NOISEGROUND_SOUND_SOUNDS_H
#define NOISEGROUND_SOUND_SOUNDS_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>


using namespace sf;
using namespace std;

class Sounds {
public:
    //Sounds(int count, string path);
    void loadMusic(const string& pathFile);
    //void loadSounds();
    void playMusic();  // проигрывание музыки
    void pauseMusic();  // пауза
    void stopMusic();  // стоп
    void setVolume(int volume);  // изменение громкости
    void setTime(int time);  // изменение время проигрывания
    //void action(int id);  // включение/выключение музыки
    //static string getPath();  // получение пути папки со звуками
    SoundSource::Status getStatus();  // получение статуса музыки
    static vector<string> getSounds();  // получение названия звуков
private:
    int count;
    int time{};
    int volume{};
    Music music;
    static string PATH;
};

#endif //NOISEGROUND_SOUND_SOUNDS_H
