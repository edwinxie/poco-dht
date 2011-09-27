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
    if (! _config) {
        // TODO log me
        return ("");
    }

    return (_config->getString(key));
}

std::string NodeConfigIni::getString(const std::string &key, std::string default_value) {
    if (! _config) {
        // TODO log me
        return (default_value);
    }

    return (_config->getString(key, default_value));
}

int NodeConfigIni::getInt(const std::string &key) {
    if (! _config) {
        // TODO log me
        return (0);
    }

    return (_config->getInt(key));
}

int NodeConfigIni::getInt(const std::string &key, int default_value) {
    if (! _config) {
        // TODO log me
        return (default_value);
    }

    return (_config->getInt(key, default_value));
}

double NodeConfigIni::getDouble(const std::string &key) {
    if (! _config) {
        // TODO log me
        return (0);
    }

    return (_config->getDouble(key));
}

double NodeConfigIni::getDouble(const std::string &key, double default_value) {
    if (! _config) {
        // TODO log me
        return (default_value);
    }

    return (_config->getDouble(key, default_value));
}

bool NodeConfigIni::getBool(const std::string &key) {
    if (! _config) {
        // TODO log me
        return (false);
    }

    return (_config->getBool(key));
}

bool NodeConfigIni::getBool(const std::string &key, bool default_value) {
    if (! _config) {
        // TODO log me
        return (default_value);
    }

    return (_config->getBool(key, default_value));
}

