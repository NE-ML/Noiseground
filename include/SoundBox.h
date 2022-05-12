#ifndef INCLUDE_SOUNDBOX_H_
#define INCLUDE_SOUNDBOX_H_

#include <string>

#include <QGroupBox>
#include <QPushButton>
#include <QSlider>

class SoundBox {
public:
    SoundBox(const std::string &name);
    
private:
    std::string name;
    QGroupBox *self;
    QPushButton *playPauseButton;
    QSlider *volumeSlider;
};


#endif //INCLUDE_SOUNDBOX_H_
