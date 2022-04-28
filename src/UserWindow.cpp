#include "UserWindow.h"

#include <QMenuBar>
#include <QStatusBar>
#include <QApplication>

UserWindow::UserWindow(QWidget *parent) : QMainWindow(parent) {
    setupUi(this);
}

UserWindow::~UserWindow()
{
    delete centralwidget;
}

void UserWindow::on_playButton_clicked()
{

}

void UserWindow::setupUi(QMainWindow *UserWindow) {
    if (UserWindow->objectName().isEmpty())
        UserWindow->setObjectName(QString::fromUtf8("UserWindow"));
    UserWindow->resize(800, 600);
    centralwidget = new QWidget(UserWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    groupBox = new QGroupBox(centralwidget);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    groupBox->setGeometry(QRect(130, 100, 111, 101));
    widget = new QWidget(groupBox);
    widget->setObjectName(QString::fromUtf8("widget"));
    widget->setGeometry(QRect(10, 30, 91, 48));
    verticalLayout = new QVBoxLayout(widget);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    verticalLayout->setContentsMargins(0, 0, 0, 0);
    playButton = new QPushButton(widget);
    playButton->setObjectName(QString::fromUtf8("playButton"));

    verticalLayout->addWidget(playButton);

    volumeSlider = new QSlider(widget);
    volumeSlider->setObjectName(QString::fromUtf8("volumeSlider"));
    volumeSlider->setOrientation(Qt::Horizontal);

    verticalLayout->addWidget(volumeSlider);

    UserWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(UserWindow);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 800, 22));
    UserWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(UserWindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    UserWindow->setStatusBar(statusbar);

    retranslateUi(UserWindow);

    QMetaObject::connectSlotsByName(UserWindow);
} // setupUi

void UserWindow::retranslateUi(QMainWindow *UserWindow) {
    UserWindow->setWindowTitle(QCoreApplication::translate("UserWindow", "MainWindow", nullptr));
    groupBox->setTitle(QCoreApplication::translate("UserWindow", "GroupBox", nullptr));
    playButton->setText(QCoreApplication::translate("UserWindow", "Play", nullptr));
} // retranslateUi


