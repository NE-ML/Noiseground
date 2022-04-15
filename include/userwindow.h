#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QMainWindow>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSlider>

QT_BEGIN_NAMESPACE
namespace Ui {
    class UserWindow;
}
QT_END_NAMESPACE

class UserWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit UserWindow(QWidget *parent = nullptr);
    ~UserWindow();

private slots:
    void on_playButton_clicked();

private:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *playButton;
    QSlider *volumeSlider;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *UserWindow);

    void retranslateUi(QMainWindow *UserWindow);
};

#endif // USERWINDOW_H
