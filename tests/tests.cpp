#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <pqxx/pqxx>

#include "../DatabaseInteraction.h"

class MockUserModel : public UserModel {
public:
    MOCK_METHOD(User, parseResponce, (pqxx::result));
    MOCK_METHOD2(createRequest, char*(std::string, std::map<std::string, std::string>));
};

class MockSoundModel : public SoundModel {
public:
    MOCK_METHOD(std::vector<Sound>, parseResponce, (pqxx::result));
    MOCK_METHOD2(createRequest, char*(std::string, std::map<std::string, std::string>));
    MOCK_METHOD(std::vector<Sound>, getStdSounds, ());
};

/*
 * class MockDBClient : public DbClient {
public:
    MOCK_METHOD(pqxx::result, select, (char*));
    MOCK_METHOD(DbClient*, getInstance, ());
    //MOCK_METHOD0(DbClient, (), ());
};
 */

TEST(UserAndSound, RequestAndResponce) {
    MockUserModel userModel;
    MockSoundModel soundModel;

    pqxx::result* res = new pqxx::result();
    std::string str = "SELECT";
    std::map<std::string, std::string> M;
    M["WHAT"] = "*";

    EXPECT_CALL(userModel, parseResponce(*res)).Times(testing::AtLeast(1));
    EXPECT_CALL(userModel, createRequest(str, M)).Times(testing::AtLeast(1));

    EXPECT_CALL(soundModel, parseResponce(*res)).Times(testing::AtLeast(1));
    EXPECT_CALL(soundModel, createRequest(str, M)).Times(testing::AtLeast(1));
    EXPECT_CALL(soundModel, getStdSounds()).Times(::testing::AtLeast(1));

    delete res;
}

/* TEST(DbClient, Responces) {
    char* ch = new char[1];
    ch[0] = 'a';

    EXPECT_CALL(MockDBClient::getInstance(), select(ch)).Times(::testing::AtLeast(1));

    delete[] ch;
}
 */

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}