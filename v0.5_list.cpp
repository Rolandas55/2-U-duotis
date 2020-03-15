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
#include <stdio.h>
#include <string.h>

using namespace std;

struct mokinys{
    string vard, pav;
    int e, sum, n;              //egzamino rezultatas, nd suma, nd skaicius
    double vid, med, galv, galm, gal;       //nd vidurkis, nd mediana, galutinis vidurkis
    list <double> nd;
};

void pgeneravimas(list <mokinys> &m, int x){
    for(list <mokinys> :: iterator it=m.begin(); it!=m.end(); it++){
        for(int i=0; i<it->n; i++){
            int z=rand()%10+1;
            it->nd.push_back(z);
        }
        it->e=rand()%10+1;
    }
}

void naujasFailas(list <mokinys> m, int psk, int k);
void nuskaitymas(list <mokinys> &m, int &C, int k);
void skaiciavimas(list <mokinys> &m, int C, string v);
void paskirstymas(list <mokinys> m, int C, int k);

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
        kel++;
        start = clock();
        nuskaitymas(m, C, kel);
        duration = (clock()-start)/(double)CLOCKS_PER_SEC;
        cout << "10000 eiluciu failas nuskaitytas per: " << duration << endl;
        skaiciavimas(m, C, v);
        paskirstymas(m, C, kel);
        kel++;
        start = clock();
        nuskaitymas(m, C, kel);
        duration = (clock()-start)/(double)CLOCKS_PER_SEC;
        cout << "100000 eiluciu failas nuskaitytas per: " << duration << endl;
        skaiciavimas(m, C, v);
        paskirstymas(m, C, kel);
        kel++;
        start = clock();
        nuskaitymas(m, C, kel);
        duration = (clock()-start)/(double)CLOCKS_PER_SEC;
        cout << "1000000 eiluciu failas nuskaitytas per: " << duration << endl;
        skaiciavimas(m, C, v);
        paskirstymas(m, C, kel);
        kel++;
        start = clock();
        nuskaitymas(m, C, kel);
        duration = (clock()-start)/(double)CLOCKS_PER_SEC;
        cout << "10000000 eiluciu failas nuskaitytas per: " << duration << endl;
        skaiciavimas(m, C, v);
        paskirstymas(m, C, kel);
    return 0;
    }
    else do{
    m.push_back(mokinys());
    list <mokinys>::iterator it = m.begin();
    cout << "Iveskite mokinio varda ir pavarde" << endl;
    cin >> it->vard >> it->pav;
    cout << "Jei norite suvesti mokinio pazymius iveskite '1', o jei norite juos generuoti '2'" << endl;
    cin >> x;
    if(x==1){
    cout << "Iveskite mokinio pazymius, o pabaigoje iveskite neigiama skaiciu" << endl;
    cin >> z;
    if(cin.fail()){
            cout << "Ivedete klaidingus duomenis" << endl;
        return 0;
        }
    it->nd.push_back(z);
    while(z>=0){
        cin >> z;
        if(cin.fail()){
            cout << "Ivedete klaidingus duomenis" << endl;
        return 0;
        }
        it->nd.push_back(z);
    }
    cout << "Iveskite egzamino rezultata" << endl;
    cin >> it->e;
    if(cin.fail()){
            cout << "Ivedete klaidingus duomenis" << endl;
        return 0;
        }
    }
    else if(x==2){
        cout << "kiek pazymiu norite generuoti?" << endl;
        cin >> it->n;
        if(cin.fail()){
            cin.clear();
            cin.ignore(500, '\n');
            cout << "Ivedete klaidingus duomenis" << endl;
        }
        pgeneravimas(m, C);
    }
    else{
        cout << "Ivedete klaidingus duomenis" << endl;
        return 0;
    }

    cout << "Jei norite ivesti mokini iveskite 't', jei ne 'n'" << endl;
    cin >> v;
    C++;
    it++;
    }while(v=="t");
    skaiciavimas(m, C, v);
    paskirstymas(m, C, kel);

    return 0;
}

void naujasFailas(list <mokinys> m, int psk, int k){
    string name;
    list <mokinys> :: iterator it = m.begin();
    int fx=1000*pow(10, k);
    name = to_string(fx) + ".txt";
    ofstream fr1(name.c_str());
    fr1 << left << setw(20) << "Pavarde" << setw(20) << "Vardas";
    for(int i=0; i<psk; i++)
    fr1 << "ND" << setw(8) << 1+i;
    fr1 << setw(10) << "Egz." << endl;
    cout << "daviau pirma eil" << endl;
    for(int j=0; j<fx; j++){
        cout << "as funkcijoj" << endl;
        m.push_back(mokinys());
        cout << "papusinau" << endl;
        it->n = psk;
        cout << "daviau pirma reiksme" << endl;
        //it->pav = "Pavarde";
        cout << "daviau ir antra reiksme" << endl;
        it->vard = "Vardas";
        cout << "pliusuosiu" << endl;
        it++;
        cout << "apejom rateli" << endl;
    }
    cout << "daviau puse reiksmes" << endl;
    it = m.begin();
    for(int j=0; j<fx; j++){                      //pazymiu generavimas
        for(int i=0; i<it->n; i++){
            int z=rand()%10+1;
            it->nd.push_back(z);
        }
        it->e=rand()%10+1;
        it++;
    }
    cout << "daviau reiksmes" << endl;
    it = m.begin();
    for(int i=0; i<fx; i++){                    //Rasymas i faila
        fr1 << it->pav << setw(13) << 1+i << it->vard << setw(14) << i+1;
        for(list <double> :: iterator it2 = it->nd.begin(); it2!=it->nd.end(); it2++)
            fr1 << setw(10) << *it2;
        fr1 << setw(10) << it->e << endl;
        it++;
    }
    fr1.close();
}

void nuskaitymas(list <mokinys> &m, int &C, int k){
    list <mokinys> :: iterator it = m.begin();
    C=0;
    char c; int words = -3; bool space = true; int ND;
    int fx=1000*pow(10, k);
    string name = to_string(fx) + ".txt";
    ifstream fd(name.c_str());
    while(fd.get(c) and c!='\n'){           //skaiciuoja kiek nd
        if(std::isspace(c)){
            space=true;
        }
        else if(space){
            words++;
            space=false;
        }
    }
    while(!fd.eof()){                       //nuskaito duomenis is failo
        m.push_back(mokinys());
        it->n=words;
        fd >> it->vard >> it->pav;
        for(int i=0; i<words; i++){
            fd >> ND;
            it->nd.push_back(ND);
        }
        fd >> it->e;
        C++;
        it++;
    }
}

void skaiciavimas(list <mokinys> &m, int C, string v){

    for(list <mokinys> :: iterator it=m.begin(); it!=m.end(); it++){             //rezultatu skaiciavimai
    for(list <double> :: iterator it2 = it->nd.begin(); it2!=it->nd.end(); it2++)
        it->sum+=*it2;
    it->nd.sort();
    for(list <double> :: iterator it2 = it->nd.begin(); it2!=it->nd.end(); it2++){
            int i=0;
        if((it->nd.size())%2>0 and (it->nd.size())/2==i)
            it->med=*it2;
        else if((it->nd.size())/2==i or (it->nd.size()/2)-1==i)
            it->med+=*it2;
        i++;
    }

    it->vid=it->sum/(it->nd.size());
    if((it->nd.size())%2==0)
        it->med=it->med/2.0;
    it->galv=it->vid*0.4+it->e*0.6;
    it->galm=it->med*0.4+it->e*0.6;

    if(v=="v") it->gal=it->galv;
    if(v=="m") it->gal=it->galm;
    }
}

void paskirstymas(list <mokinys> m, int C, int k){
    clock_t start; double duration;
    list <mokinys> :: iterator it=m.begin();
    string name1, name2;
    list <mokinys> gal, bic;
    list <mokinys> :: iterator itg=gal.begin();
    list <mokinys> :: iterator itb=bic.begin();
    int C1=0, C2=0; //galvociu ir biciuliu skaicius
    name1 = "biciuliai" + to_string(k+1) + ".txt";
    name2 = "galvociai" + to_string(k+1) + ".txt";
    ofstream frb(name1.c_str());
        frb << left << setw(20) << "Pavarde" << setw(20) << "Vardas";
        for(int i=0; i<it->n; i++)
        frb << "ND" << setw(8) << 1+i;
        frb << setw(8) << "Egz." << endl;

    ofstream frg(name2.c_str());
        frg << left << setw(20) << "Pavarde" << setw(20) << "Vardas";
        for(int i=0; i<it->n; i++)
        frg << "ND" << setw(8) << 1+i;
        frg << setw(8) << "Egz." << endl;
    start = clock();
    for(it=m.begin(); it!=m.end(); it++){
        if(it->gal>=5){
            gal.push_back(mokinys());
            *itg=*it;
            itg++;
        }
        else{
            bic.push_back(mokinys());
            *itb=*it;
            itb++;
        }
    }
    duration = (clock()-start)/(double)CLOCKS_PER_SEC;
    int eil=100;
    string eilutes;
    for(int i=0; i<k+1; i++) eil=eil*10;
    eilutes = to_string(eil);
        cout << eilutes << " eiluciu failas suskirstytas per: " << duration << endl;
    for(it=m.begin(); it!=m.end(); it++){                                //iraso gudrocius
            frg << setw(20) << it->pav << setw(20) << it->vard;
            for(list <double> :: iterator it2 = it->nd.begin(); it2!=it->nd.end(); it2++)
                frg << setw(10) << *it2;
            frg << setw(10) << it->e << endl;
        }
    for(it=m.begin(); it!=m.end(); it++){                               //iraso biciulius
            frb << setw(20) << it->pav << setw(20) << it->vard;
            for(list <double> :: iterator it2 = it->nd.begin(); it2!=it->nd.end(); it2++)
                frb << setw(10) << *it2;
            frb << setw(10) << it->e << endl;
        }
        eil=100;
        for(int i=0; i<k+1; i++) eil=eil*10;
        eilutes = to_string(eil);
        frb.close(); frg.close();
}
