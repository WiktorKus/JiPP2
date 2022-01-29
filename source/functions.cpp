//
// Created by wiktor on 28.01.2022.
//

#include "../include/functions.h"

void help() {
    cout<<"DOKUMENTACJA"<<endl;
    cout<<"---------------------ZAKLADANIE KONTA---------------------"<<endl;
    cout<<"[pacjent] --> nalezy podac [imie], [nazwisko], [date urodzenia], [ID], [haslo]"<<endl;
    cout<<"[lekarz] --> nalezy podac [imie], [nazwisko], [date urodzenia], [ID], [haslo], [specjalizacje]"<<endl;
    cout<<"\n---------------------LOGOWANIE---------------------"<<endl;
    cout<<"[pacjent] --> nalezy podać [ID], [haslo]"<<endl;
    cout<<"[lekarz] --> nalezy podać [ID], [haslo]"<<endl;
}

void showInformation() {
    cout<<"Mozesz sprawdzic gdzie znajduje sie nasz szpital wpisz [szpital]"<<endl;
    cout<<"Jesli chcesz sprawdzic godzine wpisz [godzina]"<<endl;
    cout<<"Numery do naszego szpitala wpisz [numery]"<<endl;
    cout<<"Wyjdz [Q]"<<endl;
}

void showInformation(string choice) {
    if(choice == "szpital") {
        cout << "ul. Piekna 5, 00-477 Warszawa" << endl;
    }
    else if(choice == "godzina") {
        time_t time1;
        struct tm * ptr;
        time( & time1 );
        ptr = localtime( & time1 );
        char * data = asctime( ptr );
        cout << "Data: " << data;
    }
    else if(choice == "Q") {
        exit(1);
    }
}

int showInformation(int *phoneNumbers) {
    for(int i = 0; i < 3; i++) {
        cout<<i+1<<"."<<" "<<phoneNumbers[i]<<endl;
    }
}