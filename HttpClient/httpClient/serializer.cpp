#include "serializer.h"

#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/archive/iterators/binary_from_base64.hpp>
#include <boost/archive/iterators/base64_from_binary.hpp>
#include <boost/archive/iterators/transform_width.hpp>
#include <boost/algorithm/string.hpp>

std::string Serializer::decode64(const std::string &val) {
    using boost::archive::iterators::binary_from_base64;
    using boost::archive::iterators::transform_width;
    using It = transform_width<binary_from_base64<std::string::const_iterator>, 8, 6>;
    return boost::algorithm::trim_right_copy_if(std::string(It(std::begin(val)),
                                                   It(std::end(val))),
                                             [](char c) {
        return c == '\0';
    });
}

std::string Serializer::encode64(const std::string &val) {
    using boost::archive::iterators::base64_from_binary;
    using boost::archive::iterators::transform_width;
    using It = base64_from_binary<transform_width<std::string::const_iterator, 6, 8>>;
    auto tmp = std::string(It(std::begin(val)), It(std::end(val)));
    return tmp.append((3 - val.size() % 3) % 3, '=');
}


std::vector<Sound> Serializer::deserialSounds(const std::string &val) {
    std::stringstream ss;
    ss << val;
    boost::property_tree::ptree json;
    boost::property_tree::read_json(ss, json);
    std::vector<Sound> sounds;
    for (auto &sound : json.get_child("sounds")) {
        Sound new_sound;
        new_sound.name = sound.second.get<std::string>("name");
        new_sound.content = decode64(sound.second.get<std::string>("data"));
        sounds.push_back(new_sound);
    }
    return sounds;
}

std::string Serializer::serialData(const std::shared_ptr<Params>& body) {
    boost::property_tree::ptree json;
    if (body) {
        for (auto& iter : *body) {
            json.put(iter.first, iter.second);
        }
    }
    std::ostringstream buf;
    write_json(buf, json, false);
    return buf.str();
}
