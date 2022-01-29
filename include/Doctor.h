//
// Created by wiktor on 11.01.2022.
//

#ifndef PROJEKTKONCOWY_DOCTOR_H
#define PROJEKTKONCOWY_DOCTOR_H

#include "User.h"

class Doctor : public User {
public:
    /*Konstruktory dla lekarza*/
    Doctor();
    Doctor(string loginChoice);
    /*Logowanie jako lekarz*/
    void login() override;
    /*Destruktor dla lekarza*/
    ~Doctor();
};

#endif //PROJEKTKONCOWY_DOCTOR_H
