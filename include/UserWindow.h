#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QMainWindow>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSlider>
#include <QScrollArea>

/*QT_BEGIN_NAMESPACE
namespace Ui {
    class UserWindow;
}
QT_END_NAMESPACE*/

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
    void drawSounds(const std::vector<std::string> &soundNames);
    
    std::vector<QString> soundNames;
    
    QGroupBox *groupBox = nullptr;
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

    void setupUi(QMainWindow *UserWindow);

    void retranslateUi(QMainWindow *UserWindow);
    
    friend class UIManager;
};

#endif // USERWINDOW_H
