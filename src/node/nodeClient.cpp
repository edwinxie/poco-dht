#include "node/nodeClient.h"
#include "node/nodeLogger.h"

#include <unistd.h>

NodeClient::NodeClient() {

}

NodeClient::~NodeClient() {

}

void NodeClient::runForEver() {
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

