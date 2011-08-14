#include "config.h"
#include "nodeListener.h"

#include <Poco/Thread.h>
#include <Poco/RunnableAdapter.h>
#include <cstdlib> /* EXIT_SUCCESS */

int main(int argc, char **argv) {
    // spawn node listener in a separate thread:
    NodeListener listener;
    Poco::RunnableAdapter<NodeListener> ra(listener, &NodeListener::start);
    Poco::Thread listenThread;
    listenThread.start(ra);

    // wait for listener to finish:
    listenThread.join();

    return (EXIT_SUCCESS);
}

