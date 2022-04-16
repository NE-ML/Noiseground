#ifndef SIGN_UP_DIALOG_H
#define SIGN_UP_DIALOG_H

#include <QDialog>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>

class SignUpDialog : public QDialog {
    Q_OBJECT

public:
    explicit SignUpDialog(QWidget *parent = nullptr);
    ~SignUpDialog();

private slots:
    void on_signup_clicked();
    
private:
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *login;
    QGridLayout *gridLayout_2;
    QLineEdit *pass;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *pass_repeat;
    QPushButton *signup;

    void setupUi(QDialog *SignUpDialog);

    void retranslateUi(QDialog *SignUpDialog);
};

#endif // SIGN_UP_DIALOG_H
