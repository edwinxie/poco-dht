#ifndef NODE_LISTENER_H
#define NODE_LISTENER_H

#include "libdht/nodeConfigIni.h"

#include <Poco/Net/DatagramSocket.h>
#include <Poco/Net/SocketAddress.h>
#include <Poco/AutoPtr.h>
#include <Poco/Net/SocketNotification.h>
#include <Poco/Net/SocketReactor.h>
#include <Poco/Runnable.h>
#include <Poco/RWLock.h>
#include <Poco/Thread.h>

#include <string>

class NodeListener : public Poco::Runnable {
    public:
        NodeListener(libdht::NodeConfigIni *cfg, Poco::RWLock *lock);
        virtual ~NodeListener();

        void    run();
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

        libdht::NodeConfigIni       *_config;
        Poco::RWLock                *_lock;
};

#endif /* NODE_LISTENER_H */

