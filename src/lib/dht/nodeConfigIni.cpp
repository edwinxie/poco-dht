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

