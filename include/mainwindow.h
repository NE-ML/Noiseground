#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setupUi(QMainWindow *MainWindow);

    void retranslateUi(QMainWindow *MainWindow);

private slots:
    void on_Exit_clicked();

    void on_Login_clicked();

    void on_SignUp_clicked();

private:
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
};
#endif // MAINWINDOW_H
