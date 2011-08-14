#include "nodeLogger.h"

NodeLogger::NodeLogger() {

}

NodeLogger::~NodeLogger() {

}

void NodeLogger::init(const std::string &filePath, const std::string &name) {
    // file channel:
    Poco::AutoPtr<Poco::SimpleFileChannel> pChannel(new Poco::SimpleFileChannel);
    pChannel->setProperty("path", filePath);
    pChannel->setProperty("rotation", "10 M");
    //pChannel->setProperty("archive", "timestamp");
    //pChannel->setProperty("compress", "true");
    //pChannel->setProperty("purgeAge", "7 days");

    // formatter:
    Poco::AutoPtr<Poco::PatternFormatter> pFrmt(new Poco::PatternFormatter);
    pFrmt->setProperty("pattern", "%Y-%m-%d %H:%M:%S %s : %t");

    // formatting channel:
    Poco::AutoPtr<Poco::FormattingChannel> pFrmtC(new Poco::FormattingChannel(pFrmt, pChannel));

    Poco::Logger::root().setChannel(pFrmtC);

    Poco::Logger &log = Poco::Logger::get(name);
    log.information("Logger initialized.");
}

