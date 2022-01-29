//
// Created by wiktor on 11.01.2022.
//

#ifndef PROJEKTKONCOWY_USER_H
#define PROJEKTKONCOWY_USER_H

#include <iostream>
#include <vector>
#include "functions.h"

using namespace std;

/*Klasa, ktora zawiera jedna wirtualna metode, ktora mozemy nadpisac za pomoca override*/
class Registration{
public:
    virtual void login() = 0;
};

/*Tworzymy klase, ktora dziedziczy po klasie Registration, więc będziemy przeciążać funkcje login*/
/*Wszystkie skladowe beda potem uzywane przez User oraz przez klasy, które będą dziedziczyły po tej klasie*/
class User : public Registration{

protected:
    string whatToDo;
    string hour;
    string doctor;
    string dat;
    string createChoice;
    string firstName;
    string surname;
    string ID;
    string birth;
    string specialization;
    string password;

public:
    /*Konstruktor, który nie przyjmuje żadnych wartości*/
    User();
    /*Konstruktor, który przyjmie zmienną createChoice, odpowiedzialną za wybór czy pacjent będzie tworzył konto czy lekarz*/
    User(string createChoice);
    /*Funkcja, ktora zapisuje do pliku dane lekarza lub pacjenta podane przez uzytkownika*/
    void registration();
    /*Pobiera od użytkownika ID, haslo, imie, nazwisko, date urodzenia*/
    void getData();
    /*Logowanie jako pacjent lub lekarz*/
    void login() override;
    /*destruktor*/
    ~User();
};

#endif //PROJEKTKONCOWY_USER_H
