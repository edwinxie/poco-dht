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
 * @file node/main.cpp
 * @brief node binary main entry point.
 */
#include "libdht/nodeConfigIni.h"
#include "node/config.h"
#include "node/nodeClient.h"
#include "node/nodeListener.h"
#include "node/nodeLogger.h"

#include <Poco/RWLock.h>
#include <Poco/Thread.h>
#include <Poco/RunnableAdapter.h>

#include <cstdlib> /* EXIT_SUCCESS */
#include <iostream> /* std::cout */

void output_usage(char **argv) {
    std::cout << "Usage: " << argv[0] << " <path/to/file.ini>" << std::endl;    
}

int main(int argc, char **argv) {
    if (argc != 2) {
        output_usage(argv);
        exit(1);
    }

    // exclusive lock on our shared parts (ie: config):
    Poco::RWLock lock;

    // initialize node config & load given configuration file:
    libdht::NodeConfigIni *config = new libdht::NodeConfigIni(argv[1]);

    // ensure provided configuration file is sane:
    if (! config->SanityCheck()) {
        std::cout << "INVALID configuration file." << std::endl;
        exit(1);
    }

    // TODO use logger, DEBUG level:
    std::cout << "Will bind udp port to " << config->getString("listener.bind_address") << std::endl;

    // spawn node listener component in a separate thread:
    NodeListener *listener = new NodeListener(config, &lock);
    Poco::Thread listenThread;
    listenThread.start(*listener);

    // spawn node client component:
    NodeClient *client = new NodeClient(config, &lock);
    Poco::Thread clientThread;
    clientThread.start(*client);

    // spawn our httpd component:

    // spwan our text-based remote management console:

    // wait for node client to finish:
    clientThread.join();

    // wait for node listener to finish:
    listenThread.join();

    NodeLogger::get("core").debug("Exiting...");

    return (EXIT_SUCCESS);
}

