/**
 * @file src/node/dataCore.cpp
 * @brief DataCore class implementation.
 */
#include "node/dataCore.h"

DataCore::DataCore() {

}

DataCore::~DataCore() {

}

void DataCore::setNodeListener(NodeListener *lst) {
    this->listener = lst;
}

NodeListener *DataCore::getNodeListener() {
    return (this->listener);
}


void DataCore::setNodeClient(NodeClient *clt) {
    this->client = clt;
}

NodeClient *DataCore::getNodeClient() {
    return (this->client);
}

