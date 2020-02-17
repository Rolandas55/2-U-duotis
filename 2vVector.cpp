#include <iostream>
#include <iomanip>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

struct mokinys{
    string vard, pav;
    int e, sum, n;
    double vid, med, gal;
    vector <int> nd;
};

int main(){
    mokinys m;
    int y, x, z, i;           //kintamieji
    for(int i=0; i<20; i++){
        m.n=0;          //mokinio pazymiu skaicius
        m.sum=0;        //mokinio pazymiu suma
        m.vid=0;        //mokinio pazymiu vidurkis
        m.med=0;        //mokinio pazymiu mediana
        m.gal=0;        //mokinio pazymiu galutinis rezultatas
    }
    cout << "Iveskite mokinio pavarde ir varda" << endl;
    cin >> m.vard >> m.pav;
    cout << "Jei norite suvesti mokinio pazymius iveskite '1', o jei norite juos generuoti '2'" << endl;
    cin >> x;
    if(x==1){
    cout << "Iveskite mokinio pazymius, o pabaigoje iveskite neigiama skaiciu" << endl;
    cin >> z;
    if(cin.fail()){
            cout << "Ivedete klaidingus duomenis" << endl;
        return 0;
        }
    m.nd.push_back(z);
    while(z>=0){
        cin >> z;
        if(cin.fail()){
            cout << "Ivedete klaidingus duomenis" << endl;
        return 0;
        }
        m.nd.push_back(z);
    }
    cout << "Iveskite egzamino rezultata" << endl;
    cin >> m.e;
    if(cin.fail()){
            cout << "Ivedete klaidingus duomenis" << endl;
        return 0;
        }
    }
    else if(x==2){
        cout << "kiek pazymiu norite generuoti?" << endl;
        cin >> m.n;
        if(cin.fail()){
            cout << "Ivedete klaidingus duomenis" << endl;
        return 0;
        }
        for(int i=0; i<m.n; i++){
            z=rand()%10+1;
            m.nd.push_back(z);
        }
        m.e=rand()%10+1;
    }
    else{
        cout << "Ivedete klaidingus duomenis" << endl;
        return 0;
    }
    for(auto i = m.nd.begin(); i != m.nd.end()-1; ++i)
        m.sum+=*i;
    sort(m.nd.begin(), m.nd.end());
    for(int i=0; i<m.nd.size()-1; i++){
        if((m.nd.size()-1)%2>0 and (m.nd.size()-1)/2+1==i)
            m.med=m.nd[i];
        else if((m.nd.size()-1)/2==i or (m.nd.size()-1)/2-1==i)
            m.med+=m.nd[i+1];
    }
    m.vid=(double)m.sum/(m.nd.size()-1);
    if((m.nd.size()-1)%2==0)
        m.med=m.med/2.0;
    m.gal=m.vid*0.4+m.e*0.6;
    cout << "Pavarde" << setw(10) << " " << setw(10) << left << "Vardas" << setw(20) << left << "Galutinis (Vid.)" << " / " << setw(20) << left << "Galutinis (Med.)" << endl;
    cout << string(60, '-') << endl;
    cout <<  m.pav << setw(10) << " " << setw(10) << m.vard << " ";
    cout << fixed << setprecision(2) << setw(20) << left << m.gal << " " << fixed << setprecision(2) << left << m.med << endl;

    return 0;
}
