#ifndef NODE_LISTENER_H
#define NODE_LISTENER_H

#include <Poco/Util/ServerApplication.h>
#include <Poco/Net/DatagramSocket.h>
#include <Poco/Net/SocketAddress.h>
#include <Poco/AutoPtr.h>
#include <Poco/Net/SocketNotification.h>
#include <Poco/Net/SocketReactor.h>
#include <Poco/Thread.h>

#include <string>

class NodeListener : public Poco::Util::ServerApplication {
    public:
        NodeListener();
        virtual ~NodeListener();

        void    runForEver();
        void    stop();

    protected:
        bool    initialize(const std::string &hostPort);

        void    onReceivePacket(const Poco::AutoPtr<Poco::Net::ReadableNotification> &notif);

    private:
        bool    _running;

        Poco::Net::DatagramSocket   _listenSock;
        Poco::Net::SocketAddress    _listenSockAddr;

        Poco::Net::SocketReactor    _reactor;
        Poco::Thread                _reactorThread;
};

#endif /* NODE_LISTENER_H */

