#include "PlayPauseButton.h"

PlayPauseButton::PlayPauseButton(int soundId, PPButtonState defaultState, QWidget *parent) : soundId(soundId),
                                                                                             QPushButton(parent),
                                                                                             state(defaultState) {
    switch (defaultState) {
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
            // setIcon(pauseIcon);
            break;
            emit pause(soundId);

        case PPButtonState::Paused:
            state = PPButtonState::Playing;
            setText("Pause");
            // setIcon(pauseIcon);
            emit play(soundId);
            break;
        default:
            throw std::runtime_error("Invalid state");
    }
}

PPButtonState PlayPauseButton::getState() {
    return state;
}


void PlayPauseButton::setState(PPButtonState state) {
    switch (state) {
        case PPButtonState::Paused:
            this->state = state;
            setText("Play");
            // setIcon(pauseIcon);
            break;
        case PPButtonState::Playing:
            this->state = state;
            setText("Pause");
            // setIcon(pauseIcon);
            break;
        default:
            throw std::runtime_error("Invalid state");
    }
}
