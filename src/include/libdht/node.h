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
 * @file src/include/libdht/node.h
 * @brief Node class.
 */
#ifndef LIBDHT_NODE_H
#define LIBDHT_NODE_H

#include "libdht/version.h"

#include <string>

namespace libdht {

    /**
     * @brief Node class.
     * @details basic properties for a libdht Node.
     */
    class Node {
        public:
            /**
             * @brief detault constructor.
             * @param \a hostPort host:port string where to reach this node.
             */
            Node(const std::string &hostPort);

            /**
             * @brief default destructor.
             */
            ~Node();

        protected:
            /**
             * @brief host:port string where this node is reachable.
             */
            std::string         _hostPort;

            /**
             * @brief node's Version.
             */
            Version             *_version;
    };

}

#endif /* LIBDHT_NODE_H */

