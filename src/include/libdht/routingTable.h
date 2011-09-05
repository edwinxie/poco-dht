#ifndef LIBDHT_ROUTINGTABLE_H
#define LIBDHT_ROUTINGTABLE_H

#include "libdht/routingTableEntry.h"

#include <list>

namespace libdht {

    class RoutingTable {
        public:
            RoutingTable();
            ~RoutingTable();

        protected:
            std::list<RoutingTableEntry> _routingTable;
    };

}

#endif /* LIBDHT_ROUTINGTABLE_H */

