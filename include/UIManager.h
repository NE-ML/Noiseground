#ifndef INCLUDE_UIMANAGER_H_
#define INCLUDE_UIMANAGER_H_

#include "mainwindow.h"
#include "userwindow.h"

class UIManager {
public:
    UIManager() = default;
    ~UIManager() =  default;
    void showMainWindow();
    void showUserWindow();
private:
    MainWindow mainWindow;
    UserWindow userWindow;
};

#endif  // INCLUDE_UIMANAGER_H_
