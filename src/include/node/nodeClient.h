#ifndef NODE_CLENT_H
#define NODE_CLENT_H

class NodeClient {
    public:
        NodeClient();
        virtual ~NodeClient();

        void runForEver();
        void stop();

    protected:
        bool    _running;
};

#endif /* NODE_CLENT_H */

