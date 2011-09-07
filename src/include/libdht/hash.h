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
 * @file src/include/libdht/hash.h
 * @brief various hashing methods
 *
 * @details Usage:
 * #include <iostream>
 * #include <string>
 * #include "libdht/hash.h"
 *
 * std::string str;
 * str = libdht::Hash::md5Hex(str);
 * std::cout << str << std::endl;
 * 
 */
#ifndef LIBDHT_HASH_H
#define LIBDHT_HASH_H

#include <string>
#include <Poco/DigestStream.h>
#include <Poco/MD5Engine.h>

namespace libdht {

    class Hash {

        public:
            /**
             * @brief default constructor.
             */
            Hash();

            /**
             * @brief default destructor.
             */
            ~Hash();

            /**
             * @brief computes md5 of given string, return hex-formatted result.
             */
            static std::string md5Hex(const std::string &str);
    };
}

#endif /* LIBDHT_HASH_H */

