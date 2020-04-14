#include <iostream>
#include <iomanip>
#include <vector>
#include <bits/stdc++.h>
#include <fstream>
#include <math.h>
#include <bits/stdc++.h>
#include <algorithm>
#include <ctime>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

using namespace std;

int main(){
    vector <mokinys> m;
    int y, x, z, i, j, C=0, gen=0, psk, kel=0, K=0;            //kintamieji, C=mokiniu skaicius, pazymiu sk, generuojamu mokiniu sk, kelintas failas
    string v;                       //kintamasis
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
    while(K!=1 and K!=2){
    cout << "Jei rezultatus norite talpinti i viena nauja koteineri iveskite '1' jei i du '2'" << endl;
        cin >> K;
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
        paskirstymas(m, C, kel, K);
        kel++;
        m.clear();
        start = clock();
        nuskaitymas(m, C, kel);
        duration = (clock()-start)/(double)CLOCKS_PER_SEC;
        cout << "10000 eiluciu failas nuskaitytas per: " << duration << endl;
        skaiciavimas(m, C, v);
        paskirstymas(m, C, kel, K);
        kel++;
        m.clear();
        start = clock();
        nuskaitymas(m, C, kel);
        duration = (clock()-start)/(double)CLOCKS_PER_SEC;
        cout << "100000 eiluciu failas nuskaitytas per: " << duration << endl;
        skaiciavimas(m, C, v);
        paskirstymas(m, C, kel, K);
        kel++;
        m.clear();
        start = clock();
        nuskaitymas(m, C, kel);
        duration = (clock()-start)/(double)CLOCKS_PER_SEC;
        cout << "1000000 eiluciu failas nuskaitytas per: " << duration << endl;
        skaiciavimas(m, C, v);
        paskirstymas(m, C, kel, K);
        kel++;
        m.clear();
        start = clock();
        nuskaitymas(m, C, kel);
        duration = (clock()-start)/(double)CLOCKS_PER_SEC;
        cout << "10000000 eiluciu failas nuskaitytas per: " << duration << endl;
        skaiciavimas(m, C, v);
        paskirstymas(m, C, kel, K);
    return 0;
    }
    else do{
    m.push_back(mokinys());
    cout << "Iveskite mokinio pavarde ir varda" << endl;
    cin >> m[C].vard >> m[C].pav;
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
    m[C].n++;
    m[C].nd.push_back(z);
    while(z>=0){
        cin >> z;
        if(cin.fail()){
        cin.clear();
        cin.ignore(500, '\n');
        cout << "Ivedete klaidingus duomenis" << endl;
    }
        m[C].n++;
        m[C].nd.push_back(z);
    }
    m[C].n--;
    cout << "Iveskite egzamino rezultata" << endl;
    cin >> m[C].e;
    if(cin.fail()){
        cin.clear();
        cin.ignore(500, '\n');
        cout << "Ivedete klaidingus duomenis" << endl;
    }
    }
    else if(x==2){
        cout << "kiek pazymiu norite generuoti?" << endl;
        cin >> m[C].n;
        if(cin.fail()){
            cin.clear();
            cin.ignore(500, '\n');
            cout << "Ivedete klaidingus duomenis" << endl;
        }
        pgeneravimas(m, C);
    }
    else{
        cin.clear();
        cin.ignore(500, '\n');
        cout << "Ivedete klaidingus duomenis" << endl;
    }

    cout << "Jei norite ivesti mokini iveskite 't', jei ne 'n'" << endl;
    cin >> v;
    if(cin.fail()){
        cin.clear();
        cin.ignore(500, '\n');
        cout << "Ivedete klaidingus duomenis" << endl;
    }
    C++;
    }while(v=="t");
    while(K!=1 and K!=2){
    cout << "Jei rezultatus norite talpinti i viena nauja koteineri iveskite '1' jei i du '2'" << endl;
        cin >> K;
        if(cin.fail()){
            cin.clear();
            cin.ignore(500, '\n');
            cout << "Ivedete klaidingus duomenis" << endl;
        }
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
    skaiciavimas(m, C, v);
    paskirstymas(m, C, kel, K);

    return 0;
}
