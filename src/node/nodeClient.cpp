/*
 * This file is part of poco-dht (http://github.com/alemansec/poco-dht).
 *
 * poco-dht is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation.
 *
 * poco-dht is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with poco-dht.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @file src/node/nodeClient.cpp
 * @brief NodeClient class implementation.
 */
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

