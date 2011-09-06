#include "libdht/localnode.h"

using namespace libdht;

LocalNode::LocalNode(const std::string &hostPort) : Node(hostPort) {
    _requests = new RequestList();
}

LocalNode::~LocalNode() {
    delete _requests;
}

