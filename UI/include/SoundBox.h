#ifndef INCLUDE_SOUNDBOX_H_
#define INCLUDE_SOUNDBOX_H_

#include <string>

#include <QGroupBox>
#include <QPushButton>
#include <QSlider>

#include "PlayPauseButton.h"

class SoundBox : public QGroupBox {
Q_OBJECT
public:
    explicit SoundBox(const std::pair<int, std::string> &data);

public slots:

    void pause(int soundId);

    void volumeChanged(int value);

    void play(int soundId);

private:
    int id;
    std::string name;
    PlayPauseButton *playPauseButton;
    QSlider *volumeSlider;
};


#endif //INCLUDE_SOUNDBOX_H_
