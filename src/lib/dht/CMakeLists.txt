SET (LIBDHT_SRC hash.cpp localnode.cpp node.cpp nodeConfigBase.cpp nodeConfigIni.cpp request.cpp requestlist.cpp routingTable.cpp routingTableEntry.cpp version.cpp)

# lib version
SET (LIBDHT_VERSION_MAJOR 0)
SET (LIBDHT_VERSION_MINOR 0)
SET (LIBDHT_VERSION_BUILD 1)

CONFIGURE_FILE(
	"${PROJECT_SOURCE_DIR}/include/libdht/config.h.in"
	"${PROJECT_BINARY_DIR}/libdht/config.h"
)
INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}")

#ADD_LIBRARY (dht-static STATIC ${LIBDHT_SRC})
ADD_LIBRARY (dht SHARED ${LIBDHT_SRC})

TARGET_LINK_LIBRARIES(dht ${Poco_LIBRARIES})

