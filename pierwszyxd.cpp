#include <iostream>
#include <math.h>
using namespace std;

float dzielenie(float x, float y);
float potegowanie(float x, float y);
float mnozenie(float x, float y);
float dodawanie(float x, float y);
float odejmowanie(float x, float y);
int main(){
    int a ,b, wynik, n;
    cout << "1-Dodawanie\n 2-Odejmowanie\n 3-Mnozenie\n 4-dzielenie\n 5-potegowanie\n";
    cin >> n;
    switch (n)
    {
    case 1:
        cout << "Podaj a";
        cin >> a;
        cout << "Podaj b";
        cin >> b;
        cout << "Wynik wynosi: ";
        cout << dodawanie(a,b) << endl;
        break;
    case 2:
        cout << "Podaj a";
        cin >> a;
        cout << "Podaj b";
        cin >> b;
        cout << "Wynik wynosi: ";
        cout << odejmowanie(a,b) << endl;
        break;
    case 3:
        cout << "Podaj a";
        cin >> a;
        cout << "Podaj b";
        cin >> b;
        cout << "Wynik wynosi: ";
        cout << mnozenie(a,b) << endl;
        break;
    case 4:
        cout << "Podaj a";
        cin >> a;
        cout << "Podaj b - rózne od 0 !";
        cin >> b;
        cout << "Wynik wynosi: ";
        cout << dzielenie(a,b) << endl;
        break;
    case 5:
        cout << "Podaj a";
        cin >> a;
        cout << "Podaj b";
        cin >> b;
        cout << "Wynik wynosi: ";
        cout << potegowanie(a,b) << endl;
        break;    
    default:
        break;
    }
}
float dodawanie(float x, float y){
    float wynik;
    wynik = x + y;
    return wynik;
}
float odejmowanie(float x, float y){
    float wynik;
    wynik = x - y;
    return wynik;
}
float mnozenie(float x, float y){
    float wynik;
    wynik = x * y;
    return wynik;
}
float dzielenie(float x, float y){
    float wynik;
    if (y != 0){
        wynik = x + y;
        }
    else{
        cout<< "Dzielenie przez 0"<< endl;
    }
    return wynik;
}
float potegowanie(float x, float y){
    float wynik;
    wynik = pow(x,y);
    return wynik;
}