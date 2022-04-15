#ifndef NOISEGROUND_SOUNDMANAGER_H
#define NOISEGROUND_SOUNDMANAGER_H

#include "serverTypes.h"
#include "serializer.h"

class SoundManager {
public:
    SoundManager();
    ResponseServer createSound(const RequestServer &request);
    ResponseServer getUserSounds(const RequestServer &request);
    ResponseServer getStdSounds(const RequestServer &request);
    ResponseServer changeSound(const RequestServer &request);
    ResponseServer deleteSound(const RequestServer &request);
private:
    SoundModel* soundModel = new SoundModel();
    Serializer* ser = new Serializer();
};

#endif //NOISEGROUND_SOUNDMANAGER_H
