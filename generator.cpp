#include <iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <time.h>

using namespace std;
const unsigned int n_char = 1e9;
//const unsigned int n_char = 300; /* for test */

string alphanum = "0123456789"
        "!@#$%^&*()_-+={}[];:,.<>? "
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
string alphanum_still = "CMPUT403.";
int stringLength = alphanum.size();
int stillLength = alphanum_still.size();

string genString() {
    return alphanum_still;
}

char genRandom() {
    return alphanum[rand() % stringLength];
}

int main(int argc, char *argv[]) {
    int choose = 1;
    if (argc > 1){
        if (strcmp(argv[1], "1") == 0){
            choose = 1;
        } else if(strcmp(argv[1], "2") == 0){
            choose = 2;
        } else {
            cout << "Please choose string tpye by using parameter 1 or 2" << endl;
            return 0;
        }
    }
    if (argc == 3){
        alphanum_still = std::string(argv[2]);
        stillLength = alphanum_still.size();
        alphanum = std::string(argv[2]);
        stringLength = alphanum.size();
    }
    if (argc > 3){
        cout << "Too many arguments, please run again" << endl;
        return 0;
    }
    srand(time(0));
    std::string Str;
    clock_t tstart = clock();

    /* generate random string */
    if (choose == 1){
        cout << "Generating Random Strings..." << endl;
        for(unsigned int i = 0; i < n_char; ++i) {
            Str += genRandom();
        }
    } else {
        cout << "Generating Repeat Strings: \"" << alphanum_still << "\" ..." << endl;
        for(unsigned int i = 0; i < n_char/stillLength; ++i) {
            Str += genString();
        }
    }
    std::ofstream out("test.in");
    out << Str;
    out.close();
    printf("Generate Successful! \n");
    printf("Generate file costs: %.5fs\n", (double) (clock() - tstart)/CLOCKS_PER_SEC);
    return 0;
}
