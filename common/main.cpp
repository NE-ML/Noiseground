#include <QApplication>

#include "UIManager.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    UIManager uiManager;
    uiManager.showMainWindow();
    return a.exec();
}
