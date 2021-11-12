//
// Created by Wiktor on 09/11/2021.
//

#ifndef LAB5_CAR_H
#define LAB5_CAR_H

#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string registrationNumber;
    string name;
    int placesNumber;
    string* passenger;
    string brand;
    string type;
public:
    Car(string registrationNumber, string name, int placesNumber,  string brand, string type);
    Car(Car &car);
    void printInformation();
    void changeInformationPassenger(int placeNumber, string passengerName);
    void setName(string name);
    void setRegistrationNumber(string registrationNumber);
    void setBrand(string brand);
    void setType(string type);
    string getName();
    string getRegistrationNumber();
};

#endif //LAB5_CAR_H
