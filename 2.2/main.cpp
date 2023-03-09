#include <iostream>
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
    cout<<"TABLICA 1D: " << endl;
    for(int i=0;i<n;i++){
        cout<<tab[i]<<" ";
    }
    cout << endl << endl;
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

void sortowanieBabelkowe(int* tab, int n, int tryb){
    int i = n-1;
    while(i>0){
        int j = 0;
        int p = 1;
        while(j < i){
            if(tryb == 1){
                if(tab[j]>tab[j+1]){
                    swap(tab[j], tab[j+1]);
                    p = 0;
                }
            } else if(tryb == 0){
                if(tab[j]<tab[j+1]){
                    swap(tab[j], tab[j+1]);
                    p = 0;
                }
            }
            j++;
        }
        if(p==1) break;
        i--;
    }
}

void sortowaniePrzezWybor(int* tab, int n, int tryb){
    int i = n-1;
    while(i>0){
        int id = 0;
        int j = 1;
        while(j<=i){
            if(tryb == 1){
                if(tab[j]>tab[id]){
                    id = j;
                }
            } else if(tryb == 0){
                if(tab[j]<tab[id]){
                    id = j;
                }
            }
            j++;
        }
        swap(tab[i], tab[id]);
        i--;
    }
}

void sortowaniePrzezWstawianie(int *tab, int n, int tryb){
    int i=n-2;
    while(i>=0){
        int j=i;
        int temp = tab[j];
        if(tryb == 1){
            while(temp > tab[j+1] && j <n-1){
                tab[j] = tab[j+1];
                j++;
            }
        } else if(tryb == 0){
            while(temp < tab[j+1] && j < n-1){
                tab[j] = tab[j+1];
                j++;
            }
        }
        tab[j] = temp;
        i--;
    }
}

void sortowanieBabelkowe2D(int **tab, int w, int k, int tryb, int nrKol){
    for(int i=0; i<w-1; i++){
        for(int j=0; j < w-i-1; j++){
            bool zamiana = false;
            if(tryb == 1){
                if(tab[j][nrKol] > tab[j+1][nrKol]) zamiana = true;
            } else if(tryb == 0){
                if(tab[j][nrKol] < tab[j+1][nrKol]) zamiana = true;
            }
            if(zamiana){
                for(int l=0; l<k; l++){
                    swap(tab[j][l], tab[j+1][l]);
                }
            }
        }
    }
}

int main() {
    int wybor;
    int *tab = nullptr;
    int **tab2 = nullptr;
    int n, a, b, w, k, t, nr;
    do{
        cout<<"1) Babelkowe"<<endl;
        cout<<"2) Przez wybor"<<endl;
        cout<<"3) Przez wstawianie"<<endl;
        cout<<"4) Sort. tablicy 2D"<<endl;
        cout<<"5) Wyjscie"<<endl;
        cout<<"Wybierz podpunkt: "; cin >> wybor;

        switch(wybor){
            case 1:
                cout<<"Podaj wielkosc tablicy: "; cin>>n;
                cout<<"Podaj dolne ograniczenie: "; cin>>a;
                cout<<"Podaj gorne ograniczenie: "; cin>>b;
                cout<<"Podaj tryb sortowania: "<< endl << "0) malejaco"
                    << endl << "1) rosnaco" << endl << "Wybor: "; cin>>t;
                przydzielPamiec1D(tab, n);
                wypelnijTablice1D(tab, n, a, b);
                cout << "Przed posortowaniem: " << endl;
                wyswietl1D(tab, n);
                sortowanieBabelkowe(tab, n, t);
                cout << "Po posortowaniu: " << endl;
                wyswietl1D(tab, n);
                usunTablice1D(tab);
                break;
            case 2:
                cout<<"Podaj wielkosc tablicy: "; cin>>n;
                cout<<"Podaj dolne ograniczenie: "; cin>>a;
                cout<<"Podaj gorne ograniczenie: "; cin>>b;
                cout<<"Podaj tryb sortowania: "<< endl << "0) malejaco"
                    << endl << "1) rosnaco" << endl << "Wybor: "; cin>>t;
                przydzielPamiec1D(tab, n);
                wypelnijTablice1D(tab, n, a, b);
                cout << "Przed posortowaniem: " << endl;
                wyswietl1D(tab, n);
                sortowaniePrzezWybor(tab, n, t);
                cout << "Po posortowaniu: " << endl;
                wyswietl1D(tab, n);
                usunTablice1D(tab);
                break;
            case 3:
                cout<<"Podaj wielkosc tablicy: "; cin>>n;
                cout<<"Podaj dolne ograniczenie: "; cin>>a;
                cout<<"Podaj gorne ograniczenie: "; cin>>b;
                cout<<"Podaj tryb sortowania: "<< endl << "0) malejaco"
                    << endl << "1) rosnaco" << endl << "Wybor: "; cin>>t;
                przydzielPamiec1D(tab, n);
                wypelnijTablice1D(tab, n, a, b);
                cout << "Przed posortowaniem: " << endl;
                wyswietl1D(tab, n);
                sortowaniePrzezWstawianie(tab, n, t);
                cout << "Po posortowaniu: " << endl;
                wyswietl1D(tab, n);
                usunTablice1D(tab);
                break;
            case 4:
                cout<<"Podaj ilosc wierszy: "; cin>>w;
                cout<<"Podaj ilosc kolumn: "; cin>>k;
                cout<<"Podaj dolne ograniczenie: "; cin>>a;
                cout<<"Podaj gorne ograniczenie: "; cin>>b;
                cout<<"Podaj tryb sortowania: "<< endl << "0) malejaco"<< endl << "1) rosnaco" << endl << "Wybor: "; cin>>t;
                cout<<"Podaj nr kolumny: "; cin>>nr;
                przydzielPamiec2D(tab2, w, k);
                wypelnijTablice2D(tab2, w, k, a, b);
                cout << "Przed posortowaniem: " << endl;
                wyswietl2D(tab2, w, k);
                sortowanieBabelkowe2D(tab2, w, k, t, nr);
                cout << "Po posortowaniu: " << endl;
                wyswietl2D(tab2, w, k);
                usunTablice2D(tab2, w);
        }

    } while(wybor != 5);
    return 0;
}
