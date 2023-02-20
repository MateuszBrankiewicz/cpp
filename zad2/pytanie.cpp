#include <iostream>
#include "pytanie.h"
#include <fstream>
#include <cstdlib>

using namespace std;

void Pytanie::wczytaj(){
    fstream plik;
    plik.open("C:\\Users\\Szef\\Desktop\\c++\\zad2\\quiz.txt",ios::in);
    if(plik.good()==false){
        cout<<"Nie udało się otworzyć pliku";
        exit(0);
    }
    int nr_linii = (nr_pytania-1)*6+1;
    int aktualny_numer = 1;
    string linia;
    while (getline(plik,linia))
    {
        if(aktualny_numer == nr_linii) tresc = linia;
        if(aktualny_numer == nr_linii+1) a = linia;
        if(aktualny_numer == nr_linii+2) b = linia;
        if(aktualny_numer == nr_linii+3) c = linia;
        if(aktualny_numer == nr_linii+4) d = linia;
        if(aktualny_numer == nr_linii+5) poprawna = linia;
        aktualny_numer++;
    }
    plik.close();
}
void Pytanie::zadaj(){
    cout<<tresc<<endl;
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    cout<<d<<endl;
    cout<<"Odpowiedz: ";
    cin>>odpowiedz;
}
void Pytanie::sprawdz(){
    if(odpowiedz == poprawna){
        punkt=1;
    } else punkt = 0;
}