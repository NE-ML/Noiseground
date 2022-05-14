#ifndef INCLUDE_CORE_H_
#define INCLUDE_CORE_H_


class Core {
public:
    static void play(int soundId, int volume);
    
    static void changeVolume(int soundId);
    
    static void pause(int soundId);
};


#endif //INCLUDE_CORE_H_
