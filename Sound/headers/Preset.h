#ifndef NOISEGROUND_SOUND_PRESET_H
#define NOISEGROUND_SOUND_PRESET_H

#include <Sounds.h>

class Preset {
public:
    string getPreset(string nameFile);

private:
    ::Sound preset;
    int count;
    string path;
};


#endif //NOISEGROUND_SOUND_PRESET_H
