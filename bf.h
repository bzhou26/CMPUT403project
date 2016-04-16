#pragma once
#include <vector>
#include <string>

class BF {
public:
    std::string needle;
    std::string haystack;
public:
    BF(std::string haystack_, std::string needle_);
    std::vector<size_t> search();
};