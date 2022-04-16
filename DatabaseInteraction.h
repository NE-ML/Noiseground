//
// Created by multitavi on 15.04.22.
//

#ifndef UNTITLED_DATABASEINTERACTION_H
#define UNTITLED_DATABASEINTERACTION_H

#endif //UNTITLED_DATABASEINTERACTION_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <pqxx/pqxx>

struct User {
    std::string login;
    int id;
    bool enabled;
};

struct Sound {
    // music
    int time;
    int volume;
};

class UserModel {
public:
    UserModel() {}

    ~UserModel() {}

    UserModel(const UserModel& other) = delete;
    UserModel& operator=(const UserModel& other) = delete;

    int isInDB(std::string username) {}
    User getUser(int userId) {}
    int deleteUser(int userId) {}
    int changeUser(int userId, std::string newUsername) {}
private:
    User parseResponse(pqxx::result res) {}
    char* createRequest(std::string type, std::map<std::string, std::string> params) {}
};

class SoundModel {
public:
    SoundModel() {}

    ~SoundModel() {}

    SoundModel(const SoundModel& other) = delete;
    SoundModel& operator=(const SoundModel& other) = delete;

    std::vector<Sound> getUserSound(std::string username) {}
    int changeSound(int soundId, std::string newName) {}
    int deleteSound(int soundId) {}
    std::vector<Sound> getStdSounds() {}
private:
    std::vector<Sound> parseResponse(pqxx::result res) {}
    char* createRequest(std::string type, std::map<std::string, std::string> params) {}
};

class DbClient {
public:
    static DbClient* getInstance() {
        if(!client_) {
            client_ = new DbClient();
        }
        return client_;
    }

    DbClient(const DbClient& other) = delete;
    DbClient& operator=(const DbClient& other) = delete;

    int del(char* query) {}
    int insert(char* query) {}
    int update(char* query) {}
    pqxx::result select(char* query) {}
    ~DbClient() {}
private:
    DbClient() {}

    pqxx::connection connect(const char* conInfo) {}

    static DbClient* client_;
    pqxx::connection connection_;
};