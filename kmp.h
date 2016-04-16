#pragma once
#include <vector>
#include <string>

class KMP {
public:
    std::string needle;
    std::string haystack;
public:
    KMP(std::string, std::string pattern);
    std::vector<size_t> search();
private:
    std::vector<size_t> knuthMorrisPrattTable();
};