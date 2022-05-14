#include "serializer.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/archive/iterators/binary_from_base64.hpp>
#include <boost/archive/iterators/transform_width.hpp>
#include <boost/algorithm/string.hpp>



std::string Serializer::decode64(const std::string &val) {
    using namespace boost::archive::iterators;
    using It = transform_width<binary_from_base64<std::string::const_iterator>, 8, 6>;
    return boost::algorithm::trim_right_copy_if(std::string(It(std::begin(val)), It(std::end(val))), [](char c) {
        return c == '\0';
    });
}


std::vector<Sound> Serializer::deserialSounds(const std::string &val) {
    std::stringstream ss;
    ss << val;
    boost::property_tree::ptree json;
    boost::property_tree::read_json(ss, json);
    int count = json.get<int>("count");
    std::vector<Sound> sounds;
    for (auto &sound : json.get_child("sounds")) {
        Sound new_sound;
        new_sound.name = sound.second.get<std::string>("name");
        new_sound.content = decode64(sound.second.get<std::string>("data"));
        sounds.push_back(new_sound);
    }
    return sounds;
};

std::string Serializer::serialData(const Params *body) {
    boost::property_tree::ptree json;
    if (body && !body->empty()) {
        auto iter = body->begin();
        for (; iter != body->end(); iter++) {
            json.put(iter->first, iter->second);
        }
    }
    std::ostringstream buf;
    write_json(buf, json, false);
    return buf.str();
};