
SET (NODE_SRC main.cpp nodeListener.cpp nodeLogger.cpp nodeClient.cpp)

# node version
SET (NODE_VERSION_MAJOR 0)
SET (NODE_VERSION_MINOR 0)
SET (NODE_VERSION_BUILD 1)

SET (DEFAULT_LOG_LEVEL "debug")
SET (DEFAULT_LOG_FILE "/tmp/dhtNode.log")

CONFIGURE_FILE(
	"${PROJECT_SOURCE_DIR}/include/node/config.h.in"
	"${PROJECT_BINARY_DIR}/node/config.h"
)
INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}")

ADD_EXECUTABLE (node ${NODE_SRC})
TARGET_LINK_LIBRARIES (node PocoFoundation PocoNet PocoUtil dht)

