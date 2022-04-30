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

private slots:
    void on_Exit_clicked();

    void on_Login_clicked();

    void on_SignUp_clicked();

private:
    AuthDialog *auth;
    SignUpDialog *signupButton;
    
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *Login;
    QSpacerItem *horizontalSpacer;
    QPushButton *SignUp;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *Exit;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    
    void setupUi(QMainWindow *MainWindow);

    void retranslateUi(QMainWindow *MainWindow);

    friend class UIManager;
};
#endif // MAINWINDOW_H
