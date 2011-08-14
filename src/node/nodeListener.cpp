#include "nodeListener.h"
#include "nodeLogger.h"

#include <unistd.h> // sleep()
#include <Poco/NObserver.h>
#include <Poco/Exception.h>

NodeListener::NodeListener() {

}

NodeListener::~NodeListener() {

}

bool NodeListener::initialize(const std::string &hostPort) {
    NodeLogger::get("core").debug("NodeListener thread initializing...");

    // setup & bind sock:
    _listenSockAddr = Poco::Net::SocketAddress(hostPort);
    _listenSock.bind(_listenSockAddr, true);

    // setup & attach event handlers to reactor:
    _reactor.addEventHandler(_listenSock, Poco::NObserver<NodeListener, Poco::Net::ReadableNotification>(*this, &NodeListener::onReceivePacket));

}

void NodeListener::runForEver() {
    this->initialize("0.0.0.0:4242");
    _reactorThread.start(_reactor);
    this->_running = true;
    NodeLogger::get("core").debug("NodeListener started.");
    while (this->_running) {
        sleep(1);
    }
    this->stop();
}

void NodeListener::stop() {
    this->_running = false;
    NodeLogger::get("core").debug("NodeListener stopping...");
    _reactor.stop();
    _reactorThread.join(); // wait for termination
}

void NodeListener::onReceivePacket(const Poco::AutoPtr<Poco::Net::ReadableNotification> &notif) {

}

