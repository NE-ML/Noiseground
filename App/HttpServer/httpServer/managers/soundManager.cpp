#include "soundManager.h"

#include <boost/lexical_cast.hpp>
#include <sound.h>

SoundManager::SoundManager()
        : soundModel(std::make_shared<SoundModel>()),
        serializer(std::make_shared<Serializer>()) {}

void SoundManager::getStdSounds(Reply& rep) {
    auto res = soundModel->getStdSounds();
    rep.status = Reply::ok;
    rep.content = serializer->serialSounds(res);
    rep.headers.resize(1);
    rep.headers[0].name = "Content-Length";
    rep.headers[0].value = boost::lexical_cast<std::string>(rep.content.size());
}

void SoundManager::createSound(const Request &req, Reply &rep) {
    auto body = std::find_if(req.headers.begin(), req.headers.end(),
                             [](const Header& i) {return i.name == "Body";});
    std::pair<std::string, Sound> new_sound = serializer->deserialNewSoundData(body->value);
    bool res = soundModel->createNewSound(new_sound);
    if (res) {
        rep.status = Reply::ok;
        return;
    }
    rep.status = Reply::forbidden;
}

void SoundManager::getUserSounds(const std::string &request_path, Reply &rep) {
    std::string login = get_param(request_path, "username");
    auto res = soundModel->getUserSounds(login);
    if (res.empty()) {
        rep.status = Reply::no_content;
        return;
    }
    rep.status = Reply::ok;
    rep.content = serializer->serialSounds(res);
    rep.headers.resize(1);
    rep.headers[0].name = "Content-Length";
    rep.headers[0].value = boost::lexical_cast<std::string>(rep.content.size());
}

void SoundManager::deleteSound(const Request &req, Reply& rep) {
    auto body = std::find_if(req.headers.begin(), req.headers.end(),
                             [](const Header& i) {return i.name == "Body";});
    std::pair<std::string, std::string> deleted_sound = serializer->deserialDeletedSoundData(body->value);
    bool res = soundModel->deleteSound(deleted_sound);
    if (res) {
        rep.status = Reply::ok;
        return;
    }
    rep.status = Reply::forbidden;
}

void SoundManager::changeSound(const Request &req, Reply &rep) {
    auto body = std::find_if(req.headers.begin(), req.headers.end(),
                             [](const Header& i) {return i.name == "Body";});
    std::pair<std::string, Sound> changed_sound = serializer->deserialChangedSoundData(body->value);
    bool res = soundModel->changeSound(changed_sound);
    if (res) {
        rep.status = Reply::ok;
        return;
    }
    rep.status = Reply::forbidden;
}

std::string SoundManager::get_param(const std::string& path, const std::string& name) {
    std::size_t pos = path.find(name, 0);
    std::size_t pos_equal = path.find('=', pos);
    std::size_t pos_and = path.find('&', pos_equal);
    if (pos_and == std::string::npos) {
        pos_and = path.size();
    }
    return path.substr(pos_equal + 1, pos_and - pos_equal - 1);
}