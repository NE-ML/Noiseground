#include "UserWindow.h"

#include <QMenuBar>
#include <QStatusBar>
#include <QApplication>

#include "Core.h"

UserWindow::UserWindow(QWidget *parent) : QMainWindow(parent) {
    Core::downloadStdSounds();
    std::vector<std::string> soundsTmp = Core::getStdSounds();
    std::for_each(soundsTmp.begin(), soundsTmp.end(), [this](const std::string &soundName) {
        unsigned dotPos = soundName.rfind('.');
        soundNames.push_back("<html><head/><body><p align=\"center\">" + soundName.substr(0, dotPos + 1) + 
        "</p></body></html>");
    });

    if (this->objectName().isEmpty()) {
        this->setObjectName(QString::fromUtf8("UserWindow"));
    }
    this->resize(800, 600);
    centralwidget = new QWidget(this);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    gridLayout_2 = new QGridLayout(centralwidget);
    gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));

    backButton = new QPushButton(centralwidget);
    backButton->setText("Выйти");
    backButton->setObjectName(QString::fromUtf8("backButton"));
    QSizePolicy szPolicy;
    szPolicy.setHeightForWidth(backButton->sizePolicy().hasHeightForWidth());
    backButton->setSizePolicy(szPolicy);

    auto horizLayout = new QHBoxLayout();
    
    horizLayout->addWidget(backButton, 0, Qt::AlignRight);
    
    gridLayout_2->addLayout(horizLayout, 0, 0, 1, 1);
    
    scrollArea = new QScrollArea(centralwidget);
    scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
    scrollArea->setMinimumSize(QSize(20, 20));
    scrollArea->setWidgetResizable(true);
    scrollAreaWidgetContents = new QWidget();
    scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
    scrollAreaWidgetContents->setGeometry(QRect(0, 0, 816, 496));
    gridLayout = new QGridLayout(scrollAreaWidgetContents);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

    for (int i = 0; i < soundNames.size(); ++i) {
        soundBoxes.push_back(new SoundBox(std::make_pair(i + 1, soundNames[i])));
        gridLayout->addWidget(soundBoxes[i], i / 4, i % 4, 1, 1);
    }
    scrollArea->setWidget(scrollAreaWidgetContents);

    gridLayout_2->addWidget(scrollArea, 1, 0, 1, 1);

    this->setCentralWidget(centralwidget);
    connect(backButton, &QPushButton::clicked, this, &UserWindow::onBackButtonClicked);
}

void UserWindow::onBackButtonClicked() {
    close();
    emit logout();
}
