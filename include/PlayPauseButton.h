#ifndef INCLUDE_PLAYPAUSEBUTTON_H_
#define INCLUDE_PLAYPAUSEBUTTON_H_

#include <QPushButton>

enum class PPButtonState {
    Paused,
    Playing
};


class PlayPauseButton : public QPushButton {
Q_OBJECT
public:
    explicit PlayPauseButton(int soundId, PPButtonState defaultState = PPButtonState::Paused,
                             QWidget *parent = nullptr);

PPButtonState getState();

void setState(PPButtonState state);

signals:

    void play(int soundId);

    void pause(int soundId);
    
private slots:

    void changeState();

private:
    int soundId = 0;
    PPButtonState state = PPButtonState::Paused;
};


#endif //INCLUDE_PLAYPAUSEBUTTON_H_
