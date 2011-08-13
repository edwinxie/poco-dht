#include "config.h"
#include "nodeListener.h"

#include <cstdlib> /* EXIT_SUCCESS */

int main(int argc, char **argv) {
    // TODO create separate thread:
    NodeListener *listener = new NodeListener("0.0.0.0:4242");
    listener->start(); // blocking...
    listener->stop();

    return (EXIT_SUCCESS);
}

