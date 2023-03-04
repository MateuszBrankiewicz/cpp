#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

void przydzielPamiec1D(int *&tab, int n){
    tab = new int[n];
}
void przydzielPamiec2D(int **&tab, int w, int k){
    tab = new int *[w];
    for(int i =0; i < w; i++){
        tab[i] = new int[k];
    }
}
void wypelnijTablice1D(int *tab, int n, int a, int b){
    srand(time(NULL));
    for(int i=0; i<n;i++){
        tab[i] = rand()%(b-a+1)+a;
    }
}
void wypelnijTablice2D(int **tab, int w, int k, int a, int b){
    srand(time(NULL));
    for(int i=0; i<w;i++){
        for(int j=0; j< k; j++){
            tab[i][j] = rand()%(b-a+1)+a;
        }
    }
}
void usunTablice1D(int *&tab){
    delete []tab;
}
void usunTablice2D(int **&tab, int w){
    for(int i=0; i<w; i++){
        delete[] tab[i];
    }
    delete[] tab;
}
void wyswietl1D(int* tab, int n){
    cout<<endl<<"TABLICA 1D: " << endl;
    for(int i=0;i<n;i++){
        cout<<tab[i]<<" ";
    }
    cout << endl;
}

void wyswietl2D(int** tab, int w, int k){
    cout<<endl<<"TABLICA 2D: " << endl;
    for(int i=0;i<w;i++){
        for(int j=0; j<k;j++){
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }

}

bool czyPierwsza(int n){
    if(n<2) return false;
    for(int i=2;i<n;i++){
        if(n%i==0) return false;
    }
    return true;
}

int minimum(int *tab, int n) {
    int mini = tab[0];
    for (int i = 0; i < n; i++) {
        if (tab[i] < mini) mini = tab[i];
    }
    return mini;
}

void zliczElementy(int *tab, int n){
    int wystapienia[10] = {0};
    for(int i=0; i<n; i++){
        wystapienia[tab[i]]++;
    }
    cout << "Ilosc liczb w tablicy:" << endl;
    for(int i=0; i<10;i++) {
        cout << "Cyfra "<< i << " - " << wystapienia[i] << " razy," << endl;
    }

}

int maksimum2D(int **tab, int w, int k){
    int maks = tab[0][0];
    for(int i = 0; i < w; i++){
        for(int j=0; j<k; j++){
            if(tab[i][j] > maks){
                maks = tab[i][j];
            }
        }
    }
    return maks;
}

int sumaCyfr(int n){
    int suma = 0;
    while(n > 0){
        suma += n % 10;
        n /= 10;
    }
    return suma;
}

double sredniaGorna(int **tab, int r){
    int suma = 0;
    int ilosc = 0;
    for(int i =0; i<r;i++){
        for(int j=i+1;j<r;j++){
            suma += tab[i][j];
            ilosc++;
        }
    }
    return (double)suma / ilosc;
}

double sredniaDolna(int **tab, int r){
    int suma = 0;
    int ilosc = 0;
    for(int i =0; i<r;i++){
        for(int j=0;j<i;j++){
            suma += tab[i][j];
            ilosc++;
        }
    }
    return (double)suma / ilosc;
}

int main() {
    int wybor;
    int *tab = nullptr;
    int **tab2 = nullptr;
    int n, a, b, w, k;
    do{
        cout<<"1) zadanie 1.2"<<endl;
        cout<<"2) zadanie 1.3"<<endl;
        cout<<"3) zadanie 1.4"<<endl;
        cout<<"4) zadanie 1.5"<<endl;
        cout<<"5) wyjscie"<<endl;
        cout<<"wybierz podpunkt: "; cin >> wybor;

        switch(wybor){
            case 1:
                cout<<"Podaj wielkosc tablicy: "; cin>>n;
                cout<<"Podaj dolne ograniczenie: "; cin>>a;
                cout<<"Podaj gorne ograniczenie: "; cin>>b;
                przydzielPamiec1D(tab, n);
                wypelnijTablice1D(tab, n, a, b);
                wyswietl1D(tab, n);
                cout<<"Minimum wynosi: "<<minimum(tab, n)<<endl;
                if(czyPierwsza(minimum(tab, n))){
                    cout<<"Minimum jest liczba pierwsza"<<endl;
                } else cout<<"Minimum nie jest liczba pierwsza"<<endl;
                usunTablice1D(tab);
                break;
            case 2:
                cout<<"Podaj wielkosc tablicy: "; cin>>n;
                a = 0; b = 9;
                przydzielPamiec1D(tab, n);
                wypelnijTablice1D(tab, n, a, b);
                wyswietl1D(tab, n);
                zliczElementy(tab, n);
                usunTablice1D(tab);
                break;
            case 3:
                cout<<"Podaj ilosc wierszy: "; cin>>w;
                cout<<"Podaj ilosc kolumn: "; cin>>k;
                cout<<"Podaj dolne ograniczenie: "; cin>>a;
                cout<<"Podaj gorne ograniczenie: "; cin>>b;
                przydzielPamiec2D(tab2, w, k);
                wypelnijTablice2D(tab2, w, k, a, b);
                wyswietl2D(tab2, w, k);
                cout<<"Maksimum wynosi: "<<maksimum2D(tab2, w, k)<<endl;
                cout<<"Suma cyfr maksimum: " << sumaCyfr(maksimum2D(tab2, w, k))<< endl;
                usunTablice2D(tab2, w);
                break;
            case 4:
                cout<<"Podaj rozmiar kwadratowej tablicy: "; cin>>n;
                a = 7; b = 122;
                przydzielPamiec2D(tab2, n, n);
                wypelnijTablice2D(tab2, n, n, a, b);
                wyswietl2D(tab2, n, n);
                cout<<"Srednia nad glowna przekatna wynosi: " << sredniaGorna(tab2, n)<< endl;
                cout<<"Srednia pod glowna przekatna wynosi: " << sredniaDolna(tab2, n)<< endl;
        }
    } while(wybor != 5);
    return 0;
}
