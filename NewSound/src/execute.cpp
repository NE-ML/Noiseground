#include "Sounds.h"
#include <SFML/Graphics.hpp>
#include <string>

std::string PATH = "music_example/";

std::map<int, sf::Keyboard::Key> buttons = {
        {0, sf::Keyboard::Key::Num0},
        {1, sf::Keyboard::Key::Num1},
        {2, sf::Keyboard::Key::Num2},
        {3, sf::Keyboard::Key::Num3},
        {4, sf::Keyboard::Key::Num4},
        {5, sf::Keyboard::Key::Num5},
        {6, sf::Keyboard::Key::Num6},
        {7, sf::Keyboard::Key::Num7},
        {8, sf::Keyboard::Key::Num8},
        {9, sf::Keyboard::Key::Num9}
};

void playback(Sounds &music, sf::Keyboard::Key key, sf::Event &event) {
    if (event.key.code == key) {
        if (music.getStatus() == sf::Music::Paused || music.getStatus() == sf::Music::Stopped)
            music.playMusic();
        else
            music.pauseMusic();
    }
}

void execute() {
    sf::RenderWindow window(sf::VideoMode(640, 480), "Demo Noiseground");
    std::vector<std::string> musicNames = Sounds::getSounds();
    Sounds sounds[musicNames.size()];
    Musics musics;
    musics.loadMusics(PATH);
    for (int i = 0; i < musicNames.size(); i++) {
        sounds[i].loadMusic(PATH + musicNames[i]);
    }

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
                for (int i = 0; i < musicNames.size(); i++)
                    playback(sounds[i], buttons[i + 1], event);
            }
        }
        window.clear();
        window.display();
    }
}

int main() {
    execute();
}