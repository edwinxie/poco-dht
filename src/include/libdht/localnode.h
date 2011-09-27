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
 * @file src/include/libdht/localnode.h
 * @brief local node class.
 */
#ifndef LIBDHT_LOCALNODE_H
#define LIBDHT_LOCALNODE_H

#include "libdht/node.h"
#include "libdht/requestList.h"

#include <string>

namespace libdht {

    /**
     * @brief local node class.
     */
    class LocalNode : public Node {
        public:
            /**
             * @brief default constructor.
             */
            LocalNode(const std::string &hostPort);

            /**
             * @brief default destructor.
             */
            ~LocalNode();

        protected:
            RequestList     *_requests; /**< current requests beeing processed by local node */
    };
}

#endif /* LIBDHT_LOCALNODE_H */

