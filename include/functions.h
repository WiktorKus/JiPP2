//
// Created by wiktor on 28.01.2022.
//

#ifndef PROJEKTKONCOWY_FUNCTIONS_H
#define PROJEKTKONCOWY_FUNCTIONS_H


#include <iostream>
#include <time.h>

using namespace std;

/*Dokumentacja, wywolywana podczas zlego parametru lub po wybraniu przez uzytkownika oraz na koncu programu*/
void help();

/*Funkcja, ktora pokazuje dodatkowe informacje, gdzie znajduje sie szpital, aktualna godzine oraz numery telefonow do szpitala*/
void showInformation();
void showInformation(string choice);
int showInformation(int *phoneNumbers);

#endif //PROJEKTKONCOWY_FUNCTIONS_H
