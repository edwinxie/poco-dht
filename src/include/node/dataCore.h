/**
 * @file src/include/dataCore.h
 * @brief 'core' class storing pointers to our various components instances.
 */
#ifndef _DATACORE_H
#define _DATACORE_H

#include "nodeListener.h"
#include "nodeClient.h"

class DataCore {
    public:
        DataCore();
        virtual ~DataCore();

        void            setNodeListener(NodeListener *lst);
        NodeListener    *getNodeListener();

        void            setNodeClient(NodeClient *clt);
        NodeClient      *getNodeClient();

    protected:
        NodeListener    *listener;
        NodeClient      *client;

};

#endif /* _DATACORE_H */

