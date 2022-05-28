#include <QApplication>
#include <QFile>

#include "UIManager.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QFile file("../UI/style/style.css");
    file.open(QFile::ReadOnly);
    a.setStyleSheet(file.readAll());
    UIManager uiManager;
    uiManager.showMainWindow();
    return a.exec();
}
