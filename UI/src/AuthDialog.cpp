#include "AuthDialog.h"

#include <QPushButton>
#include <QApplication>
#include <QMessageBox>

#include "Core.h"

AuthDialog::AuthDialog(QWidget *parent) : QDialog(parent) {
    setupUi(this);
}

AuthDialog::~AuthDialog() {
}

void AuthDialog::on_loginButton_clicked() {
    std::string log = login->text().toStdString();
    std::string pass = password->text().toStdString();
    if (log.empty() || pass.empty()) {
        QMessageBox::warning(this, "Ошибка авторизации", "Логин и пароль не могут быть пустыми");
        return;
    }
    unsigned result = Core::login(log, pass);
    switch (result) {
        case 200:
            this->close();
            emit showUserWindow();
            break;
        case 403:
            QMessageBox::warning(this, "Ошибка авторизации","Неправильный логин или пароль");
            break;
        default:
            QMessageBox::critical(this, "Авторизация невозможна", "Нет соединения с сервером");
    }
}

void AuthDialog::setupUi(QDialog *AuthDialog) {
    if (AuthDialog->objectName().isEmpty())
        AuthDialog->setObjectName(QString::fromUtf8("AuthDialog"));
    AuthDialog->resize(400, 300);
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    groupBox = new QGroupBox(AuthDialog);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    groupBox->setEnabled(true);
    groupBox->setGeometry(QRect(75, 50, 250, 190));
    groupBox->setAlignment(Qt::AlignCenter);
    layoutWidget = new QWidget(groupBox);
    layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
    layoutWidget->setGeometry(QRect(21, 32, 210, 140));
    verticalLayout = new QVBoxLayout(layoutWidget);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    verticalLayout->setContentsMargins(0, 0, 0, 0);
    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    loginLabel = new QLabel(layoutWidget);
    loginLabel->setObjectName(QString::fromUtf8("loginLabel"));

    horizontalLayout->addWidget(loginLabel);

    login = new QLineEdit(layoutWidget);
    login->setObjectName(QString::fromUtf8("login"));

    horizontalLayout->addWidget(login);


    verticalLayout->addLayout(horizontalLayout);

    horizontalLayout_2 = new QHBoxLayout();
    horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
    passwordLabel = new QLabel(layoutWidget);
    passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));

    horizontalLayout_2->addWidget(passwordLabel);

    password = new QLineEdit(layoutWidget);
    password->setObjectName(QString::fromUtf8("password"));
    password->setEchoMode(QLineEdit::Password);

    horizontalLayout_2->addWidget(password);


    verticalLayout->addLayout(horizontalLayout_2);

    loginButton = new QPushButton(layoutWidget);
    loginButton->setObjectName(QString::fromUtf8("loginButton"));

    verticalLayout->addWidget(loginButton);

    backButton = new QPushButton(layoutWidget);
    backButton->setObjectName(QString::fromUtf8("backButton"));

    verticalLayout->addWidget(backButton);

    setTexts(AuthDialog);

    QMetaObject::connectSlotsByName(AuthDialog);
} // setupUi

void AuthDialog::setTexts(QDialog *AuthDialog) {
    AuthDialog->setWindowTitle("Вход");
    groupBox->setTitle("Авторизация");
    loginLabel->setText("Логин");
    passwordLabel->setText("Пароль");
    loginButton->setText("Войти");
    backButton->setText("Назад");
}

void AuthDialog::on_backButton_clicked() {
    close();
    emit showMainWindow();
}
