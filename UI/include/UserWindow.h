#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QMainWindow>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSlider>
#include <QScrollArea>

#include "SoundBox.h"

class UserWindow : public QMainWindow {
Q_OBJECT

public:
    explicit UserWindow(QWidget *parent = nullptr);

    ~UserWindow() override;

signals:

    void logout();

private slots:

    void on_playButton_clicked();

    void on_logoutButton_clicked();

private:
    std::vector<QString> soundNames;

    std::vector<SoundBox *> soundBoxes;
    QWidget *widget = nullptr;
    QVBoxLayout *verticalLayout = nullptr;
    QPushButton *playButton = nullptr;
    QSlider *volumeSlider = nullptr;
    QMenuBar *menubar = nullptr;
    QStatusBar *statusbar = nullptr;
    QPushButton *logoutButton = nullptr;

    QScrollArea *scrollArea = nullptr;
    QWidget *scrollAreaWidgetContents = nullptr;

    QGridLayout *gridLayout = nullptr;
    QGridLayout *gridLayout_2 = nullptr;

    QWidget *centralwidget = nullptr;

    QPushButton *pushButton = nullptr;
};

#endif // USERWINDOW_H
