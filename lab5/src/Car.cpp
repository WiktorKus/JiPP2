//
// Created by Wiktor on 09/11/2021.
//

#include <../include/Car.h>

Car::Car(string registrationNumber, string name, int placesNumber, string brand, string type) : registrationNumber(registrationNumber), name(name), placesNumber(placesNumber), brand(brand), type(type){
    passenger = new string[placesNumber+1];
    for(int i = 1; i <= placesNumber; i++) {
        passenger[i] = "PUSTE";
    }

}

void Car::printInformation() {
    cout<<"Numer rejestracyjny: "<<registrationNumber<<"\nNazwa samochodu: "<<name<<"\nLiczba miejsc: "<<placesNumber<<endl;
    for(int i = 1; i <= placesNumber; i++) {
        cout<<"Numer miejsca: "<<i<<"\nImie i nazwisko pasazera: "<<passenger[i]<<endl;
    }
    cout<<"\nMarka: "<<brand<<"\nTyp samochodu: "<<type<<endl;
}

void Car::changeInformationPassenger(int placeNumber, string passengerName) {
    passenger[placeNumber] = passengerName;
    cout<<"\nNumer miejsca: "<<placeNumber<<"\nImie i nazwisko pasazera: "<<passengerName<<endl;
}

void Car::setName(string name) {
    this->name = name;
}

void Car::setRegistrationNumber(string registrationNumber) {
    this->registrationNumber = registrationNumber;
}

void Car::setBrand(string brand) {
    this->brand = brand;
}

void Car::setType(string type) {
    this->type = type;
}

string Car::getName() {
    return name;
}

string Car::getRegistrationNumber() {
    return registrationNumber;
}


