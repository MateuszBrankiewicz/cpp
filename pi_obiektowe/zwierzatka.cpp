#include <iostream>

using namespace std;
class Zwierze{
    public:
    string gatunek;
    string imie;
    int wiek;
    void dodaj_zwoerze(){
        cout<<"DODAWNANIE NOWEGO ZWIERZECIA DO BAZY: "<<endl;
        cout<<"Podaj gatunek: ";
        cin>>gatunek;
        cout<<"Podaj imie: ";
        cin>>imie;
        cout<<"Podaj wiek: ";
        cin>>wiek;
    }
    void daj_glos(){
        if(gatunek == "kot") cout<<"imie"<<" lat"<<wiek<< ":Miau!";
        else if(gatunek == "kot") cout<<imie<<" lat"<<wiek<< ":Miau!";
        else if(gatunek == "krowa") cout<<imie<<" lat"<<wiek<< ":Muuu!";
        else if(gatunek == "koza") cout<<imie<<" lat"<<wiek<< ":Bee!";
        else cout<<"Nieznany gatunek: ";
    }
};


int main(){
    Zwierze z1;
    z1.dodaj_zwoerze();
    z1.daj_glos();

    Zwierze z2;

}