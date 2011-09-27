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

            /**
             * @brief Version getter.
             * @return Version node's version object.
             */
            Version *getVersion();

        protected:
            std::string         _hostPort; /**< public ip|host & port where to reach this node */
            Version             *_version; /**< current node version */
    };

}

#endif /* LIBDHT_NODE_H */

