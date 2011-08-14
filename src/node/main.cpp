/**
 * @file node/main.cpp
 * @brief node binary main entry point.
 */
#include "config.h"
#include "nodeListener.h"
#include "nodeLogger.h"
#include "dataCore.h"

#include <Poco/Thread.h>
#include <Poco/RunnableAdapter.h>

#include <cstdlib> /* EXIT_SUCCESS */

int main(int argc, char **argv) {
    // our 'dataCore' object references all our components:
    DataCore *core = new DataCore();

    // spawn node listener component in a separate thread:
    NodeListener listener;
    Poco::RunnableAdapter<NodeListener> ralist(listener, &NodeListener::runForEver);
    Poco::Thread listenThread;
    listenThread.start(ralist);
    core->setNodeListener(&listener);

    // spawn node client component:
    NodeClient client;
    Poco::RunnableAdapter<NodeClient> racli(client, &NodeClient::runForEver);
    Poco::Thread clientThread;
    clientThread.start(racli);
    core->setNodeClient(&client);


    // spawn httpd component:

    // wait for node client to finish:
    clientThread.join();

    // wait for node listener to finish:
    listenThread.join();

    NodeLogger::get("core").debug("Exiting...");

    return (EXIT_SUCCESS);
}

