#include "kmp.h"

KMP::KMP(std::string haystack_, std::string needle_){
    needle = needle_;
    haystack = haystack_;
}

std::vector<size_t> KMP::knuthMorrisPrattTable(){
    std::vector<size_t> initTable(needle.size() + 1, -1);
    for(size_t index = 1; index <= needle.size(); index++){
        size_t position = initTable[index - 1];
        while(position != -1 && needle[position] != needle[index - 1]){
            position = initTable[position];
        }
        initTable[index] = position + 1;
    }
    return initTable;
}

std::vector<size_t> KMP::search(){
    std::vector<size_t> matches;
    std::vector<size_t> table;
    table = knuthMorrisPrattTable();
    size_t haystackIndex = 0;
    size_t needleIndex = 0;
    size_t haystackSize = haystack.size();
    size_t needleSize = needle.size();
    while(haystackIndex < haystackSize){
        while(needleIndex != -1 && (needleIndex == needleSize || needle[needleIndex] != haystack[haystackIndex])){
            needleIndex = table[needleIndex];
        }
        needleIndex++;
        haystackIndex++;
        if(needleIndex == needleSize){
            matches.push_back(haystackIndex - needleSize);
        }
    }
    return matches;
}