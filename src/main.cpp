#include "mainwindow.h"
#include "userwindow.h"

#include <QApplication>

#include "UIManager.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    UIManager uiManager;
    uiManager.showUserWindow();
    uiManager.showMainWindow();
    return a.exec();
}
