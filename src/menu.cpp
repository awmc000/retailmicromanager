//
// Created by AMC on 12/5/2022.
//
#include "../header/menu.h"
#include "../header/global.h"
#include "../header/staff.h"
#include <sstream>
#include <ctime>
#include <locale>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
namespace menu {
    /*
     * dayOneSetup()
     *
     * Purpose: Set up the data list files on the initial run of the MicroManager.
     *
     */
    void dayOneSetup() {
        // for use in taking input
        string line;


        cout << "Welcome to Retail Micro Manager Setup" << endl;
        cout << "You must set up the entreprise info." << endl;

        infoSetup();

        //saveEntInfo();


        // Make owner employee
        cout << "You must create a manager-level account." << endl;

        staff::Employee first_employee = staff::createEmployee();

        cout << "You have completed setting up the first employee account." << endl;
        
        employee_list.push_back(first_employee);
        //saveEmployeeList();

        cout << "Enter the amount of money in store possession:" << endl;
        finance::Budget unallocated;
        unallocated.name = "Unallocated Funds";
        unallocated.desc = "Funds not sent into a particular budget.";
        unallocated.can_remove = false;
        std::getline(cin, line);
        unallocated.amount = std::stoi(line);

        budget_list.push_back(unallocated);

        //saveBudgetList();
        // on exit, should return to main.cpp:main() and thus run the menu.cpp:login() func
    }

    void infoSetup()
    {
        string line;
        cout << "Enter the name of the entreprise:" << endl;
        string new_ent_name;
        std::getline(cin, new_ent_name);
        ent_name = new_ent_name;

        cout << "Enter the street address, i.e., '300 Whittaker Rd':" << endl;
        std::getline(cin, line);
        ent_address.street_address = line;

        cout << "Enter the name of the city the business is in:" << endl;
        std::getline(cin, line);
        ent_address.city = line;

        cout << "[Your province has been set to British Columbia as others are not supported at this time.]" << endl;
        ent_address.province = "British Columbia";

        cout << "Enter the businesses' postal code, without spaces, eg.'V8Y4W8':" << endl;
        std::getline(cin, ent_address.postal_code);

        cout << "[Your country has been set to Canada as others are not supported at this time.]" << endl;
        ent_address.country = "Canada";

        cout << "Enter the businesses' phone number, without spaces:" << endl;
        std::getline(cin, ent_phone);
    }

    tm getTm();

    void login()
    {
        cout << "Welcome to the Retail Micro Manager\nEnter your username to continue." << endl;
        string line;

        bool not_logged_in = true;
        // linear search for an employee account that has this username
        staff::Employee curr;
        while (not_logged_in)
        {
            // get line for username
            std::getline(cin, line);
            for (int i = 0; i < employee_list.size(); i++) {
                // get the employee at this index in the list
                curr = employee_list[i];
                if (curr.user == line) {
                    cout << "Welcome " << curr.contact.given_name << "!" << endl;
                    cout << "Enter your password:" << endl;
                    bool pass_valid = false;
                    while (!pass_valid)
                    {
                        // get line for password
                        std::getline(cin, line);

                        // if password is correct
                        if (curr.pass == line)
                        {
                            // then these booleans need to be switched
                            pass_valid = true;
                            not_logged_in = false;

                            // that employee is set as the current in a global
                            current_employee = curr;

                            // set their clock in time to right now
                            // when they clock out, the difference will be added to their "hours worked"
                            // (hours_worked stores hrs since last paycheque)
                            curr.clocked_in = getTm();

                            // and we send the user to the welcome screen
                            welcome();
                        }
                    }
                }
            }
            // if the linear search did not find an Employee struct w/ that username,
            // the username must have been invalid, and the user will be prompted
            // again at the next repetition of the loop.
            cout << "Did not find that user. Try again, or enter 'EXIT' to exit:" << endl;
            if (line == "EXIT")
                return;
        }
    }

    /*
     * getTm()
     * returns current time as std::tm
     */
    tm getTm()
    {
        // get the epoch time
        // declare a time_T to hold epoch time
        time_t clockin_time_epoch;

        // send the current time to the epoch time variable
        time(&clockin_time_epoch);

        // get a pointer to a tm struct of this time and dereference it
        tm clockin_tm_calendar = *localtime(&clockin_time_epoch);
        return clockin_tm_calendar;
    }

    void welcome()
    {
        cout << " Welcome Menu " << endl;
        cout << " a. Cashiering" << endl;
        cout << " b. Management" << endl;
        cout << " c. Exit" << endl;
        char welcome_choice = getOption(3);
        switch (welcome_choice)
        {
            case 'a':
                cashiering();
                break;
            case 'b':
                management();
                break;
            case 'c':
            default:
                // add difference since last clock in to current employee's hours worked
                exit(0);
        }
    }

    void cashiering()
    {
        cout << " Cashiering Menu " << endl;
        cout << " a. Sale" << endl;
        cout << " b. Refund" << endl;
        cout << " c. Inventory [Limited Access]" << endl;
        cout << " d. Exit" << endl;
        char welcome_choice = getOption(4);
        switch (welcome_choice) {
            case 'a':
                sale();
                break;
            case 'b':
                refund();
                break;
            case 'c':
                inventory(true);
                break;
            case 'd':
            default:
                return;
        }
    }
    void sale()
    {

    }
    void refund()
    {

    }

    // management and submenus
    void management()
    {
        cout << "Management" << endl;
        cout << " a. Info" << endl;
        cout << " b. Inventory [Full Access]" << endl;
        cout << " c. Staffing" << endl;
        cout << " d. Finance" << endl;
        cout << " e. Payroll" << endl;
        cout << " f. Exit" << endl;
        char management_choice = getOption(4);
        switch (management_choice) {
            case 'a':
                info();
                break;
            case 'b':
                inventory(false);
                break;
            case 'c':
                staffing();
                break;
            case 'd':
                budgets();
                break;
            case 'e':
                payroll();
                break;
            case 'f':
            default:
                return;
        }
    }
    void budgets()
    {
        cout << "Budget Overview and Options " << endl;
        cout << "BUDGET ID\t\tNAME\t\tVALUE\t\t\tDESCRIPTION" << endl;
        for (int i = 0; i < budget_list.size(); ++i)
        {
            cout << i << "\t\t" << budget_list[i].name << "\t\t" << formatMoney(budget_list[i].amount)
                << "\t\t" << budget_list[i].desc << endl;
        }
    }
    void staffing()
    {

    }
    void info()
    {

    }
    void inventory(bool limited)
    {

    }
    void payroll()
    {
        cout << "Paystub Generation" << endl;
        cout << "Enter a valid employee ID:" << endl;

        bool valid_entry = false;
        while (!valid_entry)
        {
            string line;
            std::getline(cin, line);
            auto search_id = (short) std::stoi(line);
            for (int i = 0; i < employee_list.size(); ++i)
            {
                if (employee_list[i].id == search_id)
                {
                    cout << "Hours Worked : " << employee_list[i].hours_worked << endl;
                    cout << "Hourly Wage  : " << employee_list[i].hourly_wage << endl;
                    cout << "Gross Payment: " << ((employee_list[i].hourly_wage / 100) * employee_list[i].hours_worked)
                    << endl;
                    cout << "Net Payment: TODO" << endl;
                    valid_entry = true;
                }
            }
            cout << "Try again: " << endl;
        }
    }

    string formatMoney(cents amount)
    {
        string s_amount = std::to_string(amount);
        if (s_amount.size() < 3)
        {
            return (s_amount + "c");
        }
        else
        {
            string new_s;

            // add minus if negative
            if (amount < 0)
                new_s = "-";

            // add dollar sign
            new_s += "$";

            // add amount
            new_s += s_amount;

            // add decimal point 2 spaces from right
            new_s.insert(new_s.size() - 2, ".");

            return new_s;
        }
    }
}