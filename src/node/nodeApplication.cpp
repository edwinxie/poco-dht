#include "node/nodeApplication.h"

#include <Poco/Util/HelpFormatter.h>
#include <Poco/Util/Option.h>
#include <Poco/Util/OptionCallback.h>

#include <iostream>

NodeApplication::NodeApplication() {
    _helpRequested = false;
}

NodeApplication::~NodeApplication() {

}

void NodeApplication::initialize(Poco::Util::ServerApplication &self) {
    loadConfiguration();
    ServerApplication::initialize(self);
}

int NodeApplication::main(const std::vector<std::string>& args) {
    if (! _helpRequested) {
        unsigned short port = (unsigned short) config().getInt("listener.udp_port", 4242);
        // TODO spawn our various components...
        Poco::Util::ServerApplication::waitForTerminationRequest();
        // TODO components cleanup
    }
    return (Poco::Util::Application::EXIT_OK);
}

void NodeApplication::defineOptions(Poco::Util::OptionSet &options) {
    Poco::Util::ServerApplication::defineOptions(options);

    // help
    options.addOption(
        Poco::Util::Option(
            "help", "h", "display help informations on cli arguments"
        )
        .required(false)
        .repeatable(false)
        .callback(
            Poco::Util::OptionCallback<NodeApplication>(
                this, &NodeApplication::handleHelp
            )
        )
    );

    options.addOption(
        Poco::Util::Option(
            "config", "", "load node settings from given .ini file"
        )
        .required(true)
        .repeatable(false)
        .argument("file")
        .callback(
            Poco::Util::OptionCallback<NodeApplication>(
                this, &NodeApplication::handleConfig
            )
        )
    );

}

void NodeApplication::handleHelp(const std::string& name, const std::string& value) {
    displayHelp();
    stopOptionsProcessing();
    _helpRequested = true;
}

void NodeApplication::displayHelp() {
    Poco::Util::HelpFormatter helpFrmt(options());
    helpFrmt.setCommand(commandName());
    helpFrmt.setUsage("<OPTIONS>");
    helpFrmt.setHeader("libdht sample node application.");
    helpFrmt.format(std::cout);
}

void NodeApplication::handleConfig(const std::string& name, const std::string& value) {
    loadConfiguration(value);
}

