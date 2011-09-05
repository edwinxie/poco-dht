#ifndef NODE_LOGGER_H
#define NODE_LOGGER_H

#include <string>
#include <Poco/Logger.h>
#include <Poco/AutoPtr.h>
#include <Poco/PatternFormatter.h>
#include <Poco/FormattingChannel.h>
#include <Poco/FileChannel.h>

class NodeLogger {
    public:
        NodeLogger();
        virtual ~NodeLogger();

        static void init(const std::string &filePath, const std::string &name);
        static void setLevel(const std::string &lvl, const std::string &name);

        static Poco::Logger &get(const std::string &name);
};

#endif /* NODE_LOGGER_H */

