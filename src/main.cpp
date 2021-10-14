#include <iostream>
#include "calc.h"

using namespace std;

void nofunction() {
    cout<<"Nie ma takiej opcji\n";
    help();
}

int main(int argc, char *argv[]) {

    if(argc == 4){
        if(string(argv[1]) == "add"){ //jesli chcemy dodawac to pierwszy podany parametr przez uzytkownika musi nosic nazwe add
            cout<<"Suma dla podanych liczb a = "<<argv[2]<<", b = "<<argv[3]<<" rowna sie: "<<add(argv);
        }
        else if(string(argv[1]) == "subtract") { //jesli chcemy odejmowac to pierwszy podany parametr przez uzytkownika musi nosic nazwe subtract
            cout<<"Roznica dla podanych liczb a = "<<argv[2]<<", b = "<<argv[3]<<" rowna sie: "<<subtract(argv);
        } else {
            nofunction();
        }
    }
    else if(argc == 6) {
        if(string(argv[1]) == "volume"){ //jesli chcemy obliczyc objetosc graniastoslupa to pierwszy podany parametr przez uzytkownika musi nosic nazwe volume
            cout<<"Objetosc graniastoslupa prostego o podanych wymiarach a = "<<argv[2]<<" , b = "<< argv[3]<<", h = "<<argv[4]<<", H = "<<argv[5]<<" rowna sie: "<<(double)volume(argv);

        } else {
            nofunction();
        }
    }
    else if(argc == 2) {
        if(string(argv[1]) == "help") { //jesli chcemy wyswietlic dokumentacje to pierwszy podany parametr przez uzytkownika musi nosic nazwe help
            help();
        } else {
            nofunction();
        }
    }else {
        cout<<"Zla ilosc parametrow\n";
    }

    return 0;
}
