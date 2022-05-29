#ifndef INCLUDE_CORE_H_
#define INCLUDE_CORE_H_

#include <string>
#include <vector>

class Core {
public:
    static void play(int soundId, int volume);

    static void changeVolume(int soundId, int value);

    static void pause(int soundId);

    static void loadMusic(const std::string& path);

    static unsigned int signUp(const std::string &login, const std::string &pass);

    static unsigned login(const std::string &login, const std::string &pass);

    static unsigned downloadStdSounds();

    static std::vector<std::string> getStdSounds();
};


#endif //INCLUDE_CORE_H_
