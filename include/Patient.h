//
// Created by wiktor on 11.01.2022.
//

#ifndef PROJEKTKONCOWY_PATIENT_H
#define PROJEKTKONCOWY_PATIENT_H

#include "User.h"

class Patient : public User {
public:
    /*Konstruktory dla pacjenta*/
    Patient();
    Patient(string loginChoice);
    /*Logowanie jako pacjent*/
    void login() override;
    /*Destruktor dla pacjenta*/
    ~Patient();
};

#endif //PROJEKTKONCOWY_PATIENT_H
