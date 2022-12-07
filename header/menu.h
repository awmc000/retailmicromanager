//
// Created by AMC on 12/5/2022.
//

#ifndef RETAILMICROMANAGER_MENU_H
#define RETAILMICROMANAGER_MENU_H

#include "utility.h"
#include "staff.h"

namespace menu {

    void dayOneSetup();
    void infoSetup();

    void login();
    void forgotPassword();


    tm getTm();

    void clearScreen();

    // main menu
    void welcomeOptions();
    void welcome();

    // cashier and submenus
    void cashiering();
    void cashieringOptions();
    void sale();
    void refund();

    // management and submenus
    void management();
    void managementOptions();

    void budgets();
    void budgetsOptions();

    void staffing();
    void staffingOptions();

    void info();
    void infoOptions();
    void payroll();
    void inventory(bool limited);
    void inventoryOptions();

    // inventory submenus
    void inventoryAdd();
    void inventoryUpdateQuantity();
    void inventoryList();

    // Staffing submenus
    void staffingHire();
    void staffingEdit();
    void staffingList();
    void staffingFire();
}
#endif //RETAILMICROMANAGER_MENU_H
