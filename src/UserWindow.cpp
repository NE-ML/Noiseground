#include "UserWindow.h"

#include <QMenuBar>
#include <QStatusBar>
#include <QApplication>
#include <QLabel>

UserWindow::UserWindow(QWidget *parent) : QMainWindow(parent) {
    // setupUi(this);
    
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
        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(150, 150));
        groupBox->setBaseSize(QSize(0, 0));
        
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(10, 10, 10, 10);

        auto label = new QLabel(groupBox);
        label->setObjectName("soundNameLabel");
        label->setText(soundNames[i]);
        
        verticalLayout->addWidget(label);
        
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setText("Play");

        verticalLayout->addWidget(pushButton);

        volumeSlider = new QSlider(widget);
        volumeSlider->setObjectName(QString::fromUtf8("volumeSlider"));
        volumeSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(volumeSlider);
        
        gridLayout->addWidget(groupBox, i / 4, i % 4, 1, 1);
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

void UserWindow::setupUi(QMainWindow *UserWindow) {
    /*if (UserWindow->objectName().isEmpty())
        UserWindow->setObjectName(QString::fromUtf8("UserWindow"));
    UserWindow->resize(800, 600);   
    scrollArea = new QScrollArea(UserWindow);
    scrollArea->setObjectName(QString::fromUtf8("scrollarea"));
    groupBox = new QGroupBox(scrollArea);
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
    
    UserWindow->setCentralWidget(scrollArea);
    menubar = new QMenuBar(UserWindow);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 800, 22));
    UserWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(UserWindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    UserWindow->setStatusBar(statusbar);

    logoutButton = new QPushButton(scrollArea);
    logoutButton->setObjectName(QString::fromUtf8("logoutButton"));

    retranslateUi(UserWindow);

    QMetaObject::connectSlotsByName(UserWindow); */
} // setupUi

void UserWindow::retranslateUi(QMainWindow *UserWindow) {
    /* UserWindow->setWindowTitle(QCoreApplication::translate("UserWindow", "MainWindow", nullptr));
    groupBox->setTitle(QCoreApplication::translate("UserWindow", "AudioName", nullptr));
    playButton->setText(QCoreApplication::translate("UserWindow", "Play", nullptr));
    logoutButton->setText(QCoreApplication::translate("UserWindow", "Logout", nullptr));
     */
}

void UserWindow::on_logoutButton_clicked() {
    close();
    emit logout();
}

void UserWindow::drawSounds(const std::vector<std::string> &soundNames) {

}
// retranslateUi
