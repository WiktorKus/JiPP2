//
// Created by wiktor on 11.01.2022.
//

#include <fstream>
#include <sstream>
#include "../include/Patient.h"

Patient::Patient() {}

template<typename T>
T* showInformation(vector<T> vec, T ID) {
    for(int i = 0; i < vec.size(); i++) {
        cout<<vec[i]<<" ";
    }
    cout<<"\n------ID------" << ID <<endl;
}

void Patient::login() {

    cout << "LOGOWANIE PACJENT" << endl;
    fstream file;
    file.open("pacjent.csv", ios::in);
    if (file.fail()) {
        cout << "Problem z otworzeniem pliku" << endl;
    }

    cout << "Podaj ID: ";
    cin >> ID;
    cout << "Podaj haslo: ";
    cin >> password;

    vector<string> record;
    vector<string> visit;
    string fieldOne;
    string fieldTwo;
    string fieldThree;
    string fieldFour;
    string fieldFive;

    bool foundRecord = false;

    while (getline(file, fieldOne, ',') && !foundRecord) {
        getline(file, fieldTwo, ',');
        getline(file, fieldThree, ',');
        getline(file, fieldFour, ',');
        getline(file, fieldFive, '\n');

        if (fieldOne == ID && fieldTwo == password) {
            foundRecord = true;
            record.push_back(fieldOne);
            record.push_back(fieldTwo);
            record.push_back(fieldThree);
            record.push_back(fieldFour);
            record.push_back(fieldFive);

            cout << "LOGOWANIE POWIODLO SIE" << endl;
            cout << "Zalogowales sie jako: ";
            ::showInformation<string>(record, ID);
        }
    }
    if (foundRecord == false) {
        cout << "Bledne ID lub haslo" << endl;
    }

    file.close();

    cout << "\nCo chcesz zrobic: " << endl;
    cout << "\nUmowic wizyte [umow]\nOdwolac wizyte [odwolaj]\n";
    cin >> whatToDo;
    bool foundVisit = false;

    file.open("wizyty.csv", ios::in | ios::out | ios::app);

    if (file.fail()) {
        cout << "Nie udalo sie otworzyc pliku" << endl;
    }

    if (whatToDo == "umow") {

        cout << "Podaj lekarza do, ktorego chcesz sie zapisac:";
        cin >> doctor;
        cout << "Podaj date wizyty: (prawidlowa data np. 12.05.2022)";
        cin >> dat;
        cout << "Podaj godzine wizyty: (prawidlowa godzina np. 12.45)";
        cin >> hour;
        cout << "Podaj specjalizacje lekarza: ";
        cin >> specialization;
        while (getline(file, fieldOne, ',') && !foundVisit) {
            getline(file, fieldTwo, ',');
            getline(file, fieldThree, ',');
            getline(file, fieldThree, '\n');

            if (fieldOne == doctor && fieldTwo == dat && fieldThree == hour) {
                foundVisit = true;
                cout << "Termin jest zajety\n";
            } else {
                file << doctor << ","
                     << dat << ","
                     << hour << ","
                     << specialization << ","
                     << ID << ","
                     << "\n";
                cout << "Wizyta zostala umowiona" << endl;
            }
        }

    }
    else if (whatToDo == "odwolaj") {
        foundVisit = false;
        cout << "Podaj lekarza do, ktorego sie umowiles";
        cin >> doctor;
        cout << "Podaj date wizyty: (prawidlowa data np. 12.05.2022)";
        cin >> dat;
        cout << "Podaj godzine wizyty: (prawidlowa godzina np. 12.45)";
        cin >> hour;
        cout << "Podaj specjalizacje lekarza:";
        cin >> specialization;


        while (getline(file, fieldOne, ',') && !foundVisit) {
            getline(file, fieldTwo, ',');
            getline(file, fieldThree, ',');
            getline(file, fieldFour, ',');
            if (fieldOne == doctor && fieldTwo == dat && fieldThree == hour && fieldFour == specialization) {
                foundVisit = true;
                file <<"ODWOLANA"<< ','
                    << "ODWOLANA"<< ','
                    << "ODWOLANA"<< ','
                    << "ODWOLANA"<< ','
                    <<"\n";
                cout<<"Pomyslnie odwolales wizyte\n";
            }
        }
    }
}

Patient::~Patient() {}