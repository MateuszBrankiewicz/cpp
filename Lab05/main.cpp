#include <iostream>
#include <string>
using namespace std;

void wczytajDane(string *tekst, string *wzor){
    cout<<"Podaj tekst:";
    getline(cin >> ws, *tekst);
    cout<<"Podaj wzor:";
    getline(cin >> ws, *wzor);
}

void naiwny(string t, string w, int dlt, int dlw){
    int i=0;
    while(i<=dlt-dlw){
        int j=0;
        while(j<dlw && w[j] == t[i+j]){
            j++;
        }
        if(j==dlw){
            cout<<i<<endl;
        }
        i++;
    }

}

void zbudujTablicaDopasowan(string w, int dlw, int *&p){
    p[0] = 0;
    p[1] = 0;
    int t = 0;
    int i = 1;
    while(i<dlw){
        while(t>0 && w[t]!=w[i]){
            t=p[t];
        }
        if(w[t]==w[i]){
            t++;
        }
        p[i+1] = t;
        i++;
    }
}

void KMP(string w, string t, int dlt, int dlw, int *p){
    int i=0;
    int j=0;
    while(i<=dlt-dlw+1){
        while(w[j]==t[i+j] && j<dlw){
            j++;
        }
        if(j==dlw){
            cout<<i<<endl;
        }
        i=i+max(1, j-p[j]);
        j=p[j];
    }

}
void zbudujTablicePrzesuniec(string w, int dlW, int *&p, char pocz, char kon){
    int n_pocz = (int)pocz;
    int n_kon = (int)kon;
    int i =0;
    while(i <= n_kon-n_pocz){
        p[i]=-1;
        i++;
    }
    i = 0;
    while(i < dlW){
        p[w[i]-n_pocz] = i;
        i++;
    }
}

void BM(string w, string t, int dlW, int dlT, int *p, char pocz){
    int n_pocz = (int)pocz;
    int i = 0;
    while(i<=dlT - dlW){
        int j=dlW-1;
        while(j>-1 && w[j] == t[i+j]){
            j--;
        }
        if(j==-1){
            cout<<i<<endl;
            i++;
        } else{
            i=i+max(1, j-p[t[i+j]-n_pocz]);
        }
    }
}

int main() {
    int wybor;
    int *tablicaDopasowan = nullptr;
    int *tablicaPrzesuniec = nullptr;
    string tekst;
    string wzorzec;
    int dlTxt, dlWz;
    char poczatek = 'a';
    char koniec = 'e';
    int dlugoscAlfabetu = int(koniec) - (int)poczatek + 1;
    cout<<dlugoscAlfabetu;

    do{
        cout<<"1) zadanie 5.1"<<endl
            <<"2) zadanie 5.2"<<endl
            <<"3) zadanie 5.3"<<endl
            <<"4) zadanie 5.4"<<endl
            <<"5) wyjscie"<<endl;
        cout<<"Podaj wybor: "; cin>>wybor;

        switch(wybor){
            case 1:
                wczytajDane(&tekst, &wzorzec);
                dlTxt = (int)tekst.length();
                dlWz = (int)wzorzec.length();
                tablicaDopasowan = new int[dlWz+1];
                break;
            case 2:
                cout<<"Tekst: "<<tekst<<endl;
                cout<<"Wzorzec: "<<wzorzec<<endl;
                cout<<"Wzorzec rozpoczyna sie od indeksow: "<<endl;
                naiwny(tekst, wzorzec, dlTxt, dlWz);
                break;
            case 3:
                cout<<"Tekst: "<<tekst<<endl;
                cout<<"Wzorzec: "<<wzorzec<<endl;
                cout<<"Wzorzec rozpoczyna sie od indeksow: "<<endl;
                zbudujTablicaDopasowan(wzorzec, dlWz, tablicaDopasowan);
                KMP(wzorzec, tekst, dlTxt, dlWz, tablicaDopasowan);
                break;
            case 4:
                cout<<"Tekst: "<<tekst<<endl;
                cout<<"Wzorzec: "<<wzorzec<<endl;
                cout<<"Wzorzec rozpoczyna sie od indeksow: "<<endl;
                tablicaPrzesuniec = new int[dlugoscAlfabetu];
                zbudujTablicePrzesuniec(wzorzec, dlWz, tablicaPrzesuniec, poczatek, koniec);
                BM(wzorzec, tekst, dlWz, dlTxt, tablicaPrzesuniec, poczatek);
                break;
            case 5:
                cout<<"Zamykanie... "<<endl;
        }

    }while(wybor!=5);
    delete [] tablicaDopasowan;
    delete [] tablicaPrzesuniec;
    return 0;
}
