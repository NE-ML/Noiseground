#ifndef AUTH_DIALOG_H
#define AUTH_DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QLineEdit>

class AuthDialog : public QDialog {
    Q_OBJECT

public:
    explicit AuthDialog(QWidget *parent = nullptr);
    ~AuthDialog();

signals:
    void showMainWindow();

private slots:
    void on_loginButton_clicked();
    void on_backButton_clicked();

private:
    QLabel *label;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *login;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *password;
    QPushButton *loginButton;
    QPushButton *backButton;
    
    void setupUi(QDialog *AuthDialog);

    void retranslateUi(QDialog *AuthDialog);
};

#endif // AUTH_DIALOG_H
