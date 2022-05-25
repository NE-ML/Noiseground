#include "UIManager.h"
#include "MainWindow.h"
#include "UserWindow.h"
#include "SignUpDialog.h"

void UIManager::showMainWindow() {
    mainWindow.show();
}

void UIManager::showUserWindow() {
    userWindow.show();
}

UIManager::UIManager() {
    QObject::connect(mainWindow.getSignUpDialog().get(), &SignUpDialog::showUserWindow, &userWindow, &UserWindow::show);
    QObject::connect(&userWindow, &UserWindow::logout, &mainWindow, &MainWindow::show);
}
