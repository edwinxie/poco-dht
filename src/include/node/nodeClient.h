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
 * @file src/include/node/nodeClient.h
 * @brief our NodeClient class.
 */
#ifndef NODE_CLENT_H
#define NODE_CLENT_H

/**
 * @brief our NodeClient class.
 * @details client part of our libdht node.
 */
class NodeClient {
    public:
        /**
         * @brief default constructor.
         */
        NodeClient();

        /**
         * @brief default destructor.
         */
        virtual ~NodeClient();

        /**
         * @brief main nodeclient loop.
         * @details will block until stop is requested.
         */
        void runForEver();

        /**
         * @brief asks for node client stop.
         */
        void stop();

    protected:
        bool    _running; /**< wether client node is running or not. */
};

#endif /* NODE_CLENT_H */

