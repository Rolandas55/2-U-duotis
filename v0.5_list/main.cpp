#include <iostream>
#include <iomanip>
#include <list>
#include <bits/stdc++.h>
#include <fstream>
#include <math.h>
#include <bits/stdc++.h>
#include <algorithm>
#include <ctime>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <string>
#include <iterator>
#include "funkcijos.h"

using namespace std;

int main(){
    list <mokinys> m;
    mokinys iks;
    int y, x, z, i, j, C=0, gen=0, psk, kel=0;            //kintamieji, C=mokiniu skaicius, pazymiu sk, generuojamu mokiniu sk, kelintas failas
    string v, vard, pav;                       //kintamasis
    double duration, duration1;
    clock_t start, start1;
    chrono::steady_clock time;
    chrono::steady_clock sc;
    while(gen!=1 and gen!=2 and gen!=3){
        cout << "Jei norite generuoti failus iveskite '1', jei nuskaityti '2', o jei ivesti ranka '3'" << endl;
        cin >> gen;
        if(cin.fail()){
            cin.clear();
            cin.ignore(500, '\n');
            cout << "Ivedete klaidingus duomenis" << endl;
        }
    }
    if(gen==1){
        cout << "kiek pazymiu norite generuoti?" << endl;
        cin >> psk;
        if(cin.fail()){
            cin.clear();
            cin.ignore(500, '\n');
            cout << "Ivedete klaidingus duomenis" << endl;
        }
    naujasFailas(m, psk, kel);
    kel++;
    naujasFailas(m, psk, kel);
    kel++;
    naujasFailas(m, psk, kel);
    kel++;
    naujasFailas(m, psk, kel);
    kel++;
    naujasFailas(m, psk, kel);
    }

    if(gen==1 or gen==2){
    if(!exists("1000.txt")){
        cout << "klaidingas duomenu failas" << endl;
        return 0;
    }
        while(v!="v" and v!="m"){
    cout << "Jei norite galutinio balo kaip vidurkio iveskite 'v' jei kaip medianos 'm'" << endl;
    cin >> v;
    if(cin.fail()){
        cin.clear();
        cin.ignore(500, '\n');
        cout << "Ivedete klaidingus duomenis" << endl;
    }
    }
        kel=0;
        start = clock();
        nuskaitymas(m, C, kel);
        duration = (clock()-start)/(double)CLOCKS_PER_SEC;
        cout << "1000 eiluciu failas nuskaitytas per: " << duration << endl;
        skaiciavimas(m, C, v);
        paskirstymas(m, C, kel);
        m.clear();
        kel++;
        start = clock();
        nuskaitymas(m, C, kel);
        duration = (clock()-start)/(double)CLOCKS_PER_SEC;
        cout << "10000 eiluciu failas nuskaitytas per: " << duration << endl;
        skaiciavimas(m, C, v);
        paskirstymas(m, C, kel);
        m.clear();
        kel++;
        start = clock();
        nuskaitymas(m, C, kel);
        duration = (clock()-start)/(double)CLOCKS_PER_SEC;
        cout << "100000 eiluciu failas nuskaitytas per: " << duration << endl;
        skaiciavimas(m, C, v);
        paskirstymas(m, C, kel);
        m.clear();
        kel++;
        start = clock();
        nuskaitymas(m, C, kel);
        duration = (clock()-start)/(double)CLOCKS_PER_SEC;
        cout << "1000000 eiluciu failas nuskaitytas per: " << duration << endl;
        skaiciavimas(m, C, v);
        paskirstymas(m, C, kel);
        m.clear();
        kel++;
        start = clock();
        nuskaitymas(m, C, kel);
        duration = (clock()-start)/(double)CLOCKS_PER_SEC;
        cout << "10000000 eiluciu failas nuskaitytas per: " << duration << endl;
        skaiciavimas(m, C, v);
        paskirstymas(m, C, kel);
        return 0;
    }
    else{
        m.push_back(mokinys());
        list <mokinys>::iterator it = m.begin();
        do{
    cout << "Iveskite mokinio varda ir pavarde" << endl;
    cin >> vard >> pav;
    char H[vard.length()];
        strcpy(H, vard.c_str());
        for(int i=0; i<vard.length(); i++)
            it->vard.push_back(H[i]);
    char P[pav.length()];
        strcpy(P, pav.c_str());
        for(int i=0; i<pav.length(); i++)
            it->pav.push_back(P[i]);
    cout << "Jei norite suvesti mokinio pazymius iveskite '1', o jei norite juos generuoti '2'" << endl;
    cin >> x;
    if(x==1){
    cout << "Iveskite mokinio pazymius, o pabaigoje iveskite neigiama skaiciu" << endl;
    cin >> z;
    if(cin.fail()){
            cin.clear();
            cin.ignore(500, '\n');
            cout << "Ivedete klaidingus duomenis" << endl;
        }
    it->nd.push_back(z);
    while(z>=0){
        cin >> z;
        if(cin.fail()){
            cin.clear();
            cin.ignore(500, '\n');
            cout << "Ivedete klaidingus duomenis" << endl;
        }
        it->nd.push_back(z);
    }
    cout << "Iveskite egzamino rezultata" << endl;
    cin >> it->e;
    if(cin.fail()){
            cin.clear();
            cin.ignore(500, '\n');
            cout << "Ivedete klaidingus duomenis" << endl;
        }
    }
    if(x==2){
        cout << "kiek pazymiu norite generuoti?" << endl;
        cin >> it->n;
        if(cin.fail()){
            cin.clear();
            cin.ignore(500, '\n');
            cout << "Ivedete klaidingus duomenis" << endl;
        }
        pgeneravimas(m, C);
    }
    cout << "Jei norite ivesti mokini iveskite 't', jei ne 'n'" << endl;
    cin >> v;
    if(cin.fail()){
            cin.clear();
            cin.ignore(500, '\n');
            cout << "Ivedete klaidingus duomenis" << endl;
        }
    C++;
    m.push_back(mokinys());
    it++;
    }while(v=="t");
    while(v!="v" and v!="m"){
    cout << "Jei norite galutinio balo kaip vidurkio iveskite 'v' jei kaip medianos 'm'" << endl;
    cin >> v;
        if(cin.fail()){
            cin.clear();
            cin.ignore(500, '\n');
            cout << "Ivedete klaidingus duomenis" << endl;
        }
    }
    kel=-1;
    }
    skaiciavimas(m, C, v);
    paskirstymas(m, C, kel);
    return 0;
}
