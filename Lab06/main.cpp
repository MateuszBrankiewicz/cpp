#include <iostream>
#include <string>
#include <fstream>

using namespace std;
string naiwny(string t, string w, int dlw, int dlt){
    int i=0;
    string wynik = "";
    while(i<=dlt-dlw){
        int j=0;
        while(j<dlw && w[j] == t[i+j]){
            j++;
        }
        if(j==dlw){
            wynik += to_string(i)+" ";
        }
        i++;
    }
    return wynik;
}

int myPow(int x, unsigned int p)
{
    if (p == 0) return 1;
    if (p == 1) return x;

    int tmp = myPow(x, p/2);
    if (p%2 == 0) return tmp * tmp;
    else return x * tmp * tmp;
}

int stworzHasz(char s, int off, int p, int exp){
    int hash = 0;
    hash = hash+((int)s-off)*myPow(p, exp);
    return hash;
}

int update_hash(int hash, char s_prev, char s_next, int off, int p, int exp){
    int u_hash = hash-((int)s_prev-off)*myPow(p, exp);
    u_hash = u_hash * p;
    u_hash = u_hash+((int)s_next-off);
    return u_hash;
}

string kr(string wzor, string tekst, int dlw, int dlt, int p, int off){
    int hashP=0;
    int hashT=0;
    int i=0;
    string z = "";

    while(i<dlw){
        hashP = hashP + stworzHasz(wzor[i], off, p, dlw-i-1);
        hashT = hashT + stworzHasz(tekst[i], off, p, dlw-i-1);
        i++;
    }
    i=dlw;
    int j = 0;
    while(i<=dlt){
        if(hashP == hashT){
            z = naiwny(tekst, wzor, dlw, dlt);
            return z;
        }
        if(i<dlt){
            hashT = update_hash(hashT, tekst[j], tekst[i], off, p, dlw-1);
        }
        i++;
        j++;
    }
}

int main() {
     ifstream plik("./text.txt");
     string wzor, tekst, wynik;
     int i=1;
     if(!plik.is_open()){
        cout<<"Nie udalo sie otworzyc pliku!"<<endl;
         return 1;
     }
     plik>>wzor;
     while(getline(plik, tekst)){
        plik>>tekst;
        wynik = kr(wzor, tekst, wzor.length(), tekst.length(), 52, 122);
        cout<<"Linijka "<<i<<": ";
        if(wynik.empty()){
            cout<<"-1";
        }else{
            cout<<wynik;
        }

        cout<<endl;
        i++;
     }
     plik.close();
     return 0;
}
