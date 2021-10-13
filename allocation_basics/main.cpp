#include <iostream>

using namespace std;

int main() {
    int telefon = 12345;    //zmienna liczbowa
    int *wsk = &telefon;    //wskaźnik wsk zawiera adres zmiennej telefon

    cout << *wsk << endl;

    cout << wsk << endl;         //wyświetlenie adresu zmiennej liczba
    cout << &wsk << endl;        //wyświetlenie adresu wskaźnika
    cout << &telefon << endl;    //wyświetlenie adresu zmiennej liczba

    return 0;
}