#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <list>

using namespace std;

struct mokinys{
    string vard, pav;
    int e, sum, n, kl;              //egzamino rezultatas, nd suma, nd skaicius
    double vid, med, galv, galm, gal;       //nd vidurkis, nd mediana, galutiniai vidurkiai
    list <double> nd;
};

bool exists(const char*);
void pgeneravimas(list <mokinys> &, int);
void naujasFailas(list <mokinys>, int, int);
void nuskaitymas(list <mokinys> &, int &, int);
void skaiciavimas(list <mokinys> &, int, string);
void paskirstymas(list <mokinys> &, int , int);

#endif // FUNCTIONS_H
