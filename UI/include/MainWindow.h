#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

#include "AuthDialog.h"
#include "SignUpDialog.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    
    SignUpDialog *getSignUpDialog();

private slots:
    void on_Exit_clicked();

    void on_Login_clicked();

    void on_SignUp_clicked();

private:
    AuthDialog *auth = nullptr;
    SignUpDialog *signupButton = nullptr;
    QWidget *centralwidget = nullptr;
    QVBoxLayout *verticalLayout = nullptr;
    QLabel *label = nullptr;
    QPushButton *Login = nullptr;
    QSpacerItem *horizontalSpacer = nullptr;
    QPushButton *SignUp = nullptr;
    QSpacerItem *horizontalSpacer_2 = nullptr;
    QPushButton *Exit = nullptr;
    QMenuBar *menubar = nullptr;
    QStatusBar *statusbar = nullptr;
    
    void setupUi(QMainWindow *MainWindow);

    void retranslateUi(QMainWindow *MainWindow);

    friend class UIManager;
};
#endif // MAINWINDOW_H
