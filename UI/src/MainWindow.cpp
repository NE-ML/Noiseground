#include "MainWindow.h"

#include <QMenuBar>
#include <QStatusBar>
#include <QApplication>
#include <QCoreApplication>
#include "AuthDialog.h"
#include"SignUpDialog.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setupUi(this);
    authDialog = std::make_shared<AuthDialog>();
    authDialog->setModal(true);
    connect(authDialog.get(), &AuthDialog::showMainWindow, this, &MainWindow::show);
    signUpDialog = std::make_shared<SignUpDialog>();
    signUpDialog->setModal(true);
    connect(signUpDialog.get(), &SignUpDialog::showMainWindow, this, &MainWindow::show);
    connect(signUpButton, &QPushButton::clicked, this, &MainWindow::onSignUpButtonClicked);
    connect(loginButton, &QPushButton::clicked, this, &MainWindow::onLoginButtonClicked);
    connect(exitButton, &QPushButton::clicked, this, &MainWindow::onExitButtonClicked);
}

MainWindow::~MainWindow() {
    delete centralwidget;
}

void MainWindow::setupUi(QMainWindow *MainWindow) {
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(800, 600);
    QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
    MainWindow->setSizePolicy(sizePolicy);
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    verticalLayout = new QVBoxLayout(centralwidget);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    label = new QLabel(centralwidget);
    label->setObjectName(QString::fromUtf8("label"));
    QFont font;
    font.setFamily(QString::fromUtf8("JetBrains Mono"));
    font.setPointSize(18);
    font.setBold(true);
    font.setItalic(true);
    font.setWeight(75);
    label->setFont(font);

    verticalLayout->addWidget(label, 0, Qt::AlignHCenter);

    loginButton = new QPushButton(centralwidget);
    loginButton->setObjectName(QString::fromUtf8("loginButton"));
    QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(loginButton->sizePolicy().hasHeightForWidth());
    loginButton->setSizePolicy(sizePolicy1);

    verticalLayout->addWidget(loginButton);

    horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    verticalLayout->addItem(horizontalSpacer);

    signUpButton = new QPushButton(centralwidget);
    signUpButton->setObjectName(QString::fromUtf8("signUpButton"));
    sizePolicy1.setHeightForWidth(signUpButton->sizePolicy().hasHeightForWidth());
    signUpButton->setSizePolicy(sizePolicy1);

    verticalLayout->addWidget(signUpButton);

    horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    verticalLayout->addItem(horizontalSpacer_2);

    exitButton = new QPushButton(centralwidget);
    exitButton->setObjectName(QString::fromUtf8("exitButton"));
    sizePolicy1.setHeightForWidth(exitButton->sizePolicy().hasHeightForWidth());
    exitButton->setSizePolicy(sizePolicy1);

    verticalLayout->addWidget(exitButton);

    MainWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(MainWindow);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 800, 22));
    MainWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    MainWindow->setStatusBar(statusbar);

    retranslateUi(MainWindow);
} // setupUi

void MainWindow::retranslateUi(QMainWindow *MainWindow) {
    MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
    label->setText(QCoreApplication::translate("MainWindow",
                                               "<html><head/><body><p align=\"center\"><span style=\" color:#1c71d8;"
                                               "\">Добро пожаловать в Noiseground!</span></p></body></html>",
                                               nullptr));
    loginButton->setText(QCoreApplication::translate("MainWindow", "Войти", nullptr));
    signUpButton->setText(QCoreApplication::translate("MainWindow", "Зарегистрироваться", nullptr));
    exitButton->setText(QCoreApplication::translate("MainWindow", "Выйти", nullptr));
}

void MainWindow::onExitButtonClicked() {
    QApplication::quit();
}

void MainWindow::onLoginButtonClicked() {
    hide();
    authDialog->exec();
}


void MainWindow::onSignUpButtonClicked() {
    hide();
    signUpDialog->exec();
}

std::shared_ptr<SignUpDialog> MainWindow::getSignUpDialog() {
    return signUpDialog;
}

std::shared_ptr<AuthDialog> MainWindow::getAuthDialog() {
    return authDialog;
}
