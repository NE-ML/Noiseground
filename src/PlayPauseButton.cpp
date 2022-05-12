#include "PlayPauseButton.h"

PlayPauseButton::PlayPauseButton(PPButtonState defaultState, QWidget *parent) : QPushButton(parent),
                                                                                state(defaultState) {
    
}

void PlayPauseButton::changeState() {
    switch (state) {
        case PPButtonState::Paused:
            // emit pause(soundName);
            state = PPButtonState::Playing;
            // changeIcon(pauseIcon);
            break;
        case PPButtonState::Playing:
            // emit play(soundName);
            state
    }
}
