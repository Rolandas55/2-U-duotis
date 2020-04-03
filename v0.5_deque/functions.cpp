#include "functions.h"
#include<fstream>
#include<cmath>
#include<iomanip>
#include<algorithm>

using namespace std;

bool exists(const char *file){
    ifstream infile(file);
    return infile.good();
}

void pgeneravimas(deque <mokinys> &m, int x){
    for(int i=0; i<m[x].n; i++){
            int z=rand()%10+1;
            m[x].nd.push_back(z);
        }
        m[x].e=rand()%10+1;
}

void naujasFailas(deque <mokinys> m, int psk, int k){
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

void nuskaitymas(deque <mokinys> &m, int &C, int k){
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

void skaiciavimas(deque <mokinys> &m, int C, string v){
    for(int j=0; j<C; j++){             //rezultatu skaiciavimai
    for(int i=0; i<m[j].n; ++i)
        m[j].sum+=m[j].nd[i];
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

void paskirstymas(deque <mokinys> &m, int C, int k){
    clock_t start; double duration;
    string name1, name2;
    deque <mokinys> gal, bic;
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
        eil=100;
        for(int i=0; i<k+1; i++) eil=eil*10;
        eilutes = to_string(eil);
        frb.close(); frg.close();
}
