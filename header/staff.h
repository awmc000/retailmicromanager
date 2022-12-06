//
// Created by AMC on 12/5/2022.
//

#ifndef RETAILMICROMANAGER_EMPLOYEE_H
#define RETAILMICROMANAGER_EMPLOYEE_H

#include "utility.h"

namespace staff {
    struct Employee {
        short int id;
        string user;
        string pass;
        string security_question;
        string security_answer;
        tm clocked_in;
        cents hourly_wage;
        short int pay_budget;
        tm dob;
        Contact contact;
        double hours_worked;
        short int rank;
    };
    Employee createEmployee();
}


#endif //RETAILMICROMANAGER_EMPLOYEE_H
