#ifndef NOISEGROUND_SOUND_SOUNDS_H
#define NOISEGROUND_SOUND_SOUNDS_H

#include <SFML/Audio.hpp>
#include <map>


class Sounds {
public:
    void loadMusic(const std::string &pathFile);
    void playMusic();  // проигрывание музыки
    void pauseMusic();  // пауза
    void stopMusic();  // стоп
    void setVolume(int volume);  // изменение громкости
    void setTime(int time);  // изменение время проигрывания
    sf::SoundSource::Status getStatus();  // получение статуса музыки
    static std::vector<std::string> getSounds(const std::string &path);  // получение названия звуков
    int getCount;
private:
    int time{};
    int volume{};
    sf::Music music;
    static std::string PATH;
};

class Musics {
public:
    void loadMusics(const std::string &pathFile);

    void play(int id, int volume);

    void pause(int id);

    void changeVolume(int id, int volume);

    bool isEmpty();

private:
    std::map<int, Sounds> musicMap;
};

#endif //NOISEGROUND_SOUND_SOUNDS_H
