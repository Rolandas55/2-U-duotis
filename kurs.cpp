#include "kurs.h"
#include<fstream>

using namespace std;

bool exists(const char *file){
    ifstream infile(file);
    return infile.good();
}

