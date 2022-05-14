#include "soundManager.h"

#include <boost/lexical_cast.hpp>
#include <sound.h>

void SoundManager::getStdSounds(Reply& rep) {
    auto res = soundModel->getStdSounds();
    rep.status = Reply::ok;
    rep.content = serializer->serialSounds(res);
    rep.headers.resize(1);
    rep.headers[0].name = "Content-Length";
    rep.headers[0].value = boost::lexical_cast<std::string>(rep.content.size());
}