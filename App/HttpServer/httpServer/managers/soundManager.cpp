#include "soundManager.h"

#include <fstream>
#include <sstream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

std::string SoundManager::readFile(const std::string& fileName) {
    std::ifstream f(fileName);
    std::stringstream ss;
    ss << f.rdbuf();
    f.close();
    return ss.str();
}

std::string SoundManager::getStdSounds() {
    std::vector<Sound> res(standardNames.size());
    int k = 0;
    for (auto &i : standardNames) {
        res[k].name = i;
        res[k].content = readFile(i);
        k++;
    }
    boost::property_tree::ptree json;
    json.put("count", res.size());
    boost::property_tree::ptree sounds_nodes;
    for (auto &i: res) {
        boost::property_tree::ptree node;
        node.put("name", i.name);
        node.put("data", i.content);
        sounds_nodes.push_back(std::make_pair("", node));
    }
    json.add_child("sounds", sounds_nodes);
    std::stringstream out;
    boost::property_tree::write_json(out, json);
    return out.str();
}