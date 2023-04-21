#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct student{
    string imie;
    string nazwisko;
    string pomocnicza;
    int punkty;
};
void wczytajDane(student*&tab, int &n){
    string linia;
    char sredniki;
    ifstream plik("./studenci.csv");
    plik >> n;
    tab = new student[n];

    for(int i=0; i<2; i++){
        plik >> sredniki;
    }
    for(int i=0; i<n; i++){
        plik >>linia;
        istringstream ss(linia);
        getline(ss, tab[i].imie, ';');
        getline(ss, tab[i].nazwisko, ';');
        getline(ss, tab[i].pomocnicza);
        tab[i].punkty = stoi(tab[i].pomocnicza);
    }
    plik.close();
    cout<<"Wczytywanie danych zakonczone!"<<endl;
}
void usunTabliceStudentow(student *&tab){
    delete[] tab;
}
void sortowanieQuickSort(student* tab, int n){
    if(n <=1 )return;
    int pivot = tab[n/2].punkty;
    int i=0;
    int j=n-1;
    while(i<=j){
        while(tab[i].punkty < pivot){
            i++;
        }
        while(tab[j].punkty > pivot){
            j--;
        }
        if(i<j){
            swap(tab[i], tab[j]);
            i++;
            j--;
        } else if(i==j){
            j--;
            i++;
        }


    }
    sortowanieQuickSort(tab, j+1);
    sortowanieQuickSort(tab+i, n-i);
}

void liniowe(student* tab, int n, int wartosc) {
    string wynik;
    string komunikat = "Nie znaleziono osob z taka iloscia puntkow";
    int i = 0;
    while (i < n) {
        if (tab[i].punkty == wartosc) {
            wynik += tab[i].imie + " " + tab[i].nazwisko;
            cout << tab[i].imie << " " << tab[i].nazwisko << endl;
        }
        i++;
    }
    if (wynik.empty()) {
        cout << komunikat << endl;
    }
}

int bisekcyjne(student* tab, int n, int wartosc) {
    int lewy = 0;
    int prawy = n - 1;
    while (lewy <= prawy) {
        int srodek = (int)(lewy + prawy) / 2;
        if (tab[srodek].punkty == wartosc) {
            return srodek;
        } else {
            if (wartosc < tab[srodek].punkty) {
                prawy = srodek - 1;
            } else {
                lewy = srodek + 1;
            }
        }
    }
    return -1;
}

void zapiszStudentow( string wynik){
    ofstream zapis;
    zapis.open("./wyniki.csv");
    zapis<<wynik;
    zapis.close();
}

int main() {
    int wybor = 0;
    int rozmiarTablicy = 0;
    int wartosc, p;
    string wynik;
    student* tab = nullptr;
    do{
        cout<<"1) zadanie 7.1"<<endl
            <<"2) zadanie 7.2"<<endl
            <<"3) zadanie 7.3"<<endl
            <<"4) wyjscie"<<endl;
        cout<<"Podaj wybor: "; cin >> wybor;

        switch (wybor) {
            case 1:
                wczytajDane(tab, rozmiarTablicy);
                break;
            case 2:
                cout<<"Podaj ocene do znalezienia: "; cin >> wartosc;
                liniowe(tab, rozmiarTablicy, wartosc);
                break;
            case 3:
                cout<<"Podaj ocene do znalezienia: "; cin >> wartosc;
                sortowanieQuickSort(tab, rozmiarTablicy);
                p = bisekcyjne(tab, rozmiarTablicy, wartosc);
                if(p == -1){
                    cout<<"Brak osob z taka iloscia punktow"<<endl;
                    zapiszStudentow("Brak osob z taka iloscia punktow!");
                    break;
                }
                cout<<tab[p].imie+" "+tab[p].nazwisko<<endl;
                wynik+= tab[p].imie+";"+tab[p].nazwisko+";"+tab[p].pomocnicza+"\n";
                //na lewo
                int j = p-1;
                while(j >= 0){
                    if(tab[j].punkty == wartosc){
                        cout<<tab[j].imie+" "+tab[j].nazwisko<<endl;
                        wynik+= tab[j].imie+";"+tab[j].nazwisko+";"+tab[j].pomocnicza+"\n";
                    } else if(tab[j].punkty < wartosc){
                        break;
                    }
                    j--;
                }
                // na prawo
                j = p+1;
                while(j<=rozmiarTablicy) {
                    if (tab[j].punkty == wartosc) {
                        cout << tab[j].imie + " " + tab[j].nazwisko << endl;
                        wynik += tab[j].imie + ";" + tab[j].nazwisko + ";" + tab[j].pomocnicza + "\n";
                    }else if(tab[j].punkty > wartosc){
                        break;
                    }
                    j++;
                }
                zapiszStudentow(wynik);
                wynik = "";
        }
    }while(wybor != 4);

    usunTabliceStudentow(tab);
    return 0;
}
