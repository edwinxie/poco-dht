#include "nodeListener.h"

#include <Poco/NObserver.h>
#include <Poco/Exception.h>

NodeListener::NodeListener() {

}

NodeListener::~NodeListener() {

}

bool NodeListener::initialize(const std::string &hostPort) {
    // setup & bind sock:
    _listenSockAddr = Poco::Net::SocketAddress(hostPort);
    _listenSock.bind(_listenSockAddr, true);

    // setup & attach event handlers to reactor:
    _reactor.addEventHandler(_listenSock, Poco::NObserver<NodeListener, Poco::Net::ReadableNotification>(*this, &NodeListener::onReceivePacket));

}

void NodeListener::start() {
    this->initialize("0.0.0.0:4242");
    _reactorThread.start(_reactor);
    _running = true;
    waitForTerminationRequest();
}

void NodeListener::stop() {
    _running = false;
    _reactor.stop();
    _reactorThread.join(); // wait for termination
}

void NodeListener::onReceivePacket(const Poco::AutoPtr<Poco::Net::ReadableNotification> &notif) {

}

