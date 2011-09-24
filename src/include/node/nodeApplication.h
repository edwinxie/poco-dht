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
 * @file src/include/node/nodeApplication.h
 * @brief our poco-based application class.
 */
#ifndef NODE_APPLICATION_H
#define NODE_APPLICATION_H

#include <Poco/Util/OptionSet.h>
#include <Poco/Util/ServerApplication.h>

#include <string>
#include <vector>

/**
 * @brief Poco 'application' providing getopt, daemon/service features.
 */
class NodeApplication : public Poco::Util::ServerApplication {
    public:
        /**
         * @brief default constructor.
         */
        NodeApplication();

        /**
         * @brief default destructor.
         */
        ~NodeApplication();

    protected:
        /**
         * @brief adds our own options to poco application.
         */
        void defineOptions(Poco::Util::OptionSet &options);

        /**
         * @brief basic application initialization.
         */
        void initialize(Poco::Util::ServerApplication &self);

        /**
         * @brief application entry point, poco way.
         */
        int main(const std::vector<std::string>& args);

        /**
         * @brief poco CLI callback associated to -h|--help opt.
         */
        void handleHelp(const std::string& name, const std::string& value);

        /**
         * @brief sample usage output.
         */
        void displayHelp();

        /**
         * @brief poco CLI callback for -c|--config opt.
         */
        void handleConfig(const std::string& name, const std::string& value);

    private:
        bool _helpRequested;
};

POCO_SERVER_MAIN(NodeApplication)

#endif /* NODE_APPLICATION_H */

