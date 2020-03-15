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

using namespace std;

struct mokinys{
    string vard, pav;
    int e, sum, n;              //egzamino rezultatas, nd suma, nd skaicius
    double vid, med, galv, galm, gal;       //nd vidurkis, nd mediana, galutinis vidurkis
    vector <double> nd;
};

void pgeneravimas(vector <mokinys> &m, int x){
    for(int i=0; i<m[x].n; i++){
            int z=rand()%10+1;
            m[x].nd.push_back(z);
        }
        m[x].e=rand()%10+1;
}

void naujasFailas(vector <mokinys> m, int psk, int k);
void nuskaitymas(vector <mokinys> &m, int &C, int k);
void skaiciavimas(vector <mokinys> &m, int C, string v);
void paskirstymas(vector <mokinys> m, int C, int k);

int main(){
    vector <mokinys> m;
    int y, x, z, i, j, C=0, gen=0, psk, kel=0;            //kintamieji, C=mokiniu skaicius, pazymiu sk, generuojamu mokiniu sk, kelintas failas
    string v;                       //kintamasis
    double duration, duration1;
    clock_t start, start1;
    chrono::steady_clock time;
    while(gen!=1 and gen!=2 and gen!=3){
        cout << "Jei norite generuoti failus iveskite '1', jei nuskaityti '2', o jei ivesti ranka '3'" << endl;
        cin >> gen;
        if(cin.fail()){chrono::steady_clock sc;
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
    start = clock();
    naujasFailas(m, psk, kel);
    duration = (clock()-start)/(double)CLOCKS_PER_SEC;
    cout << "1000 eiluciu failas sukurtas per: " << duration << endl;
    kel++;
    start = clock();
    naujasFailas(m, psk, kel);
    duration = (clock()-start)/(double)CLOCKS_PER_SEC;
    cout << "10000 eiluciu failas sukurtas per: " << duration << endl;
    kel++;
    start = clock();
    naujasFailas(m, psk, kel);
    duration = (clock()-start)/(double)CLOCKS_PER_SEC;
    cout << "100000 eiluciu failas sukurtas per: " << duration << endl;
    kel++;
    start = clock();
    naujasFailas(m, psk, kel);
    duration = (clock()-start)/(double)CLOCKS_PER_SEC;
    cout << "1000000 eiluciu failas sukurtas per: " << duration << endl;
    kel++;
    start = clock();
    naujasFailas(m, psk, kel);
    duration = (clock()-start)/(double)CLOCKS_PER_SEC;
    cout << "10000000 eiluciu failas sukurtas per: " << duration << endl;
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
        start1 = clock();
        start = clock();
        nuskaitymas(m, C, kel);
        duration = (clock()-start)/(double)CLOCKS_PER_SEC;
        cout << "1000 eiluciu failas nuskaitytas per: " << duration << endl;
        skaiciavimas(m, C, v);
        paskirstymas(m, C, kel);
        duration1 = (clock()-start1)/(double)CLOCKS_PER_SEC;
        cout << endl << "1000 irasu testo laikas: " << duration1 << endl << endl;
        kel++;
        start1 = clock();
        start = clock();
        nuskaitymas(m, C, kel);
        duration = (clock()-start)/(double)CLOCKS_PER_SEC;
        cout << "10000 eiluciu failas nuskaitytas per: " << duration << endl;
        skaiciavimas(m, C, v);
        paskirstymas(m, C, kel);
        duration1 = (clock()-start1)/(double)CLOCKS_PER_SEC;
        cout << endl << "10000 irasu testo laikas: " << duration1 << endl << endl;
        kel++;
        start1 = clock();
        start = clock();
        nuskaitymas(m, C, kel);
        duration = (clock()-start)/(double)CLOCKS_PER_SEC;
        cout << "100000 eiluciu failas nuskaitytas per: " << duration << endl;
        skaiciavimas(m, C, v);
        paskirstymas(m, C, kel);
        duration1 = (clock()-start1)/(double)CLOCKS_PER_SEC;
        cout << endl << "100000 irasu testo laikas: " << duration1 << endl << endl;
        kel++;
        start1 = clock();
        start = clock();
        nuskaitymas(m, C, kel);
        duration = (clock()-start)/(double)CLOCKS_PER_SEC;
        cout << "1000000 eiluciu failas nuskaitytas per: " << duration << endl;
        skaiciavimas(m, C, v);
        paskirstymas(m, C, kel);
        cout << endl << "1000000 irasu testo laikas: " << duration1 << endl << endl;
        kel++;
        duration1 = (clock()-start1)/(double)CLOCKS_PER_SEC;
        start1 = clock();
        start = clock();
        nuskaitymas(m, C, kel);
        duration = (clock()-start)/(double)CLOCKS_PER_SEC;
        cout << "10000000 eiluciu failas nuskaitytas per: " << duration << endl;
        skaiciavimas(m, C, v);
        paskirstymas(m, C, kel);
        duration1 = (clock()-start1)/(double)CLOCKS_PER_SEC;
        cout << endl << "10000000 irasu testo laikas: " << duration1 << endl << endl;
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
            cout << "Ivedete klaidingus duomenis" << endl;
        return 0;
        }
    m[C].nd.push_back(z);
    while(z>=0){
        cin >> z;
        if(cin.fail()){
            cout << "Ivedete klaidingus duomenis" << endl;
        return 0;
        }
        m[C].nd.push_back(z);
    }
    cout << "Iveskite egzamino rezultata" << endl;
    cin >> m[C].e;
    if(cin.fail()){
            cout << "Ivedete klaidingus duomenis" << endl;
        return 0;
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
        cout << "Ivedete klaidingus duomenis" << endl;
        return 0;
    }

    cout << "Jei norite ivesti mokini iveskite 't', jei ne 'n'" << endl;
    cin >> v;
    C++;
    }while(v=="t");
    skaiciavimas(m, C, v);
    paskirstymas(m, C, kel);

    return 0;
}

void naujasFailas(vector <mokinys> m, int psk, int k){
    string name;
    int fx=1000*pow(10, k);
    name = to_string(fx) + ".txt";
    ofstream fr1(name.c_str());
    fr1 << left << setw(20) << "Pavarde" << setw(20) << "Vardas";
    for(int i=0; i<psk; i++)
    fr1 << "ND" << setw(8) << 1+i;
    fr1 << setw(10) << "Egz." << endl;
    for(int i=0; i<fx; i++){
        m.push_back(mokinys());
        m[i].n = psk;
        m[i].pav ="Pavarde";
        m[i].vard="Vardas";
    }
    for(int j=0; j<fx; j++){                      //pazymiu generavimas
        for(int i=0; i<m[j].n; i++){
            int z=rand()%10+1;
            m[j].nd.push_back(z);
        }
        m[j].e=rand()%10+1;
    }
    for(int i=0; i<fx; i++){                    //Rasymas i faila
        fr1 << m[i].pav << setw(13) << 1+i << m[i].vard << setw(14) << i+1;
        for(int j=0; j<psk; j++)
            fr1 << setw(10) << m[i].nd[j];
        fr1 << setw(10) << m[i].e << endl;
    }
    fr1.close();
}

void nuskaitymas(vector <mokinys> &m, int &C, int k){
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
        m[C].n=words;
        fd >> m[C].vard >> m[C].pav;
        for(int i=0; i<words; i++){
            fd >> ND;
            m[C].nd.push_back(ND);
        }
        fd >> m[C].e;
        C++;
    }
}

void skaiciavimas(vector <mokinys> &m, int C, string v){
    for(int j=0; j<C; j++){             //rezultatu skaiciavimai
    for(int i=0; i<m[j].n; ++i)
        m[j].sum+=i;
    sort(m[j].nd.begin(), m[j].nd.end());
    for(int i=0; i<m[j].n; i++){
        if((m[j].nd.size())%2>0 and (m[j].nd.size())/2==i)
            m[j].med=m[j].nd[i];
        else if((m[j].nd.size())/2==i or (m[j].nd.size())/2-1==i)
            m[j].med+=m[j].nd[i+1];
    }

    m[j].vid=m[j].sum/(m[j].nd.size());
    if((m[j].nd.size())%2==0)
        m[j].med=m[j].med/2.0;
    m[j].galv=m[j].vid*0.4+m[j].e*0.6;
    m[j].galm=m[j].med*0.4+m[j].e*0.6;
    }

    for(int i=0; i<C; i++){
        if(v=="v") m[i].gal=m[i].galv;
        if(v=="m") m[i].gal=m[i].galm;
    }
}

void paskirstymas(vector <mokinys> m, int C, int k){
    clock_t start; double duration;
    string name1, name2;
    vector <mokinys> gal, bic;
    int C1=0, C2=0; //galvociu ir biciuliu skaicius
    name1 = "biciuliai" + to_string(k+1) + ".txt";
    name2 = "galvociai" + to_string(k+1) + ".txt";
    ofstream frb(name1.c_str());
        frb << left << setw(20) << "Pavarde" << setw(20) << "Vardas";
        for(int i=0; i<m[0].n; i++)
        frb << "ND" << setw(8) << 1+i;
        frb << setw(8) << "Egz." << endl;

    ofstream frg(name2.c_str());
        frg << left << setw(20) << "Pavarde" << setw(20) << "Vardas";
        for(int i=0; i<m[0].n; i++)
        frg << "ND" << setw(8) << 1+i;
        frg << setw(8) << "Egz." << endl;
        start = clock();
    for(int i=0; i<C-1; i++){
        if(m[i].gal>=5){
            gal.push_back(mokinys());
            gal[C1]=m[i];
            C1++;
        }
        else{
            bic.push_back(mokinys());
            bic[C2]=m[i];
            C2++;
        }
    }
    duration = (clock()-start)/(double)CLOCKS_PER_SEC;
    int eil=100;
    string eilutes;
    for(int i=0; i<k+1; i++) eil=eil*10;
    eilutes = to_string(eil);
        cout << eilutes << " eiluciu failas suskirstytas per: " << duration << endl;
        start = clock();
    for(int i=0; i<C1; i++){                                //iraso gudrocius
            frg << setw(20) << gal[i].pav << setw(20) << gal[i].vard;
            for(int j=0; j<gal[i].n; j++)
                frg << setw(10) << gal[i].nd[j];
            frg << setw(10) << gal[i].e << endl;
        }
    for(int i=0; i<C2; i++){                               //iraso biciulius
            frb << setw(20) << bic[i].pav << setw(20) << bic[i].vard;
            for(int j=0; j<bic[i].n; j++)
                frb << setw(10) << bic[i].nd[j];
            frb << setw(10) << bic[i].e << endl;
        }
        duration = (clock()-start)/(double)CLOCKS_PER_SEC;
        eil=100;
        for(int i=0; i<k+1; i++) eil=eil*10;
        eilutes = to_string(eil);
        frb.close(); frg.close();
        cout << eilutes << " eiluciu failas irasytas i 2 failus per: " << duration << endl;
}
