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
    QGroupBox *groupBox = nullptr;
    QWidget *layoutWidget = nullptr;
    QVBoxLayout *verticalLayout_2 = nullptr;
    QVBoxLayout *verticalLayout = nullptr;
    QGridLayout *gridLayout = nullptr;
    QLabel *label = nullptr;
    QLineEdit *login = nullptr;
    QGridLayout *gridLayout_2 = nullptr;
    QLineEdit *pass = nullptr;
    QLabel *label_2 = nullptr;
    QHBoxLayout *horizontalLayout_3 = nullptr;
    QLabel *label_3 = nullptr;
    QLineEdit *pass_repeat = nullptr;
    QPushButton *signupButton = nullptr;
    QPushButton *backButton = nullptr;
    
    void setupUi(QDialog *SignUpDialog);

    void retranslateUi(QDialog *SignUpDialog);
};

#endif // SIGN_UP_DIALOG_H
