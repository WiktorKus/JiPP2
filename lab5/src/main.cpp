#include <iostream>
#include <../include/Car.h>

using namespace std;

int main () {

    int placeNumber;
    string passengerName;

    Car myCar("AX 312", "Fiat", 5, "124p", "Kabriolet");
    myCar.printInformation();

    cout<<"\nPodaj numer miejsca w samochodzie: ";
    cin>>placeNumber;
    cout<<"\nPodaj imie i nazwisko pasazera: ";
    cin>>passengerName;

    myCar.changeInformationPassenger(placeNumber, passengerName);

    return 0;
}