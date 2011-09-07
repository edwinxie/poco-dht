#include "libdht/hash.h"

using namespace libdht;

Hash::Hash() {

}

Hash::~Hash() {

}

std::string Hash::md5Hex(const std::string &str) {
    Poco::MD5Engine           md5;
    Poco::DigestOutputStream  ostr(md5);

    ostr << str;
    ostr.flush();

    const Poco::DigestEngine::Digest &digest = md5.digest();

    return (Poco::DigestEngine::digestToHex(digest));
}

