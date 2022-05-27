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
            QMessageBox::warning(this, "Авторизация невозможна", "Нет соединения с сервером");
    }
}

void AuthDialog::setupUi(QDialog *AuthDialog) {
    if (AuthDialog->objectName().isEmpty())
        AuthDialog->setObjectName(QString::fromUtf8("AuthDialog"));
    AuthDialog->resize(400, 300);
    label = new QLabel(AuthDialog);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(0, 10, 401, 31));
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
    label->setSizePolicy(sizePolicy);
    QFont font;
    font.setFamily(QString::fromUtf8("JetBrains Mono NL"));
    font.setPointSize(14);
    font.setItalic(true);
    label->setFont(font);
    groupBox = new QGroupBox(AuthDialog);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    groupBox->setEnabled(true);
    groupBox->setGeometry(QRect(70, 80, 247, 188));
    groupBox->setAlignment(Qt::AlignCenter);
    layoutWidget = new QWidget(groupBox);
    layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
    layoutWidget->setGeometry(QRect(21, 32, 205, 124));
    verticalLayout = new QVBoxLayout(layoutWidget);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    verticalLayout->setContentsMargins(0, 0, 0, 0);
    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    label_2 = new QLabel(layoutWidget);
    label_2->setObjectName(QString::fromUtf8("label_2"));

    horizontalLayout->addWidget(label_2);

    login = new QLineEdit(layoutWidget);
    login->setObjectName(QString::fromUtf8("login"));

    horizontalLayout->addWidget(login);


    verticalLayout->addLayout(horizontalLayout);

    horizontalLayout_2 = new QHBoxLayout();
    horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
    label_3 = new QLabel(layoutWidget);
    label_3->setObjectName(QString::fromUtf8("label_3"));

    horizontalLayout_2->addWidget(label_3);

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

    retranslateUi(AuthDialog);

    QMetaObject::connectSlotsByName(AuthDialog);
} // setupUi

void AuthDialog::retranslateUi(QDialog *AuthDialog) {
    AuthDialog->setWindowTitle(QCoreApplication::translate("AuthDialog", "Dialog", nullptr));
    label->setText(QCoreApplication::translate("AuthDialog",
                                               "<html><head/><body><p align=\"center\">\320\236\320\272\320\275\320\276 \320\260\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\320\270</p></body></html>",
                                               nullptr));
    groupBox->setTitle(QCoreApplication::translate("AuthDialog",
                                                   "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217",
                                                   nullptr));
    label_2->setText(QCoreApplication::translate("AuthDialog", "\320\233\320\276\320\263\320\270\320\275", nullptr));
    label_3->setText(
            QCoreApplication::translate("AuthDialog", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
    loginButton->setText(
            QCoreApplication::translate("AuthDialog", "\320\222\320\276\320\271\321\202\320\270", nullptr));
    backButton->setText(QCoreApplication::translate("AuthDialog", "Назад", nullptr));
}

void AuthDialog::on_backButton_clicked() {
    close();
    emit showMainWindow();
}
// retranslateUi
