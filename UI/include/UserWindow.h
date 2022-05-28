#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QMainWindow>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSlider>
#include <QScrollArea>
#include "SoundBox.h"

/*QT_BEGIN_NAMESPACE
namespace Ui {
    class UserWindow;
}
QT_END_NAMESPACE*/

class UserWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit UserWindow(QWidget *parent = nullptr);
    ~UserWindow() override = default;

signals:
    void logout();
    
private slots:    
    void onBackButtonClicked();
    
private:
    
    std::vector<std::string> soundNames;
    
    std::vector<SoundBox *> soundBoxes;
    QPushButton *backButton = nullptr;
    
    QScrollArea *scrollArea = nullptr;
    QWidget *scrollAreaWidgetContents = nullptr;
    
    QGridLayout *gridLayout = nullptr;
    QGridLayout *gridLayout_2 = nullptr;
    
    QWidget *centralwidget = nullptr;
};

#endif // USERWINDOW_H
