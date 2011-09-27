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
 * @file src/include/libdht/nodeConfigBase.h
 * @brief base node config class.
 */
#ifndef LIBDHT_CONFIG_BASE_H
#define LIBDHT_CONFIG_BASE_H

#include <Poco/AutoPtr.h>
#include <Poco/Util/AbstractConfiguration.h>

namespace libdht {

    /**
     * @brief base class for our various config engines.
     */
    class NodeConfigBase {
        public:
            /**
             * @brief default constructor.
             */
            NodeConfigBase();

            /**
             * @brief default destructor.
             */
            ~NodeConfigBase();

            /**
             * @brief basic configuration sanity check.
             * @details Not Implemented here ; overload this.
             */
            virtual bool SanityCheck();

        protected:
            //Poco::AutoPtr<Poco::Util::AbstractConfiguration> _config; /**< implementation-independant config pointer  */
            Poco::Util::AbstractConfiguration   *_config;
    };
}

#endif /* LIBDHT_CONFIG_BASE_H */

