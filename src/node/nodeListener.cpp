#include "nodeListener.h"

#include <Poco/NObserver.h>
#include <Poco/Exception.h>

NodeListener::NodeListener(const std::string &hostPort) {
    this->initialize(hostPort);
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

bool NodeListener::start() {
    _reactorThread.start(_reactor);
    _running = true;
    waitForTerminationRequest();

    return (true);
}

bool NodeListener::stop() {
    _running = false;
    _reactor.stop();
    _reactorThread.join(); // wait for termination

    return (true);
}

void NodeListener::onReceivePacket(const Poco::AutoPtr<Poco::Net::ReadableNotification> &notif) {

}

