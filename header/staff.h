//
// Created by AMC on 12/5/2022.
//

#ifndef RETAILMICROMANAGER_EMPLOYEE_H
#define RETAILMICROMANAGER_EMPLOYEE_H

#include "utility.h"

/*
 * Order for Employee Data Points
 * LINE  0: id
 * LINE  1: user
 * LINE  2: pass
 * LINE  3: security_question
 * LINE  4: security_answer
 * LINE  5: hourly_wage
 * LINE  6: pay_budget
 * LINE  7: dob.tm_year
 * LINE  8: dob.tm_mon
 * LINE  9: dob.tm_mday
 * LINE 10: contact.surname
 * LINE 11: contact.given_name
 * LINE 12: contact.address.street_address
 * LINE 13: contact.address.city
 * LINE 14: contact.address.province
 * LINE 15: contact.address.postal_code
 * LINE 16: contact.address.country
 * LINE 17: contact.phone
 * LINE 18: contact.email
 * LINE 19: contact.note
 * LINE 20: hours_worked
 * LINE 21: rank
 */

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
