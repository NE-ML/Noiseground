#include "gtest/gtest.h"
#include "User.h"
#include "UserSound.h"
#include "Preset.h"

TEST(UserTests, Assert1){
    User user("makezh", 123);
    EXPECT_EQ(user.getId(), 123);
    EXPECT_EQ(user.getLogin(), string("makezh"));
    EXPECT_EQ(user.idToLogin(123), string("makezh"));
}

TEST(UserTests, Assert2){
    User user("makezh", 123);
    user.setLogin("levbara");
    EXPECT_EQ(user.getId(), 123);
    EXPECT_EQ(user.getLogin(), string("levbara"));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}