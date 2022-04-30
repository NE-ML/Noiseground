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
    ~SignUpDialog() override;

signals:
    void showMainWindow();
    void showUserWindow();
    
private slots:
    void on_signupButton_clicked();
    void on_backButton_clicked();
    
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
    QPushButton *signupButton;
    QPushButton *backButton;
    
    void setupUi(QDialog *SignUpDialog);

    void retranslateUi(QDialog *SignUpDialog);
};

#endif // SIGN_UP_DIALOG_H
