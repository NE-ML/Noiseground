#include "mainwindow.h"
#include "userwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    UserWindow window;
    window.show();
    return a.exec();
}
