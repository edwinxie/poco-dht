#include "libdht/node.h"

using namespace libdht;

Node::Node(const std::string &hostPort) {
    _hostPort = hostPort;
    _version = new Version();
}

Node::~Node() {

}

Version *Node::getVersion() {
    return (_version);
}

