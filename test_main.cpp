#include "bm.h"
#include "kmp.h"
#include "bf.h"
#include <fstream>
#include <streambuf>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[]){
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Test Start..." << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::vector<int> result_bm;
    std::vector<size_t> result_kmp, result_bf;
    /* read input file */
    clock_t tstart1 = clock();
    std::ifstream t("test.in");
    std::string str((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());
    printf("Reading file costs: %.5fs\n", (double) (clock() - tstart1)/CLOCKS_PER_SEC);
    std::cout << "-----------------------------" << std::endl;
    /* create pattern for testing */
    std::string pattern = "";
    if (argc == 2){
        pattern = std::string(argv[1]);
        std::cout << "Search for: " << std::string(argv[1]) << std::endl;
        std::cout << "-----------------------------" << std::endl;
    } else if (argc < 2){
        for (int i = 0; i < 100; i++) {
            pattern += str[i];
        }
        std::cout << "Search for first 100 characters in the input file " << std::endl;
        std::cout << "-----------------------------" << std::endl;
    } else {
        std::cout << "Please type string as one parameter or leave it blank to search" << std::endl;
    }
    /* Boyer-Moore test */
    BM bm(str, pattern);
    clock_t tstart2 = clock();
    result_bm = bm.search();
    std::cout << "Boyer-Moore Algorithm Found: " << result_bm.size() << std::endl;
    printf("Boyer-Moore costs: %.5fs\n", (double) (clock() - tstart2)/CLOCKS_PER_SEC);
    std::cout << "-----------------------------" << std::endl;
    /* Knuth–Morris–Pratt test */
    KMP kmp(str, pattern);
    clock_t tstart3 = clock();
    result_kmp = kmp.search();
    std::cout << "KMP Algorithm Found: " << result_kmp.size() << std::endl;
    printf("KMP costs: %.5fs\n", (double) (clock() - tstart3)/CLOCKS_PER_SEC);
    std::cout << "-----------------------------" << std::endl;
    /* Brute Force test */
    BF bf(str, pattern);
    clock_t tstart4 = clock();
    result_bf = bf.search();
    std::cout << "BruteForce Algorithm Found: " << result_bf.size() << std::endl;
    printf("BruteForce costs: %.5fs\n", (double) (clock() - tstart4)/CLOCKS_PER_SEC);
    std::cout << "-----------------------------" << std::endl;
    t.close();
    return 0;
}