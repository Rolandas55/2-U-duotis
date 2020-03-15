#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <deque>

using namespace std;

struct mokinys{
    string vard, pav;
    int e, sum, n;              //egzamino rezultatas, nd suma, nd skaicius
    double vid, med, galv, galm, gal;       //nd vidurkis, nd mediana, galutiniai vidurkiai
    deque <double> nd;
};

bool exists(const char*);
void pgeneravimas(deque <mokinys> &, int);
void naujasFailas(deque <mokinys>, int, int);
void nuskaitymas(deque <mokinys> &, int &, int);
void skaiciavimas(deque <mokinys> &, int, string);
void paskirstymas(deque <mokinys>, int , int);

#endif // FUNCTIONS_H
