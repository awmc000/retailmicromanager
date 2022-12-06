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

    // main menu
    void welcome();

    // cashier and submenus
    void cashiering();
    void sale();
    void refund();

    // management and submenus
    void management();
    void budgets();
    void staffing();
    void info();
    void payroll();
    void inventory(bool limited);

    string formatMoney(cents amount);
}
#endif //RETAILMICROMANAGER_MENU_H
