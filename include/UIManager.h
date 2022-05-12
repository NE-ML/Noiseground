#ifndef INCLUDE_UIMANAGER_H_
#define INCLUDE_UIMANAGER_H_

#include "MainWindow.h"
#include "UserWindow.h"

class UIManager {
public:
    UIManager();
    ~UIManager() = default;
    void showMainWindow();
    void showUserWindow();
    void playSound();
    void getSounds();  //  Loads list of sounds to be played
    /*
     * 5 sounds:
     * S1->name S2->name
     * S3 S4
     * S5
     * 
     * 6
     */
private:
    // TODO: @levbara
    MainWindow mainWindow; // Передавать в конструктор UIManager извне
    UserWindow userWindow;
};

#endif  // INCLUDE_UIMANAGER_H_
