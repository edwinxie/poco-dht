#include "libdht/nodeConfigIni.h"

using namespace libdht;

NodeConfigIni::NodeConfigIni(const std::string &ini_file) : NodeConfigBase() {
    _config = new Poco::Util::IniFileConfiguration(ini_file);
}

NodeConfigIni::~NodeConfigIni() {

}

