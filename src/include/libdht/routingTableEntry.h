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
 * @file src/include/libdht/routingTableEntry.h
 * @brief our RoutingTableEntry class.
 */
#ifndef LIBDHT_ROUTINGTABLEENTRY_H
#define LIBDHT_ROUTINGTABLEENTRY_H

namespace libdht {

    /**
     * @brief our RoutingTableEntry class, modelling a single entry in our routing table.
     */
    class RoutingTableEntry {
        public:
            /**
             * @brief default constructor.
             */
            RoutingTableEntry();

            /**
             * @brief default destructor.
             */
            ~RoutingTableEntry();
    };
}

#endif /* LIBDHT_ROUTINGTABLEENTRY_H */

