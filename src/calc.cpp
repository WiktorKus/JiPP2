#include <iostream>
#include <cstdlib> //biblioteka z funkcja atoi i atof
#include "calc.h"

using namespace std;

int add(char *argv[]) { //dodawanie dwoch liczb calkowitych
    return atoi(argv[2]) + atoi(argv[3]);
}

int subtract(char *argv[]) { //odejmowanie dwoch liczb calkowitych
    return atoi(argv[2]) - atoi(argv[3]);
}

double volume(char *argv[]) { //obliczanie objetosci graniastoslupa prostego o podstawie trapezu
    return (((atof(argv[2]) + atof(argv[3])) * atof(argv[4])) / 2.) * atof(argv[5]);

}

void help(){ //dokumentacja dla funkcji
    cout<<"DOKUMENTACJA\n\n";
    cout<<"Simple calculator\n\n1. simpleCalc [dodawanie]\nDzialania add [a] [b]\n\tDodawanie dwoch liczb ([a] i [b]) calkowitych\n\n\n";
    cout<<"2. simpleCalc [odejmowanie]\nDzialania subtract [a] [b]\n\tOdejmowanie dwoch liczb ([a] i [b]) calkowitych\n\n\n";
    cout<<"3. simpleCalc [obliczanie objetosci graniostoslupa]\nDzialanie volume ([a], [b], [h], [H])\n\tObliczanie objetosci graniastoslupa prostego o podstawie trapezu ze wzoru [((a*b)/2)*H], gdzie a, b i H to liczby calkowite\n\n\n";
    cout<<"4. simpleCalc [dokumentacja]\nWyswietlanie help\n\tDokumentacja dla dodawania, odejmowania i obliczania objetosci graniastoslupa";
}
