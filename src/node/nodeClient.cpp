#include "node/nodeClient.h"
#include "node/nodeLogger.h"

#include <unistd.h>

NodeClient::NodeClient(libdht::NodeConfigIni *cfg, Poco::RWLock *lock) {
    _config = cfg;
    _lock = lock;
}

NodeClient::~NodeClient() {

}

void NodeClient::run() {
    _lock->writeLock(); // acquire lock
    // TODO read client config
    _lock->unlock(); // release lock

    this->_running = true;

    NodeLogger::get("core").debug("NodeClient started.");
    while (this->_running) {
        sleep (1);
    }
    NodeLogger::get("core").debug("NodeClient::runForEver() exiting.");
}

void NodeClient::stop() {
    NodeLogger::get("core").debug("NodeClient asked to stop...");
    this->_running = false;
}

