//
// Created by AMC on 12/5/2022.
//
#include "../header/menu.h"
#include "../header/global.h"
#include "../header/staff.h"
#include <sstream>
#include <locale>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
namespace menu {
    void dayOneSetup() {
        // for use in taking input
        string line;


        cout << "Welcome to Retail Micro Manager Setup" << endl;
        cout << "You must set up the entreprise info." << endl;

        infoSetup();

        saveEntInfo();


        // Make owner employee
        cout << "You must create a manager-level account." << endl;

        staff::Employee first_employee = staff::createEmployee();

        cout << "You have completed setting up the first employee account." << endl;
        
        employee_list.push_back(first_employee);
        saveEmployeeList();

        cout << "Enter the amount of money in store possession:" << endl;
        finance::Budget unallocated;
        unallocated.name = "Unallocated Funds";
        unallocated.desc = "Funds not sent into a particular budget.";
        unallocated.can_remove = false;
        std::getline(cin, line);
        unallocated.amount = std::stoi(line);

        budget_list.push_back(unallocated);

        saveBudgetList();
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
                exit(0);
        }
    }

    void cashiering()
    {
        cout << " Cashiering Menu " << endl;
        cout << " a. Sale" << endl;
        cout << " b. Refund" << endl;
        cout << " c. Inventory" << endl;
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
                inventory();
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
    void limited_inventory()
    {

    }

    // management and submenus
    void management()
    {

    }
    void budgets()
    {

    }
    void staffing()
    {

    }
    void info()
    {

    }
    void inventory()
    {

    }
}