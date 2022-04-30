#ifndef INCLUDE_UIMANAGER_H_
#define INCLUDE_UIMANAGER_H_

#include "MainWindow.h"
#include "UserWindow.h"

class UIManager {
public:
    UIManager();
    ~UIManager() =  default;
    void showMainWindow();
    void showUserWindow();
private:
    MainWindow mainWindow;
    UserWindow userWindow;
};

#endif  // INCLUDE_UIMANAGER_H_
