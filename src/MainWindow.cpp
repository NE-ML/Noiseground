#include "MainWindow.h"

#include <QMenuBar>
#include <QStatusBar>
#include <QApplication>
#include <QCoreApplication>
#include "AuthDialog.h"
#include"SignUpDialog.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setupUi(this);
    auth = new AuthDialog();
    auth->setModal(true);
    connect(auth, &AuthDialog::showMainWindow, this, &MainWindow::show);
    signupButton = new SignUpDialog();
    signupButton->setModal(true);
    connect(signupButton, &SignUpDialog::showMainWindow, this, &MainWindow::show);
    //connect(ui->AuthDialog::backButton, &QPushButton::clicked, this, &QMainWindow::show);
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

    Login = new QPushButton(centralwidget);
    Login->setObjectName(QString::fromUtf8("Login"));
    QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(Login->sizePolicy().hasHeightForWidth());
    Login->setSizePolicy(sizePolicy1);

    verticalLayout->addWidget(Login);

    horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    verticalLayout->addItem(horizontalSpacer);

    SignUp = new QPushButton(centralwidget);
    SignUp->setObjectName(QString::fromUtf8("SignUp"));
    sizePolicy1.setHeightForWidth(SignUp->sizePolicy().hasHeightForWidth());
    SignUp->setSizePolicy(sizePolicy1);

    verticalLayout->addWidget(SignUp);

    horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    verticalLayout->addItem(horizontalSpacer_2);

    Exit = new QPushButton(centralwidget);
    Exit->setObjectName(QString::fromUtf8("Exit"));
    sizePolicy1.setHeightForWidth(Exit->sizePolicy().hasHeightForWidth());
    Exit->setSizePolicy(sizePolicy1);

    verticalLayout->addWidget(Exit);

    MainWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(MainWindow);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 800, 22));
    MainWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    MainWindow->setStatusBar(statusbar);

    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(MainWindow);
} // setupUi

void MainWindow::retranslateUi(QMainWindow *MainWindow) {
    MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
    label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" color:#1c71d8;\">Noiseground Login Page</span></p></body></html>", nullptr));
    Login->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
    SignUp->setText(QCoreApplication::translate("MainWindow", "Sign Up", nullptr));
    Exit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
}

void MainWindow::on_Exit_clicked() {
    QApplication::quit();
}

void MainWindow::on_Login_clicked() {
    hide();
    auth->exec();
}


void MainWindow::on_SignUp_clicked() {
    hide();
    signupButton->exec();
}
