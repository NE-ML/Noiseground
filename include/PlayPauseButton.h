#ifndef INCLUDE_PLAYPAUSEBUTTON_H_
#define INCLUDE_PLAYPAUSEBUTTON_H_

#include <QPushButton>

enum class PPButtonState {
    Paused,
    Playing
};



class PlayPauseButton : QPushButton {
Q_OBJECT
public:
    explicit PlayPauseButton(PPButtonState defaultState = PPButtonState::Paused, QWidget *parent = nullptr);

     
signals:
    
private slots:
    void changeState();
private:
    PPButtonState state;
};


#endif //INCLUDE_PLAYPAUSEBUTTON_H_
