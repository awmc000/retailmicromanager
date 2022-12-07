//
// Created by AMC on 12/5/2022.
//
#include "../header/menu.h"
#include "../header/global.h"
#include "../header/staff.h"
#include "../header/utility.h"
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
        cout << "Welcome to the Retail Micro Manager\nEnter your username to continue or enter 'EXIT' to exit:" << endl;
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
                            // that employee is set as the current in a global
                            current_employee = curr;

                            // set their clock in time to right now
                            // when they clock out, the difference will be added to their "hours worked"
                            // (hours_worked stores hrs since last paycheque)
                            curr.clocked_in = getTm();

                            // and we send the user to the welcome screen
                            welcome();
                            // if this part of the code is reached, the user has exited the welcome call
                            // go back to main.cpp:main() to save data
                            return;
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

    // TODO: Implement forgot password feature
    void forgotPassword()
    {

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

        while (true) {
            char welcome_choice = getOption(3);
            switch (welcome_choice) {
                case 'a':
                    cashiering();
                    break;
                case 'b':
                    if (current_employee.rank < 2) {
                        management();
                    }
                    else
                    {
                        cout << "You need to be rank 0 [Owner] or rank 1 [Mgr] to access that page." << endl;
                    }
                    break;
                case 'c':
                default:
                    // add difference since last clock in to current employee's hours worked
                    tm clockout = getTm();
                    int hour_diff = clockout.tm_hour - current_employee.clocked_in.tm_hour;
                    double min_diff = clockout.tm_min - current_employee.clocked_in.tm_min;
                    min_diff /= 60; // 30 -> 0.5, 45 -> 0.75, etc.
                    current_employee.hours_worked += (hour_diff + min_diff);
                    exit(0);
            }
        }
    }

    void cashiering()
    {
        cout << " Cashiering Menu " << endl;
        cout << " a. Sale" << endl;
        cout << " b. Refund" << endl;
        cout << " c. Inventory [Limited Access]" << endl;
        cout << " d. Exit" << endl;
        while (true) {
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
    }
    void sale()
    {
        cout << "Entering point of sale mode: enter 'q' to exit." << endl;
        string line;
        while (line != "q") {

            cout<< "Making a sale: Enter UPCs one at a time pressing enter to add products, then press 's' to subtotal."
                << endl;

            vector<inventory::Item> selection;
            cents subtotal = 0;
            while (line != "s") {
                // get line of input
                cout << "Enter UPC:" << endl;
                std::getline(cin, line);

                // convert to long long (upc type)
                long long search_upc = stoll(line);
                bool found = false;

                // linear search item list for this upc
                for (int i = 0; i < item_list.size(); ++i) {
                    if (item_list[i].upc == search_upc) {
                        found = true;
                        selection.push_back(item_list[i]);
                        cout << "Added " << item_list[i].name << ", $" << formatMoney(item_list[i].price) << endl;
                        subtotal += item_list[i].price;
                        cout << "New subtotal: " << subtotal << endl;
                    }
                }
                if (!found)
                {
                    cout << "Item not found, try again:" << endl;
                }
            }
            cout << "Subtotal: " << selection.size() << " items, " << formatMoney(subtotal) << " before taxes."
                 << endl;
            cout << "TODO: taxes are not yet being applied" << endl;
            bool transaction_paid = false;
            cents total_given = 0;
            while (!transaction_paid) {
                cout << "Enter amount of cash given in cents and press enter." << endl;
                std::getline(cin, line);
                total_given += stol(line);
                if (total_given >= subtotal) {
                    cout << "Give change: " << formatMoney(total_given - subtotal) << endl;
                    budget_list[0].amount += subtotal;
                    transaction_paid = true;
                }
            }
        }
    }
    void refund()
    {

    }

    // management and submenus
    void managementOptions()
    {
        cout << "Management" << endl;
        cout << " a. Info" << endl;
        cout << " b. Inventory [Full Access]" << endl;
        cout << " c. Staffing" << endl;
        cout << " d. Finance" << endl;
        cout << " e. Payroll" << endl;
        cout << " f. Exit" << endl;
    }
    void management()
    {
        managementOptions();

        while (true) {
            char management_choice = getOption(6);
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
                    return;
                default:
                    continue;
            }
            managementOptions();
            return;
        }
    }
    void budgetsOptions()
    {
        cout << "Budget Overview and Options " << endl;
        cout << "BUDGET ID\t\tNAME\t\tVALUE\t\t\tDESCRIPTION" << endl;
        for (int i = 0; i < budget_list.size(); ++i)
        {
            cout << i << "\t\t" << budget_list[i].name << "\t\t" << formatMoney(budget_list[i].amount)
                 << "\t\t" << budget_list[i].desc << endl;
        }
        // options
        cout << "a. Add a budget" << endl;
        cout << "b. Make a transfer between budgets" << endl;
        cout << "c. Remove a budget" << endl;
        cout << "d. Exit" << endl;
    }

    void budgets()
    {
        budgetsOptions();
        while (true)
        {
            char choice = getOption(3);
            switch (choice)
            {
                case 'a':
                    cout << "todo, add budget" << endl;
                    break;
                case 'b':
                    cout << "todo, transfer bt budgets" << endl;
                    break;
                case 'c':
                    cout << "todo, remove a budget" << endl;
                    break;
                case 'd':
                    return; // go up a menu to management();
                default:
                    break;
            }
            budgetsOptions();
        }
    }
    void staffing()
    {
        staffingOptions();

        while (true)
        {
            char choice = getOption(5);
            switch (choice)
            {
                case 'a':
                    staffingHire();
                    break;
                case 'b':
                    staffingEdit();
                    break;
                case 'c':
                    staffingList();
                    break;
                case 'd':
                    staffingFire();
                    break;

                case 'e':
                    return;
                default: continue;
            }
            staffingOptions();
        }
    }
    void staffingOptions()
    {
        cout << "Staffing Menu" << endl;
        cout << "a. hire" << endl;
        cout << "b. edit" << endl;
        cout << "c. list" << endl;
        cout << "d. fire" << endl;
        cout << "e. exit" << endl;
    }

    // Staffing submenus
    void staffingHire()
    {
        employee_list.push_back(staff::createEmployee());
    }
    void staffingEdit()
    {

    }
    void staffingList()
    {
        cout << "Employee List" << endl;
        cout << "For details not shown here, go to Edit File..." << endl;
        for (int i = 0; i < employee_list.size(); ++i)
        {
            staff::Employee curr;
            curr = employee_list[i];
            cout << "ID\t\tRANK\t\tNAME\t\tPHONE\t\tWAGE/HR\t\tHOURS TO PAY" << endl;
            cout << curr.id << "\t\t" << curr.rank << "\t\t "<< curr.contact.given_name << "\t\t"
            << curr.contact.surname << "\t\t" << curr.contact.phone_number << "\t\t" << curr.hourly_wage << "\t\t"
            << curr.hours_worked << endl;
        }
    }
    void staffingFire()
    {

    }

    void info()
    {

    }
    void inventoryOptions()
    {
        cout << "Inventory menu" << endl;
        cout << "a. Add new item" << endl;
        cout << "b. Update item quantity" << endl;
        cout << "c. List items" << endl;
        cout << "d. Edit item information" << endl;
        cout << "e. Remove item" << endl;
        cout << "f. Exit" << endl;
    }
    void inventory(bool limited)
    {
        inventoryOptions();
        while (true)
        {
            char option = getOption(3);
            switch (option)
            {
                case 'a':
                    inventoryAdd();
                    break;
                case 'b':
                    inventoryUpdateQuantity();
                    break;
                case 'c':
                    inventoryList();
                    break;
                case 'd':
                    inventoryEditItem();
                    break;
                case 'e':
                    inventoryRemove();

                case 'f':
                default:
                    return;
            }
            inventoryOptions();
        }
    }

    void inventoryAdd()
    {

    }

    void inventoryUpdateQuantity()
    {

    }

    void inventoryList()
    {

    }

    void inventoryEditItem()
    {

    }
    void inventoryRemove()
    {

    }

    void payroll()
    {
        cout << "Paystub Generation" << endl;
        cout << "Enter a valid employee ID:" << endl;

        while (true)
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
                    cout << "Gross Payment: " << (((employee_list[i].hourly_wage) * employee_list[i].hours_worked)
                    / 100) << endl;
                    cout << "Net Payment: TODO" << endl;
                    cout << "Returning to Management menu..." << endl;
                    return;
                }
            }
            cout << "Try again: " << endl;
        }
    }

}