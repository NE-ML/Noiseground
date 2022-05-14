#include "Sounds.h"
#include <string>
string PATH = "music_example/";
map<int, Keyboard::Key> buttons = {
        {0, Keyboard::Key::Num0}, {1, Keyboard::Key::Num1},
        {2, Keyboard::Key::Num2}, {3, Keyboard::Key::Num3},
        {4, Keyboard::Key::Num4}, {5, Keyboard::Key::Num5},
        {6, Keyboard::Key::Num6}, {7, Keyboard::Key::Num7},
        {8, Keyboard::Key::Num8}, {9, Keyboard::Key::Num9},
        };
void playback(Sounds &music, Keyboard::Key key, Event &event)
{
    if (event.key.code == key) {
        if (music.getStatus() == sf::Music::Paused || music.getStatus() == sf::Music::Stopped)
            music.playMusic();
        else
            music.pauseMusic();
    }
}

void execute() {
    RenderWindow window(VideoMode(640, 480), "Demo Noiseground");
    vector<string> musicNames = Sounds::getSounds();
    Sounds musics[musicNames.size()];
    for(int i = 0; i < musicNames.size(); i++)
        musics[i].loadMusic(PATH + musicNames[i]);
    while (window.isOpen()) {
        Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
                for(int i = 0; i < musicNames.size(); i++)
                    playback(musics[i], buttons[i+1], event);
            }
        }
        window.clear();
        window.display();
    }
}

int main() {
    execute();
}