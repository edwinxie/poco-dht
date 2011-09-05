#ifndef LIBDHT_NODE_H
#define LIBDHT_NODE_H

#include "libdht/version.h"

#include <string>

namespace libdht {

    class Node {
        public:
            Node(const std::string &hostPort);
            ~Node();

        protected:
            std::string         _hostPort;
            Version             *_version;
    };

}

#endif /* LIBDHT_NODE_H */

