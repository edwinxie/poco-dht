#include "libdht/nodeConfigBase.h"

#include <iostream>

using namespace libdht;

NodeConfigBase::NodeConfigBase() {

}

NodeConfigBase::~NodeConfigBase() {

}

bool NodeConfigBase::SanityCheck() {
    return (false);
}

std::string NodeConfigBase::getString(const std::string &key) {
    return ("NYI");
}

std::string NodeConfigBase::getString(const std::string &key, std::string default_value) {
    return (default_value);
}

int NodeConfigBase::getInt(const std::string &key) {
    return (0);
}

int NodeConfigBase::getInt(const std::string &key, int default_value) {
    return (default_value);
}

double NodeConfigBase::getDouble(const std::string &key) {
    return ( (double) 0);
}

double NodeConfigBase::getDouble(const std::string &key, double default_value) {
    return (default_value);
}

bool NodeConfigBase::getBool(const std::string &key) {
    return (false);
}

bool NodeConfigBase::getBool(const std::string &key, bool default_value) {
    return (default_value);
}


