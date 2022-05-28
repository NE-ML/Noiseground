#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "UIManager.h"

#include <QApplication>

TEST(ConstructorTest, MainWindow) {
    int fake = 0;
    QApplication a(fake, nullptr);
    MainWindow mw;
    EXPECT_NO_FATAL_FAILURE(mw.show());
    a.exec();
}

TEST(ConstructorTest, UserWindow) {
    int fake = 0;
    QApplication a(fake, nullptr);
    MainWindow uw;
    EXPECT_NO_FATAL_FAILURE(uw.show());
    a.exec();
}

TEST(ConstructorTest, UIManagerMW) {
    int fake_argc = 0;
    QApplication a(fake_argc, nullptr);
    UIManager um;
    EXPECT_NO_FATAL_FAILURE(um.showMainWindow());
    a.exec();
}

TEST(ConstructorTest, UIManagerUW) {
    int fake_argc = 0;
    QApplication a(fake_argc, nullptr);
    UIManager um;
    EXPECT_NO_FATAL_FAILURE(um.showUserWindow());
    a.exec();
}

TEST(ConstructorTest, MainWindow_AuthDialog) {
    int fake_argc = 0;
    QApplication a(fake_argc, nullptr);
    MainWindow mainWindow;
    EXPECT_NO_FATAL_FAILURE(mainWindow.getAuthDialog()->show());
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
