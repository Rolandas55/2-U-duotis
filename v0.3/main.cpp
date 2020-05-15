#include <iostream>
#include <iomanip>
#include <vector>
#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include "kurs.h"
#include "struktura.h"


using namespace std;

int main(){
    vector<mokinys> m;
    ifstream fd("kursiokai.txt");
    int x, i, C=0,                 //kintamieji, C=mokiniu skaicius
    inp=0, words=-3;                //duomenu ivedimo tipas, nd pazymiu skaicius
    float z, ND;
    bool space=true;                 //iesko tarpu
    char v, c, vp='k';                          //kintamasis
    while(inp>2 or inp<1){
        cout << "Jei norite ivesti duomenis, iveskite '1', o jei nuskaityti is failo, iveskite '2'" << endl;
        cin >> inp;
        if(cin.fail()){
            cin.clear();
            cin.ignore(500, '\n');
            cout << "Ivedete klaidingus duomenis" << endl;
        }
    }

    if(inp==1){                     //Duomenu ivedimas ranka
    do{
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
    m[C].nd.push_back(z);
    while(z>=0){
        cin >> z;
        if(cin.fail()){
        cin.clear();
        cin.ignore(500, '\n');
        cout << "Ivedete klaidingus duomenis" << endl;
        }
        if(z>0){
        m[C].nd.push_back(z);
        }
    }

    while(m[C].e<=0 or m[C].e>10){
    cout << "Iveskite egzamino rezultata" << endl;
    cin >> m[C].e;
    if(cin.fail()){
        cin.clear();
        cin.ignore(500, '\n');
        cout << "Ivedete klaidingus duomenis" << endl;
    }
    }
    }
    else if(x==2){
        cout << "kiek pazymiu norite generuoti?" << endl;
        cin >> m[C].n;
        if(cin.fail()){
            cout << "Ivedete klaidingus duomenis" << endl;
        return 0;
        }
        for(i=0; i<m[C].n; i++){
            z=rand()%10+1;
            m[C].nd.push_back(z);
        }
        m[C].e=rand()%10+1;
    }
    else{
        cout << "Ivedete klaidingus duomenis" << endl;
        return 0;
    }
    v='p';
    while(v!='t' and v!='n'){
    cout << "Jei norite ivesti mokini iveskite 't', jei ne 'n'" << endl;
    cin >> v;
    if(cin.fail()){
        cin.clear();
        cin.ignore(500, '\n');
        cout << "Ivedete klaidingus duomenis" << endl;
    }
    }
    C++;
    }while(v=='t');
    }
    else{                           //Duomenu nuskaitymas is failo
        if(!exists("kursiokai.txt")){
        cout << "klaidingas duomenu failas" << endl;
        return 0;
    }
        while(fd.get(c) and c!='\n'){
        if(std::isspace(c)){
            space=true;
        }
        else if(space){
            words++;
            space=false;
        }
    }

    while(!fd.eof()){
        m.push_back(mokinys());
        fd >> m[C].vard >> m[C].pav;
        for(i=0; i<words; i++){
            fd >> ND;
            m[C].nd.push_back(ND);
        }
        fd >> m[C].e;
        C++;
    }

    while(1){
        cout << "Jei norite rusiuoti pagal vardus iveskite 'v', jei pagal pavardes 'p'" << endl;
        cin >> vp;
        if(vp=='p' or vp=='v'){
    if(vp=='p'){
        sort(m.begin(), m.end(), [](const mokinys& a, const mokinys& b){
        return a.pav < b.pav;
        });
    }
    if(vp=='v'){
        sort(m.begin(), m.end(), [](const mokinys& a, const mokinys& b){
        return a.vard < b.vard;
        });
        }
    break;
    }
        else{
            cin.clear();
            cin.ignore(500, '\n');
            cout << "Ivedete klaidingus duomenis" << endl;
        }
    }

    }
    for(int j=0; j<C; j++){             //rezultatu skaiciavimai
    for(auto i = m[j].nd.begin(); i != m[j].nd.end(); ++i)
        m[j].sum+=*i;
    sort(m[j].nd.begin(), m[j].nd.end());
    for(i=0; i<m[j].nd.size(); i++){
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

    while(v!='v' and v!='m'){
        cout << "Jei norite galutinio balo kaip vidurkio iveskite 'v' jei kaip medianos 'm'" << endl;
        cin >> v;
        if(cin.fail()){
            cin.clear();
            cin.ignore(500, '\n');
            cout << "Ivedete klaidingus duomenis" << endl;
        }
    }
    if(v=='v'){
    cout << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis (Vid.)" << endl;
    cout << string(50, '-') << endl;
    for(int i=0; i<C; i++){
    cout << left << setw(20) << m[i].pav << setw(20) << m[i].vard;
    cout << fixed << setprecision(2) << setw(20) << m[i].galv << endl;
    }
    }
    else{
    cout << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis (Med.)" << endl;
    cout << string(50, '-') << endl;
    for(int i=0; i<C; i++){
    cout << left << setw(20) << m[i].pav << setw(20) << m[i].vard;
    cout << fixed << setprecision(2) << setw(20) << m[i].galm << endl;
    }
    }
    return 0;
}
