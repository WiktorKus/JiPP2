//
// Created by wiktor on 11.01.2022.
//

#include "../include/User.h"
#include <iostream>
#include <fstream>

using namespace std;

User::User() {}
User::User(string createChoice) : createChoice(createChoice) {}

void User::getData() {

    cout<<"Podaj Twoje ID: ";
    cin>>ID;
    cout<<"Podaj Twoje haslo: ";
    cin>>password;
    cout<<"Podaj imie: ";
    cin>>firstName;
    cout<<"Podaj nazwisko: ";
    cin>>surname;
    cout<<"Podaj date urodzenia: ";
    cin>>birth;
}

void User::registration() {

    vector <string> loginVector;
    fstream file;

        if (createChoice == "pacjent") {
            file.open("pacjent.csv", ios::in | ios::app);
            getData();
            file << firstName << ", "
                 << surname << ", "
                 << birth << ", "
                 << ID << ", "
                 << password << ", "
                 << "\n";
            file.close();

        } else if (createChoice == "lekarz") {
            file.open("lekarz.csv", ios::in | ios::app);
            getData();
            cout << "Podaj specjalizacje: ";
            cin >> specialization;
            file << firstName << ", "
                 << surname << ", "
                 << birth << ", "
                 << ID << ", "
                 << password << ", "
                 << specialization <<", "
                 << "\n";
            file.close();
        } else {
            cout << "Nie ma takiej opcji\n";
            ::help();
        }
}


void User::login() {}

User::~User() {}

