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

    Poco::RWLock lock;

    // node config:
    libdht::NodeConfigIni *config = new libdht::NodeConfigIni(argv[1]);

    // spawn node listener component in a separate thread:
    NodeListener *listener = new NodeListener(config, &lock);
    Poco::Thread listenThread;
    listenThread.start(*listener);

    // spawn node client component:
    NodeClient *client = new NodeClient(config, &lock);
    Poco::Thread clientThread;
    clientThread.start(*client);

    // spawn httpd component:

    // wait for node client to finish:
    clientThread.join();

    // wait for node listener to finish:
    listenThread.join();

    NodeLogger::get("core").debug("Exiting...");

    return (EXIT_SUCCESS);
}

