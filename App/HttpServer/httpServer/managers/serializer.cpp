#include "serializer.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/archive/iterators/base64_from_binary.hpp>
#include <boost/archive/iterators/binary_from_base64.hpp>
#include <boost/archive/iterators/transform_width.hpp>
#include <boost/algorithm/string.hpp>

std::string Serializer::encode64(const std::string &val) {
    using namespace boost::archive::iterators;
    using It = base64_from_binary<transform_width<std::string::const_iterator, 6, 8>>;
    auto tmp = std::string(It(std::begin(val)), It(std::end(val)));
    return tmp.append((3 - val.size() % 3) % 3, '=');
}

std::string Serializer::decode64(const std::string &val) {
    using namespace boost::archive::iterators;
    using It = transform_width<binary_from_base64<std::string::const_iterator>, 8, 6>;
    return boost::algorithm::trim_right_copy_if(std::string(It(std::begin(val)), It(std::end(val))), [](char c) {
        return c == '\0';
    });
}


std::string Serializer::serialSounds(std::vector<Sound> &sounds) {
    boost::property_tree::ptree json;
    json.put("count", sounds.size());
    boost::property_tree::ptree sounds_nodes;
    for (auto &i: sounds) {
        boost::property_tree::ptree node;
        node.put("name", i.name);
        node.put("data", encode64(i.content));
        sounds_nodes.push_back(std::make_pair("", node));
    }
    json.add_child("sounds", sounds_nodes);
    std::stringstream out;
    boost::property_tree::write_json(out, json);
    return out.str();
};

User Serializer::deserialRegisterData(const std::string &val) {
    std::stringstream ss;
    ss << val;
    boost::property_tree::ptree json;
    boost::property_tree::read_json(ss, json);
    User tmp;
    tmp.login = json.get<std::string>("login");
    tmp.password = json.get<std::string>("password");
    return tmp;
};

std::pair<std::string, Sound> Serializer::deserialNewSoundData(const std::string &val) {
    std::stringstream ss;
    ss << val;
    boost::property_tree::ptree json;
    boost::property_tree::read_json(ss, json);
    std::pair<std::string, Sound> tmp;
    tmp.first = json.get<std::string>("username");
    tmp.second.name = json.get<std::string>("name");
    tmp.second.content = decode64(json.get<std::string>("data"));
    return tmp;
};