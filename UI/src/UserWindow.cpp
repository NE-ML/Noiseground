#include "UserWindow.h"

#include <QMenuBar>
#include <QStatusBar>
#include <QApplication>

UserWindow::UserWindow(QWidget *parent) : QMainWindow(parent) {

    for (int i = 0; i < 20; ++i) {
        soundNames.push_back(QString::fromStdString("<html><head/><body><p align=\"center\">Audio" +
                                                    std::to_string(i + 1)) + "</p></body></html>");
    }

    if (this->objectName().isEmpty())
        this->setObjectName(QString::fromUtf8("UserWindow"));
    this->resize(800, 600);
    centralwidget = new QWidget(this);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    gridLayout_2 = new QGridLayout(centralwidget);
    gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
    scrollArea = new QScrollArea(centralwidget);
    scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
    scrollArea->setMinimumSize(QSize(20, 20));
    scrollArea->setWidgetResizable(true);
    scrollAreaWidgetContents = new QWidget();
    scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
    scrollAreaWidgetContents->setGeometry(QRect(0, 0, 816, 496));
    gridLayout = new QGridLayout(scrollAreaWidgetContents);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

    for (int i = 0; i < 20; ++i) {
        soundBoxes.push_back(new SoundBox(std::make_pair(i + 1, "Test" + std::to_string(i))));

        gridLayout->addWidget(soundBoxes[i], i / 4, i % 4, 1, 1);
    }
    scrollArea->setWidget(scrollAreaWidgetContents);

    gridLayout_2->addWidget(scrollArea, 0, 0, 1, 1);

    this->setCentralWidget(centralwidget);
    //QMetaObject::connectSlotsByName(this);
}

UserWindow::~UserWindow() {
    //delete scrollArea;
}

void UserWindow::on_playButton_clicked() {

}

void UserWindow::on_logoutButton_clicked() {
    close();
    emit logout();
}
