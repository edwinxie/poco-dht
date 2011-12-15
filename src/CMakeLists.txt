PROJECT(node)

INCLUDE_DIRECTORIES ("include")

# where to look for our custom cmake modules:
SET(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

# look for local poco libraries installation:
FIND_PACKAGE(Poco COMPONENTS Foundation Net Util XML)
#LINK_DIRECTORIES(${Poco_LIBRARY_DIR})
#LINK_DIRECTORIES(${Poco_BINARY_DIR})

ADD_SUBDIRECTORY (lib)
ADD_SUBDIRECTORY (node)

