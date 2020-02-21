#include <iostream>
#include <iomanip>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

struct mokinys{
    string vard, pav;
    int e, sum, *nd, n;              //egzamino rezultatas, nd suma, nd, nd skaicius
    double vid, med, gal;       //nd vidurkis, nd mediana, galutinis visurkis
};

int main(){
    vector <mokinys> m;
    int y, x, z, i, C=0;            //kintamieji, C=mokiniu skaicius
    string v;                       //kintamasis

    do{
    m.push_back(mokinys());
    cout << "Iveskite mokinio pavarde ir varda" << endl;
    cin >> m[C].vard >> m[C].pav;
    cout << "Jei norite suvesti mokinio pazymius iveskite '1', o jei norite juos generuoti '2'" << endl;
    cin >> x;
    if(x==1){
    cout << "Iveskite mokinio pazymius, o pabaigoje iveskite neigiama skaiciu" << endl;
    //
    m[C].nd = new int [1];
    cin >> m[C].nd[m[C].n];
    if(cin.fail()){
            cout << "Ivedete klaidingus duomenis" << endl;
        return 0;
    }
    while(m[C].nd[m[C].n]>=0){
        m[C].n++;
        int *x;
        x = new int [m[C].n+1];
        cin >> x[m[C].n];
        if(cin.fail()){
            cout << "Ivedete klaidingus duomenis" << endl;
        return 0;
        }
        for(int i=0; i<m[C].n; i++)
            x[i]=m[C].nd[i];
        delete[] m[C].nd;
        m[C].nd = x;
    }
    //
    cout << "Iveskite egzamino rezultata" << endl;
    cin >> m[C].e;
    if(cin.fail()){
            cout << "Ivedete klaidingus duomenis" << endl;
        return 0;
        }
    }
    else if(x==2){                                          //generavimas
        cout << "kiek pazymiu norite generuoti?" << endl;
        cin >> m[C].n;
        if(cin.fail()){
            cout << "Ivedete klaidingus duomenis" << endl;
        return 0;
        }
        m[C].nd = new int [m[C].n];
        for(int i=0; i<m[C].n; i++){
            m[C].nd[i] = rand()%10+1;
        }
        m[C].e=rand()%10+1;
    }
    else{
        cout << "Ivedete klaidingus duomenis" << endl;
        return 0;
    }
    for(int i=0; i<m[C].n; i++)
        m[C].sum+=m[C].nd[i];
    for(int i=0; i<m[C].n; i++){
        for(int j=i; j<m[C].n; j++)
            if(m[C].nd[i]>m[C].nd[j]){
            y=m[C].nd[i];
            m[C].nd[i]=m[C].nd[j];
            m[C].nd[j]=y;
            }
        if(m[C].n%2>0 and m[C].n/2==i)
            m[C].med=m[C].nd[i];
        else if(m[C].n/2==i or m[C].n/2-1==i)
            m[C].med+=m[C].nd[i];
    }
    m[C].vid=(double)m[C].sum/m[C].n;
    if(m[C].n%2==0)
        m[C].med=m[C].med/2.0;
    m[C].gal=m[C].vid*0.4+m[C].e*0.6;
    cout << "Jei norite ivesti mokini iveskite 't', jei ne 'n'" << endl;
    cin >> v;
    C++;
    }while(v=="t");
    cout << "Jei norite galutinio balo kaip vidurkio iveskite 'v' jei kaip medianos 'm'" << endl;
    cin >> v;
    if(v=="v"){
    cout << "Pavarde" << setw(20) << " Vardas " << setw(20) << "Galutinis (Vid.)" << setw(20) << endl;
    cout << string(50, '-') << endl;
    for(i=0; i<C; i++){
    cout << m[i].pav << setw(20-m[i].vard.length()) << " " << m[i].vard;
    cout << fixed << setprecision(2) << setw(20) << right << m[i].gal << endl;
    }
    }
    else
    {
    cout << "Pavarde" << setw(20) << " Vardas " << setw(20) << "Galutinis (Med.)" << setw(20) << endl;
    cout << string(50, '-') << endl;
    for(i=0; i<C; i++){
    cout << m[i].pav << setw(20-m[i].vard.length()) << " " << m[i].vard;
    cout << fixed << setprecision(2) << setw(20) <<right << m[i].med << endl;
    }
    }

    return 0;
}
