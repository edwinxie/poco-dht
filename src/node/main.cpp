/**
 * @file node/main.cpp
 * @brief node binary main entry point.
 */
#include "config.h"
#include "nodeListener.h"
#include "nodeLogger.h"

#include <Poco/Thread.h>
#include <Poco/RunnableAdapter.h>
#include <cstdlib> /* EXIT_SUCCESS */

int main(int argc, char **argv) {
    // spawn node listener component in a separate thread:
    NodeListener listener;
    Poco::RunnableAdapter<NodeListener> ra(listener, &NodeListener::runForEver);
    Poco::Thread listenThread;
    listenThread.start(ra);

    // spawn node client component:

    // spawn httpd component:

    // wait for listener to finish:
    listenThread.join();

    NodeLogger::get("core").debug("Exiting...");

    return (EXIT_SUCCESS);
}

