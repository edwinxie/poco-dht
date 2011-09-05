#ifndef LIBDHT_VERSION_H
#define LIBDHT_VERSION_H

#include "libdht/config.h"

namespace libdht {

    class Version {
        public:
            Version();
            ~Version();

            int get();
    };

}

#endif /* LIBDHT_VERSION_H */

