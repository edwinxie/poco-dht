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
 * @file src/node/nodeLogger.cpp
 * @brief NodeLogger class implementation.
 */
#include "node/nodeLogger.h"
#include "node/config.h"

NodeLogger::NodeLogger() {

}

NodeLogger::~NodeLogger() {

}

void NodeLogger::init(const std::string &filePath, const std::string &name) {
    // file channel:
    Poco::AutoPtr<Poco::FileChannel> pChannel(new Poco::FileChannel);
    pChannel->setProperty("path", filePath);
    pChannel->setProperty("rotation", "10 M");
    pChannel->setProperty("archive", "timestamp");
    pChannel->setProperty("compress", "true");
    pChannel->setProperty("purgeAge", "7 days");

    // formatter:
    Poco::AutoPtr<Poco::PatternFormatter> pFrmt(new Poco::PatternFormatter);
    pFrmt->setProperty("pattern", "%Y-%m-%d %H:%M:%S [%p] %s : %t");

    // formatting channel:
    Poco::AutoPtr<Poco::FormattingChannel> pFrmtC(new Poco::FormattingChannel(pFrmt, pChannel));

    Poco::Logger::root().setChannel(pFrmtC);

    Poco::Logger &log = Poco::Logger::get(name);
    log.setLevel(DEFAULT_LOG_LEVEL);
    log.debug("Logger initialized.");
}

/**
 * @details levels: fatal, critical, error, warning, notice, information, debug, trace
 */
void NodeLogger::setLevel(const std::string &lvl, const std::string &name) {
    Poco::Logger &log = Poco::Logger::get(name);
    log.setLevel(lvl);
}

Poco::Logger &NodeLogger::get(const std::string &name) {
    if (Poco::Logger::has(name) == NULL) {
        NodeLogger::init(DEFAULT_LOG_FILE, name);
    }

    return (Poco::Logger::get(name));
}

