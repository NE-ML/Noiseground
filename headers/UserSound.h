#ifndef NOISEGROUND_SOUND_USERSOUND_H
#define NOISEGROUND_SOUND_USERSOUND_H

#include <Sound.h>

class UserSound {
public:
    void loadFile(FILE file);
    void deleteFile();
    string getListMusic();
};
#endif //NOISEGROUND_SOUND_USERSOUND_H
