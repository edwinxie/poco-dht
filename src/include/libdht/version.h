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
 * @file src/include/libdht/version.h
 * @brief Version class header.
 */
#ifndef LIBDHT_VERSION_H
#define LIBDHT_VERSION_H

#include "libdht/config.h"

#include <Poco/Types.h>

/**
 * @namespace libdht Our main library namespace.
 * @brief main library namespace.
 */
namespace libdht {

    /**
     * @brief Version class
     * @details Version-related informations for a given node.
     */
    class Version {
        public:
            /**
             * @brief default constructor.
             */
            Version();

            /**
             * @brief default destructor.
             */
            ~Version();

            /**
             * @brief Retrieve current version as an integer.
             * @return unsigned short Node version.
             */
            Poco::UInt16 get();
    };

}

#endif /* LIBDHT_VERSION_H */

