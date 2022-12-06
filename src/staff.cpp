//
// Created by AMC on 12/5/2022.
//
#include "../header/staff.h"
#include <sstream>
#include <locale>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;

namespace staff {
    Employee createEmployee() {
        staff::Employee new_emp;
        string line;
        cout << "[As the first employee your ID will be zero] " << endl;
        new_emp.id = 0;

        cout << "Enter your given name: " << endl;
        std::getline(cin, line);
        new_emp.contact.given_name = line;

        cout << "Enter your surname: " << endl;
        std::getline(cin, line);
        new_emp.contact.surname = line;

        cout << "Enter your phone number: " << endl;
        std::getline(cin, line);
        new_emp.contact.phone_number = line;

        cout << "Enter your email address: " << endl;
        std::getline(cin, line);
        new_emp.contact.email = line;

        cout << "Enter your street address, i.e., '300 Whittaker Rd':" << endl;
        std::getline(cin, line);
        new_emp.contact.address.street_address = line;

        cout << "Enter the name of your city:" << endl;
        std::getline(cin, line);
        new_emp.contact.address.city = line;

        cout << "[Your province has been set to British Columbia as others are not supported at this time.]" << endl;
        new_emp.contact.address.province = "British Columbia";

        cout << "Enter your postal code, without spaces, eg.'V8Y4W8':" << endl;
        std::getline(cin, line);
        new_emp.contact.address.postal_code = line;

        cout << "[Your country has been set to Canada as others are not supported at this time.]" << endl;
        new_emp.contact.address.country = "Canada";

        cout << "Enter your username for logging in:" << endl;
        std::getline(cin, line);
        new_emp.user = line;

        cout << "Enter your password for logging in:" << endl;
        std::getline(cin, line);
        new_emp.pass = line;

        cout << "Enter a security question for if you forget your password:" << endl;
        std::getline(cin, line);
        new_emp.security_question = line;

        cout << "Enter the answer to the security question:" << endl;
        std::getline(cin, line);
        new_emp.security_answer = line;

        cout << "Enter your hourly wage (Zero is OK for owners)" << endl;
        std::getline(cin, line);
        new_emp.hourly_wage = std::stol(line);

        cout << "Enter your date of birth in the format YYYY/MM/DD:" << endl;
        std::getline(cin, line);
        tm birth = {};

        // parse dob from string 'line', and send to 'birth'
        std::istringstream ss(line);
        ss.imbue(std::locale(""));
        ss >> std::get_time(&birth, "%Y/%m/%d");
        if (ss.fail()) {
            std::cerr << "Parse failed\n";
        } else {
            std::cerr << std::put_time(&birth, "%c") << '\n';
        }
        new_emp.dob = birth;

        cout << "Hours worked set to 0." << endl;
        new_emp.hours_worked = 0;

        cout << "Enter your rank (0 = Owner, 1 = Manager, 2 = Associate):" << endl;
        std::getline(cin, line);
        new_emp.rank = (short int) std::stoi(line);

        return new_emp;
    }
}