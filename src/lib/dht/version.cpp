#include "libdht/version.h"

using namespace libdht;

Version::Version() {

}

Version::~Version() {

}

int Version::get() {
    return (1000 * LIBDHT_VERSION_MAJOR + 10 * LIBDHT_VERSION_MINOR + LIBDHT_VERSION_BUILD);
}


