#include "SoundBox.h"

#include <QVBoxLayout>
#include <QLabel>

#include "Core.h"
#include "PlayPauseButton.h"

SoundBox::SoundBox(const std::pair<int, std::string> &data) : QGroupBox(), id(data.first), name(data.second) {
    setObjectName(QString::fromStdString(data.second + "GroupBox"));
    setEnabled(true);
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(this->sizePolicy().hasHeightForWidth());
    setSizePolicy(sizePolicy);
    setMinimumSize(QSize(150, 150));
    setBaseSize(QSize(0, 0));

    auto verticalLayout = new QVBoxLayout(this);
    verticalLayout->setObjectName(QString::fromStdString(data.second + "VerticalLayout"));
    verticalLayout->setContentsMargins(10, 10, 10, 10);

    auto label = new QLabel(this);
    label->setObjectName("soundNameLabel");
    label->setText(QString::fromStdString("<html><head/><body><p align=\"center\">Audio" + data.second +
                                          "</p></body></html>"));

    playPauseButton = new PlayPauseButton(data.first, PPButtonState::Paused, this);
    playPauseButton->setObjectName(QString::fromStdString(data.second + "PlayPauseButton"));

    verticalLayout->addWidget(playPauseButton);

    verticalLayout->addWidget(label);

    volumeSlider = new QSlider(this);
    volumeSlider->setObjectName(QString::fromStdString(data.second + "VolumeSlider"));
    volumeSlider->setOrientation(Qt::Horizontal);

    verticalLayout->addWidget(volumeSlider);

    QObject::connect(volumeSlider, &QSlider::valueChanged, this, &SoundBox::volumeChanged);
    connect(playPauseButton, &PlayPauseButton::play, this, &SoundBox::play);
    connect(playPauseButton, &PlayPauseButton::pause, this, &SoundBox::pause);
}

void SoundBox::volumeChanged(int value) {
    if (playPauseButton->getState() == PPButtonState::Playing) {
        Core::changeVolume(id, value);
    }
}

void SoundBox::play(int soundId) {
    if (volumeSlider->value() > 0) {
        Core::play(soundId, volumeSlider->value());
    } else {
        playPauseButton->setState(PPButtonState::Paused);
    }
}

void SoundBox::pause(int soundId) {
    Core::pause(soundId);
}
