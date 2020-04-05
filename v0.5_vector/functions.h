#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <vector>

using namespace std;

struct mokinys{
    string vard, pav;
    int e, sum, n;              //egzamino rezultatas, nd suma, nd skaicius
    double vid, med, galv, galm, gal;       //nd vidurkis, nd mediana, galutiniai vidurkiai
    vector <double> nd;
};

bool exists(const char*);
void pgeneravimas(vector <mokinys> &, int);
void naujasFailas(vector <mokinys>, int, int);
void nuskaitymas(vector <mokinys> &, int &, int);
void skaiciavimas(vector <mokinys> &, int, string);
void paskirstymas(vector <mokinys> &, int , int, int);

#endif // FUNCTIONS_H
