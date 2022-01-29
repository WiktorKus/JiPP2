#include <iostream>
#include "../include/User.h"
#include "../include/Doctor.h"
#include "../include/Patient.h"

using namespace std;



int main(int argc, char **argv) {

    string msg = "Zla ilosc parametrow\n";
    try {
        if (argc == 2) {
            cout<<"Wszystko w porzadku z argumentami\n";
        }else {
            throw(&msg);
        }
    }
    catch (...) {
        cout<<"Zajrzyj do dokumentacji\n";
    }

    int phoneNumbers[] = {9200231, 5550123, 3124123};
    string choiceInformation;
    string menuChoice = string(argv[1]);
    string choiceLogin;
    string createChoice;

    cout<<"Program sie zaczyna\n";

    cout << "-----------------Jaka operacje chcesz wykonac?-----------------\n";
    cout << "Zaloz konto [zaloz], logowanie [logowanie]\n";
    cout << "Potrzebujesz pomocy [pomoc], wiecej informacji [informacje], wyjscie z progarmu [Q]\n\n";

    if (menuChoice == "zaloz") {

        cout << "-----------------REJESTRACJA-----------------\n";
        cout << "Podaj jako kto chcesz zalozyc konto\n";
        cout << "Pacjent [pacjent]\n";
        cout << "Lekarz [lekarz]\n";
        cin >> createChoice;
        User mainUser(createChoice);
        mainUser.registration();
    }
    else if(menuChoice == "logowanie"){
        cout << "-----------------LOGOWANIE-----------------\n";
        cout << "Podaj jako kto chcesz sie zalogowac\n";
        cout << "Pacjent [pacjent]\n";
        cout << "Lekarz [lekarz]\n";
        cin >> choiceLogin;
        if(choiceLogin == "pacjent") {
            User *patientMain = new Patient();
            patientMain->login();
        }
        else if(choiceLogin == "lekarz") {
            User *doctorMain = new Doctor();
            doctorMain->login();
        }
    }
    else if (menuChoice == "pomoc") {
        help();
    }
    else if(menuChoice == "informacje") {
        showInformation();
        cin>>choiceInformation;
        showInformation(choiceInformation);
        if(choiceInformation == "numery") {
            showInformation(phoneNumbers);
        }
    }
    else if (menuChoice == "Q") {
        exit(1);
    } else {
        help();
    }

    cout<<"\nProgam sie konczy\n";
    return 0;
}
