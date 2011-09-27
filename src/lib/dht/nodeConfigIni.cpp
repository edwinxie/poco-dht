#include "libdht/nodeConfigIni.h"

#include <iostream>

using namespace libdht;

NodeConfigIni::NodeConfigIni(const std::string &ini_file) {
    _config = new Poco::Util::IniFileConfiguration(ini_file);
}

NodeConfigIni::~NodeConfigIni() {

}

void NodeConfigIni::Load(const std::string &ini_file) {
    _config->load(ini_file);
}

bool NodeConfigIni::SanityCheck() {
    if (! _config) {
        std::cout << "NO config object." << std::endl;
        return (false);
    }

    // ensure 'bind_address' key is set under [listener] section:
    if (! _config->hasOption("listener.bind_address")) {
        std::cout << "NO 'listener.bind_address' key in configuration." << std::endl;
        return (false);
    }

    return (true);
}

std::string NodeConfigIni::getString(const std::string &key) {
    return ("NYI");
}

std::string NodeConfigIni::getString(const std::string &key, std::string default_value) {
    return (default_value);
}

int NodeConfigIni::getInt(const std::string &key) {
    return (0);
}

int NodeConfigIni::getInt(const std::string &key, int default_value) {
    return (default_value);
}

double NodeConfigIni::getDouble(const std::string &key) {
    return ( (double) 0);
}

double NodeConfigIni::getDouble(const std::string &key, double default_value) {
    return (default_value);
}

bool NodeConfigIni::getBool(const std::string &key) {
    return (false);
}

bool NodeConfigIni::getBool(const std::string &key, bool default_value) {
    return (default_value);
}


