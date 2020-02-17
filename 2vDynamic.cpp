#include <iostream>
#include <iomanip>

using namespace std;

struct mokinys{
    string vard, pav;
    int *nd, e, sum, n;
    double vid, med, gal;
};

int main(){
    mokinys m;
    int y, x;           //kintamieji
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
    m.nd = new int [1];
    cin >> m.nd[m.n];
    if(cin.fail()){
            cout << "Ivedete klaidingus duomenis" << endl;
        return 0;
    }
    while(m.nd[m.n]>=0){
        m.n++;
        int *x;
        x = new int [m.n+1];
        cin >> x[m.n];
        if(cin.fail()){
            cout << "Ivedete klaidingus duomenis" << endl;
        return 0;
        }
        for(int i=0; i<m.n; i++)
            x[i]=m.nd[i];
        delete[] m.nd;
        m.nd = x;
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
        m.nd = new int [m.n];
        for(int i=0; i<m.n; i++){
            m.nd[i] = rand()%10+1;
        }
        m.e=rand()%10+1;
    }
    else{
        cout << "Ivedete klaidingus duomenis" << endl;
        return 0;
    }
    for(int i=0; i<m.n; i++)
        m.sum+=m.nd[i];
    for(int i=0; i<m.n; i++){
        for(int j=i; j<m.n; j++)
            if(m.nd[i]>m.nd[j]){
            y=m.nd[i];
            m.nd[i]=m.nd[j];
            m.nd[j]=y;
            }
        if(m.n%2>0 and m.n/2==i)
            m.med=m.nd[i];
        else if(m.n/2==i or m.n/2-1==i)
            m.med+=m.nd[i];
    }
    m.vid=(double)m.sum/m.n;
    if(m.n%2==0)
        m.med=m.med/2.0;
    m.gal=m.vid*0.4+m.e*0.6;
    cout << "Pavarde" << setw(10) << " " << setw(10) << left << "Vardas" << setw(20) << left << "Galutinis (Vid.)" << " / " << setw(20) << left << "Galutinis (Med.)" << endl;
    cout << string(60, '-') << endl;
    cout <<  m.pav << setw(10) << " " << setw(10) << m.vard << " ";
    cout << fixed << setprecision(2) << setw(20) << left << m.gal << " " << fixed << setprecision(2) << left << m.med << endl;

    return 0;
}
