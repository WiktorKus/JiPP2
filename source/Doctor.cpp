//
// Created by wiktor on 11.01.2022.
//

#include <fstream>
#include <string>
#include <istream>
#include "../include/Doctor.h"

template<typename T>
T* showInformation(vector<T> vec, T ID) {
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout<<"------ID------" << ID <<endl;
}

Doctor::Doctor() {}

void Doctor::login() {
    cout << "LOGOWANIE LEKARZ" << endl;
    fstream file;
    file.open("lekarz.csv", ios::in);

    cout << "Podaj ID: ";
    cin >> ID;
    cout << "Podaj haslo: ";
    cin >> password;

    vector <string> record;
    string fieldOne;
    string fieldTwo;
    string fieldThree;
    string fieldFour;
    string fieldFive;
    string fieldSix;

    bool foundRecord = false;

    while(getline(file, fieldOne, ',') && !foundRecord) {
        getline(file, fieldTwo, ',');
        getline(file, fieldThree, ',');
        getline(file, fieldFour, ',');
        getline(file, fieldFive, ',');
        getline(file, fieldSix, '\n');

        if(fieldOne == ID && fieldTwo == password) {
                foundRecord = true;
                record.push_back(fieldOne);
                record.push_back(fieldTwo);
                record.push_back(fieldThree);
                record.push_back(fieldFour);
                record.push_back(fieldFive);
                record.push_back(fieldSix);
                cout<<"LOGOWANIE POWIODLO SIE"<<endl;
                cout<<"Zalogowales sie jako";
                ::showInformation<string>(record, ID);
        }
        }
        file.close();

    if(foundRecord == false) {
            cout<<"Bledne ID lub haslo"<<endl;
        }

    cout << "\nCo chcesz zrobic: " << endl;
    cout << "\nZobaczyc pelny grafik pracy [grafik]";
    cin >> whatToDo;

    file.open("wizyty.csv", ios::in);

    string line;

    if(whatToDo == "grafik") {
        do {
            getline(file, line); //pobierz linijkę
            cout << line << endl; //wypisz na ekranie
        }
        while(!file.eof());
    }
    file.close();
}

Doctor::~Doctor() {}