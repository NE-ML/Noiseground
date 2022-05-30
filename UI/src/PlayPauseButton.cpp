#include "PlayPauseButton.h"

PlayPauseButton::PlayPauseButton(int soundId, PPButtonState defaultState, QWidget *parent) : soundId(soundId),
                                                                                             QPushButton(parent),
                                                                                             state(defaultState) {
    switch(defaultState) {
        case PPButtonState::Paused:
            setText("Play");
            break;
        case PPButtonState::Playing:
            setText("Pause");
            break;
        default:
            setText("WrongState");
    }

    connect(this, &QAbstractButton::clicked, this, &PlayPauseButton::changeState);
}

void PlayPauseButton::changeState() {
    switch (state) {
        case PPButtonState::Playing:
            state = PPButtonState::Paused;
            setText("Play");
            emit pause(soundId);
            break;
            
        case PPButtonState::Paused:
            state = PPButtonState::Playing;
            setText("Pause");
            emit play(soundId);
            break;
        default:
            setText("Wrong state");
    }
}

PPButtonState PlayPauseButton::getState() {
    return state;
}


void PlayPauseButton::setState(PPButtonState newState) {
    switch (newState) {
        case PPButtonState::Paused:
            this->state = newState;
            setText("Play");
            break;
        case PPButtonState::Playing:
            this->state = newState;
            setText("Pause");
            break;
        default:
            setText("Wrong newState");
    }
}
