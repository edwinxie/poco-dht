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
 * @file src/include/libdht/routingTable.h
 * @brief RoutingTable class.
 */
#ifndef LIBDHT_ROUTINGTABLE_H
#define LIBDHT_ROUTINGTABLE_H

#include "libdht/routingTableEntry.h"

#include <list>

namespace libdht {

    /**
     * @brief our RoutingTable class, modelling a node's routing table.
     */
    class RoutingTable {
        public:
            /**
             * @brief default constructor.
             */
            RoutingTable();

            /**
             * @brief default destructor.
             */
            ~RoutingTable();

        protected:
            std::list<RoutingTableEntry> _routingTable; /**< current node's routing table. */
    };

}

#endif /* LIBDHT_ROUTINGTABLE_H */

