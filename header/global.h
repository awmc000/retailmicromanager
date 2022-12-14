//
// Created by AMC on 12/5/2022.
//

#ifndef RETAILMICROMANAGER_GLOBAL_H
#define RETAILMICROMANAGER_GLOBAL_H

#include "staff.h"
#include "inventory.h"
#include "finance.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>

using std::vector;

extern vector<staff::Employee> employee_list;
extern vector<inventory::Item> item_list;
extern vector<finance::Budget> budget_list;

// current employee logged in
extern staff::Employee current_employee;

// ent info
extern string ent_name;
extern Address ent_address;
extern string ent_phone;
extern string ent_email;

void loadEntInfo();
void loadEmployeeList();
void loadItemList();
void loadBudgetList();

void saveEntInfo();
void saveEmployeeList();
void saveItemList();
void saveBudgetList();

#endif //RETAILMICROMANAGER_GLOBAL_H
