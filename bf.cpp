#include "bf.h"

BF::BF(std::string haystack_, std::string needle_) {
    haystack = haystack_;
    needle = needle_;
}

std::vector<size_t> BF::search() {
    std::vector<size_t> matches;
    if(needle.size() > haystack.size())
        return matches;
    size_t needleSize = needle.size();
    size_t maximumIndex = haystack.size() - needleSize;
    size_t needleIndex;
    for(size_t haystackIndex = 0; haystackIndex <= maximumIndex; haystackIndex++) {
        for(needleIndex = 0; needleIndex < needleSize && needle[needleIndex] == haystack[haystackIndex + needleIndex]; needleIndex++){};
        if(needleIndex == needleSize)
            matches.push_back(haystackIndex);
    }
    return matches;
}