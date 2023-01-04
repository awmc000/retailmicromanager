//
// Created by AMC on 12/5/2022.
//
#include "header/utility.h"
#include "header/menu.h"
#include "header/global.h"

int main()
{
    // if the program is not set up, start the process of setting up
    if (!setUp())
    {
        menu::dayOneSetup();
    }
    else
    {
        // Load ent info from file
        loadEntInfo();
        // Load employee list from file
        loadEmployeeList();
        // Load product list from file
        loadItemList();
        // Load budget list from file
        loadBudgetList();
    }

    // Run menu
    menu::login();

    // Save budget list to file
    saveBudgetList();
    // Save product list to file
    saveItemList();
    // Save employee list to file
    saveEmployeeList();
    // Save ent info to file
    saveEntInfo();
}