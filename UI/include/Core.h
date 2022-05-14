#ifndef INCLUDE_CORE_H_
#define INCLUDE_CORE_H_

#include <string>

class Core {
public:
    static void play(int soundId, int volume);

    static void changeVolume(int soundId, int value);

    static void pause(int soundId);

    static void loadMusic(const std::string &path);
};


#endif //INCLUDE_CORE_H_
