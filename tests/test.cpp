#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "mainwindow.h"

class MockMW : public MainWindow {
public:
    MockMW() : MainWindow() {}

    MOCK_METHOD(void, setupUi, (QMainWindow *MainWindow));
};

TEST(1, 1) {
    EXPECT_CALL()
    MockMW mmw;
    
}