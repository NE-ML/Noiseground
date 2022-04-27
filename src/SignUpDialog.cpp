#include "SignUpDialog.h"

#include <QCoreApplication>
#include <QPushButton>

SignUpDialog::SignUpDialog(QWidget *parent) : QDialog(parent) {
    setupUi(this);
}

SignUpDialog::~SignUpDialog() {
    delete groupBox;
    delete layoutWidget;
    delete verticalLayout;
    delete verticalLayout_2;
    delete gridLayout;
    delete gridLayout_2;
    delete label;
    delete label_2;
    delete label_3;
    delete pass;
    delete pass_repeat;
    delete login;
    delete signupButton;
}

void SignUpDialog::on_signup_clicked() {
    QString log = login->text();
    QString pass = this->pass->text();
    QString pass_repeat = this->pass_repeat->text();
    // Some logic then
}

void SignUpDialog::retranslateUi(QDialog *SignUpDialog) {
    SignUpDialog->setWindowTitle(QCoreApplication::translate("SignUpDialog", "Dialog", nullptr));
    groupBox->setTitle(QCoreApplication::translate("SignUpDialog", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
    label->setText(QCoreApplication::translate("SignUpDialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\273\320\276\320\263\320\270\320\275", nullptr));
    label_2->setText(QCoreApplication::translate("SignUpDialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
    label_3->setText(QCoreApplication::translate("SignUpDialog", "\320\237\320\276\320\262\321\202\320\276\321\200\320\270\321\202\320\265 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
    signupButton->setText(QCoreApplication::translate("SignUpDialog", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
    backButton->setText(QCoreApplication::translate("SignUpDialog", "Назад", nullptr));
}

void SignUpDialog::setupUi(QDialog *SignUpDialog) {
    if (SignUpDialog->objectName().isEmpty())
        SignUpDialog->setObjectName(QString::fromUtf8("SignUpDialog"));
    SignUpDialog->resize(400, 300);
    groupBox = new QGroupBox(SignUpDialog);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    groupBox->setGeometry(QRect(50, 60, 305, 168));
    layoutWidget = new QWidget(groupBox);
    layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
    layoutWidget->setGeometry(QRect(10, 20, 285, 128));
    verticalLayout_2 = new QVBoxLayout(layoutWidget);
    verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
    verticalLayout_2->setContentsMargins(0, 0, 0, 0);
    verticalLayout = new QVBoxLayout();
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    gridLayout = new QGridLayout();
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    label = new QLabel(layoutWidget);
    label->setObjectName(QString::fromUtf8("label"));

    gridLayout->addWidget(label, 0, 0, 1, 1);

    login = new QLineEdit(layoutWidget);
    login->setObjectName(QString::fromUtf8("login"));

    gridLayout->addWidget(login, 0, 1, 1, 1);


    verticalLayout->addLayout(gridLayout);

    gridLayout_2 = new QGridLayout();
    gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
    pass = new QLineEdit(layoutWidget);
    pass->setObjectName(QString::fromUtf8("pass"));

    gridLayout_2->addWidget(pass, 0, 1, 1, 1);

    label_2 = new QLabel(layoutWidget);
    label_2->setObjectName(QString::fromUtf8("label_2"));

    gridLayout_2->addWidget(label_2, 0, 0, 1, 1);


    verticalLayout->addLayout(gridLayout_2);

    horizontalLayout_3 = new QHBoxLayout();
    horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
    label_3 = new QLabel(layoutWidget);
    label_3->setObjectName(QString::fromUtf8("label_3"));

    horizontalLayout_3->addWidget(label_3);

    pass_repeat = new QLineEdit(layoutWidget);
    pass_repeat->setObjectName(QString::fromUtf8("pass_repeat"));

    horizontalLayout_3->addWidget(pass_repeat);


    verticalLayout->addLayout(horizontalLayout_3);


    verticalLayout_2->addLayout(verticalLayout);

    signupButton = new QPushButton(layoutWidget);
    signupButton->setObjectName(QString::fromUtf8("signupButton"));

    verticalLayout_2->addWidget(signupButton);

    backButton = new QPushButton(layoutWidget);
    backButton->setObjectName(QString::fromUtf8("backButton"));
    
    verticalLayout_2->addWidget(backButton);

    retranslateUi(SignUpDialog);

    QMetaObject::connectSlotsByName(SignUpDialog);
}

void SignUpDialog::on_backButton_clicked() {
    close();
    emit showMainWindow();
}
// setupUi
