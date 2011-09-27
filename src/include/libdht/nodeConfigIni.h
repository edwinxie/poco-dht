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
 * @file src/include/libdh/nodeConfigIni.h
 * @brief ini config class.
 */
#ifndef LIBDHT_CONFIG_INI_H
#define LIBDHT_CONFIG_INI_H

#include "libdht/nodeConfigBase.h"

#include <Poco/Util/IniFileConfiguration.h>

#include <string>

namespace libdht {

    class NodeConfigIni : public NodeConfigBase {
        public:

            /**
             * @brief default constructor.
             * @details initializes internals & parses provided ini file.
             * @param std::string \a ini_file ini configuration path.
             */
            NodeConfigIni(const std::string &ini_file);

            /**
             * @brief default destructor.
             */
            ~NodeConfigIni();

            /**
             * @brief loads configuration data from given file.
             */
            void Load(const std::string &ini_file);

            /**
             * @brief basic configuration sanity check.
             * @details ensure configuration is loaded, and mandatory keys exists.
             * @return boolean true on successful check, false otherwise.
             */
            bool SanityCheck();

            virtual std::string getString(const std::string &key);
            virtual std::string getString(const std::string &key, const std::string default_value);
            virtual int getInt(const std::string &key);
            virtual int getInt(const std::string &key, int default_value);

            virtual double getDouble(const std::string &key);
            virtual double getDouble(const std::string &key, double default_value);

            virtual bool getBool(const std::string &key);
            virtual bool getBool(const std::string &key, bool default_value);


        protected:
            Poco::Util::IniFileConfiguration    *_config; /**< current config instance */
    };
}

#endif /* LIBDHT_CONFIG_INI_H */

