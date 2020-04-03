#include "funkcijos.h"
#include<fstream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;

bool exists(const char *file){
    ifstream infile(file);
    return infile.good();
}

void pgeneravimas(list <mokinys> &m, int x){
    for(list <mokinys> :: iterator it=m.begin(); it!=m.end(); it++){
        for(int i=0; i<it->n; i++){
            int z=rand()%10+1;
            it->nd.push_back(z);
        }
        it->e=rand()%10+1;
    }
}

void naujasFailas(list <mokinys> m, int psk, int k){
    string name;
    char vard[6] = {'V', 'a', 'r', 'd', 'a', 's'}, pav[7] = {'P', 'a', 'v', 'a', 'r', 'd', 'e'};
    int fx=1000*pow(10, k);
    name = to_string(fx) + ".txt";
    ofstream fr1(name.c_str());
    fr1 << left << setw(20) << "Pavarde" << setw(20) << "Vardas";
    for(int i=0; i<psk; i++)
    fr1 << "ND" << setw(8) << 1+i;
    fr1 << setw(10) << "Egz." << endl;
    m.push_back(mokinys());
    list <mokinys> :: iterator it = m.begin();
    for(int i=0; i<fx; i++){
        for(int j=0; j<6; j++){
            it->n = psk;
            it->pav.push_back(pav[j]);
            it->vard.push_back(vard[j]);
        }
        it->pav.push_back(pav[6]);
        m.push_back(mokinys());
        it++;
    }
    it--;
    it = m.begin();
    for(int j=0; j<fx; j++){                      //pazymiu generavimas
        for(int i=0; i<it->n; i++){
            int z=rand()%10+1;
            it->nd.push_back(z);
        }
        it->e=rand()%10+1;
        it++;
    }
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
    m.push_back(mokinys());
    list <mokinys> :: iterator it = m.begin();
    C=0;
    char c; int words = -3; bool space = true; int ND;
    int fx=1000*pow(10, k);
    string name = to_string(fx) + ".txt", vard, pav;
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

    for(int j=0; j<fx; j++){                       //nuskaito duomenis is failo
        m.push_back(mokinys());
        it->n=words;
        fd >> pav;
        char P[pav.length()];
        strcpy(P, pav.c_str());
        for(int i=0; i<pav.length(); i++)
            it->pav.push_back(P[i]);
        fd >> vard;
        char H[vard.length()];
        strcpy(H, vard.c_str());
        for(int i=0; i<vard.length(); i++)
            it->vard.push_back(H[i]);
        for(int i=0; i<words; i++){
            fd >> ND;
            it->nd.push_back(ND);
        }
        fd >> it->e;
        C++;
        it++;
    }
    m.pop_back();
}

void skaiciavimas(list <mokinys> &m, int C, string v){
    for(list <mokinys> :: iterator it=m.begin(); it!=m.end(); it++){             //rezultatu skaiciavimai
    for(list <double> :: iterator it2 = it->nd.begin(); it2!=it->nd.end(); it2++)
        it->sum+=*it2;
    it->nd.sort();
    int i=0;
    for(list <double> :: iterator it2 = it->nd.begin(); it2!=it->nd.end(); it2++){
        if(it->n%2>0 and it->n/2==i)
            it->med=*it2;
        else if(it->n/2==i or (it->n/2)-1==i)
            it->med+=*it2;
        i++;
    }

    it->vid=it->sum/it->n;
    if(it->n%2==0)
        it->med=it->med/2.0;
    it->galv=it->vid*0.4+it->e*0.6;
    it->galm=it->med*0.4+it->e*0.6;

    if(v=="v") it->gal=it->galv;
    if(v=="m") it->gal=it->galm;
    }
}

void paskirstymas(list <mokinys> &m, int C, int k){
    clock_t start; double duration;
    list <mokinys> :: iterator it=m.begin();
    string name1, name2;
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
            it->kl = 1;
        }
        else{
            it->kl = 2;
        }
    }
    duration = (clock()-start)/(double)CLOCKS_PER_SEC;
    int eil=100;
    string eilutes;
    for(int i=0; i<k+1; i++) eil=eil*10;
    eilutes = to_string(eil);
        cout << eilutes << " eiluciu failas suskirstytas per: " << duration << endl;
    for(list <mokinys> :: iterator it=m.begin(); it!=m.end(); it++){                                //iraso gudrocius
            if(it->kl==1){
            frg << setw(20) << it->pav << setw(20) << it->vard;
            for(list <double> :: iterator it2 = it->nd.begin(); it2!=it->nd.end(); it2++)
                frg << setw(10) << *it2;
            frg << setw(10) << it->e << endl;
            }
            else{                                                            //iraso biciulius
            frb << setw(20) << it->pav << setw(20) << it->vard;
            for(list <double> :: iterator it2 = it->nd.begin(); it2!=it->nd.end(); it2++)
                frb << setw(10) << *it2;
            frb << setw(10) << it->e  << endl;
            }
    }
        eil=100;
        for(int i=0; i<k+1; i++) eil=eil*10;
        eilutes = to_string(eil);
        frb.close(); frg.close();
}
