#include "libdht/requestlist.h"

using namespace libdht;

RequestList::RequestList() {

}

RequestList::~RequestList() {

}

int RequestList::count() {
    return (_requestList.size());
}

void RequestList::clear() {
    _requestList.clear();
}

void  RequestList::append(Request &req) {
    _requestList.push_back(req);
}

