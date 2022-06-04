#include "SignUpDialog.h"

#include <QCoreApplication>
#include <QPushButton>
#include <QMessageBox>

#include "Core.h"

SignUpDialog::SignUpDialog(QWidget *parent) : QDialog(parent) {
    setupUi(this);
}

SignUpDialog::~SignUpDialog() {
}

void SignUpDialog::on_signUpButton_clicked() {
    QString log = login->text();
    QString pass = this->pass->text();
    QString passRepeat = this->passRepeat->text();
    if (pass == passRepeat && !log.isEmpty()) {
        unsigned response = Core::signUp(log.toStdString(), pass.toStdString());
        switch (response) {
            case 200:
                QMessageBox::information(this, "Успех!", "Вы успешно зарегистрированы!");
                close();
                emit showUserWindow();
                break;
            case 403:
                QMessageBox::warning(this, "Регистрация невозможна", "Логин уже занят!");
                break;
            default:
                QMessageBox::critical(this, "Регистрация невозможна!", "Нет соединения с сервером!");
        }

    } else if (log.isEmpty()) {
        QMessageBox::warning(this, "Ошибка!", "Логин не может быть пустым!");
    } else {
        QMessageBox::warning(this, "Ошибка!", "Пароли не совпадают!");
    }
}

void SignUpDialog::retranslateUi(QDialog *SignUpDialog) {
    SignUpDialog->setWindowTitle("Регистрация");
    groupBox->setTitle("Регистрация");
    enterLoginLabel->setText("Введите логин");
    enterPasswordLabel->setText("Введите пароль");
    repeatPasswordLabel->setText("Повторите пароль");
    signUpButton->setText("Зарегистрироваться");
    backButton->setText("Назад");
}

void SignUpDialog::setupUi(QDialog *SignUpDialog) {
    if (SignUpDialog->objectName().isEmpty())
        SignUpDialog->setObjectName(QString::fromUtf8("SignUpDialog"));
    SignUpDialog->resize(400, 300);
    groupBox = new QGroupBox(SignUpDialog);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    groupBox->setGeometry(QRect(45, 50, 310, 200));
    layoutWidget = new QWidget(groupBox);
    layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
    layoutWidget->setGeometry(QRect(10, 30, 290, 160));
    verticalLayout_2 = new QVBoxLayout(layoutWidget);
    verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
    verticalLayout_2->setContentsMargins(5, 5, 5, 5);
    verticalLayout = new QVBoxLayout();
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    gridLayout = new QGridLayout();
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    enterLoginLabel = new QLabel(layoutWidget);
    enterLoginLabel->setObjectName(QString::fromUtf8("enterLoginLabel"));

    gridLayout->addWidget(enterLoginLabel, 0, 0, 1, 1);

    login = new QLineEdit(layoutWidget);
    login->setObjectName(QString::fromUtf8("login"));

    gridLayout->addWidget(login, 0, 1, 1, 1);


    verticalLayout->addLayout(gridLayout);

    gridLayout_2 = new QGridLayout();
    gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
    pass = new QLineEdit(layoutWidget);
    pass->setObjectName(QString::fromUtf8("pass"));
    pass->setEchoMode(QLineEdit::Password);

    gridLayout_2->addWidget(pass, 0, 1, 1, 1);

    enterPasswordLabel = new QLabel(layoutWidget);
    enterPasswordLabel->setObjectName(QString::fromUtf8("enterPasswordLabel"));

    gridLayout_2->addWidget(enterPasswordLabel, 0, 0, 1, 1);


    verticalLayout->addLayout(gridLayout_2);

    horizontalLayout_3 = new QHBoxLayout();
    horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
    repeatPasswordLabel = new QLabel(layoutWidget);
    repeatPasswordLabel->setObjectName(QString::fromUtf8("repeatPasswordLabel"));

    horizontalLayout_3->addWidget(repeatPasswordLabel);

    passRepeat = new QLineEdit(layoutWidget);
    passRepeat->setObjectName(QString::fromUtf8("passRepeat"));
    passRepeat->setEchoMode(QLineEdit::Password);

    horizontalLayout_3->addWidget(passRepeat);


    verticalLayout->addLayout(horizontalLayout_3);


    verticalLayout_2->addLayout(verticalLayout);

    signUpButton = new QPushButton(layoutWidget);
    signUpButton->setObjectName(QString::fromUtf8("signUpDialog"));

    verticalLayout_2->addWidget(signUpButton);

    backButton = new QPushButton(layoutWidget);
    backButton->setObjectName(QString::fromUtf8("backButton"));

    verticalLayout_2->addWidget(backButton);

    retranslateUi(SignUpDialog);

    connect(signUpButton, &QPushButton::clicked, this, &SignUpDialog::on_signUpButton_clicked);
    connect(backButton, &QPushButton::clicked, this, &SignUpDialog::on_backButton_clicked);
}

void SignUpDialog::on_backButton_clicked() {
    close();
    emit showMainWindow();
}
// setupUi
