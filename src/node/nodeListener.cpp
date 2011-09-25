#include "node/nodeListener.h"
#include "node/nodeLogger.h"

#include <unistd.h> // sleep()
#include <Poco/NObserver.h>
#include <Poco/Exception.h>

NodeListener::NodeListener(libdht::NodeConfigIni *cfg, Poco::RWLock *lock) {
    _config = cfg;
    _lock = lock;
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

void NodeListener::run() {
    _lock->writeLock(); // acquire lock (core/config)
    // TODO read bindaddress from config
    _lock->unlock(); // release lock

    this->initialize("0.0.0.0:4242");
    _reactorThread.start(_reactor);
    this->_running = true;
    NodeLogger::get("core").debug("NodeListener started.");
    while (this->_running) {
        sleep(1);
    }
    NodeLogger::get("core").debug("NodeListener::runForEver() exiting.");
}

void NodeListener::stop() {
    NodeLogger::get("core").debug("NodeListener asked to stop...");
    this->_running = false;
    _reactor.stop();
    _reactorThread.join(); // wait for termination
    NodeLogger::get("core").debug("NodeListener reactor stopped.");
}

void NodeListener::onReceivePacket(const Poco::AutoPtr<Poco::Net::ReadableNotification> &notif) {

}

