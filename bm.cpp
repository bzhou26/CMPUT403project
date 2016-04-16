// https://github.com/zhuozhongcao/Boyer_Moore

#include "bm.h"

BM::BM(std::string _text, std::string _pattern) {
    pattern = _pattern;
    text = _text;
    initialize();
}

void BM::initBadCh() {
    int len = (int)pattern.length();
    for(int i = 0; i < Max_Char; i++) {
        badCh[i] = len;
    }
    for(int i = 0; i < len - 1; i++) {
        badCh[pattern[i]] = len - 1 - i;
    }
}

void BM::suffix(std::string pattern, int *suff) {
    int len = (int)pattern.length();
    int f = 0, g;
    suff[len - 1] = len;
    g = len - 1;
    for (int i = len - 2; i >= 0; --i) {
        if (i > g && suff[i + len - 1 - f] < i - g)
            suff[i] = suff[i + len - 1 - f];
        else {
            if (i < g) g = i;
            f = i;
            while (g >= 0 && pattern[g] == pattern[g + len - 1 - f]) --g;
            suff[i] = f - g;
        }
    }
}

void BM::initGoodStr() {
    int len = (int)pattern.length();
    int suff[len];
    if (goodStr.size() < len) {
        goodStr.insert(goodStr.end(), len-goodStr.size(), 0);
    }
    suffix(pattern, suff);
    for(int i = 0; i < len; i++) {
        goodStr[i] = len;
    }
    int j = 0;
    for(int i = len - 1; i >= 0; i--) {
        if(suff[i] == i + 1) {
            for(; j < len - 1 - i; j++) {
                if(goodStr[j] == len)
                    goodStr[j] = len - 1 - i;
            }
        }
    }
    for(int i = 0; i <= len - 2; i++) {
        goodStr[len - 1 - suff[i]] = len - 1 - i;
    }
}

void inline BM::initialize() {
    initBadCh();
    initGoodStr();
}

std::vector<int> BM::search() {
    std::vector<int> answer;
    int i, j = 0, n = (int)text.length(), m = (int)pattern.length();
    while(j <= n - m) {
        for(i = m - 1; i >= 0 && pattern[i] == text[i + j]; i--);
        if(i < 0) {
            answer.push_back(j);
            j += goodStr[0];
        } else {
            j += std::max(badCh[text[i + j]] - m + 1 + i, goodStr[i]);
        }
    }
    return answer;
}