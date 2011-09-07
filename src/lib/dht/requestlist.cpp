#include "libdht/requestlist.h"

using namespace libdht;

RequestList::RequestList() {

}

RequestList::~RequestList() {

}

Poco::UInt16 RequestList::count() {
    return ( (Poco::UInt16) _requestList.size());
}

void RequestList::clear() {
    _requestList.clear();
}

void  RequestList::append(Request &req) {
    _requestList.push_back(req);
}

