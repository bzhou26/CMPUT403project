#pragma once

#include <iostream>
#include <string>
#include <vector>

#define Max_Char 266

class BM {

private:
    std::string pattern;
    std::string text;
    int badCh[Max_Char];
    std::vector<int> goodStr;

public:
    BM(std::string text, std::string pattern);       //constructor
    std::vector<int> search();

private:
    void initialize();
    void initBadCh();
    void initGoodStr();
    void suffix(std::string, int*);
};