//
// Created by AMC on 12/5/2022.
//
#include "../header/global.h"
#define EMP_LINES 20

vector<staff::Employee> employee_list;
vector<inventory::Item> item_list;
vector<finance::Budget> budget_list;

// ent info
string ent_name;
Address ent_address;
string ent_phone;
string ent_email;

void loadEntInfo()
{
    std::ifstream ifs_info ("data/info");

    if (!ifs_info.is_open()) {
        std::cerr << "loadEntInfo(): file was not opened";
        return;
    }

    string line;
    // get ent name
    getline(ifs_info, line);
    ent_name = line;

    // ent address: get street addr
    getline(ifs_info, line);
    ent_address.street_address = line;

    // ent addr: get city
    getline(ifs_info, line);
    ent_address.city = line;

    // ent addr: get prov
    getline(ifs_info, line);
    ent_address.province = line;

    // ent addr: get postal code
    getline(ifs_info, line);
    ent_address.postal_code = line;

    // ent addr: get country
    getline(ifs_info, line);
    ent_address.country = line;

    // get phone
    getline(ifs_info, line);
    ent_phone = line;

    // get email
    getline(ifs_info, line);
    ent_email = line;

    ifs_info.close();
}
void loadEmployeeList()
{
    std::ifstream ifs_employees ("data/employees");

    if (!ifs_employees.is_open()) {
        std::cerr << "loadEmployeeList(): file was not opened";
        return;
    }

    // current employee
    staff::Employee curr;
    // string to store current line
    string line;

    // current line of file being accessed
    int lines = (int) linesInFile("data/employees");



    int i = 0;

    for (i; i < lines; i += 20)
    {
        std::getline(ifs_employees, line);
        curr.id = (short) std::stoi(line);

        std::getline(ifs_employees, line);
        curr.user = line;

        std::getline(ifs_employees, line);
        curr.pass = line;

        std::getline(ifs_employees, line);
        curr.security_question = line;

        std::getline(ifs_employees, line);
        curr.security_answer = line;

        std::getline(ifs_employees, line);
        curr.hourly_wage = std::stol(line);

        std::getline(ifs_employees, line);
        curr.pay_budget = (short) std::stoi(line);

        std::getline(ifs_employees, line);
        curr.dob.tm_year = std::stoi(line);

        std::getline(ifs_employees, line);
        curr.dob.tm_mon = std::stoi(line);

        std::getline(ifs_employees, line);
        curr.dob.tm_mday = std::stoi(line);

        std::getline(ifs_employees, line);
        curr.contact.address.street_address = line;

        std::getline(ifs_employees, line);
        curr.contact.address.city = line;

        std::getline(ifs_employees, line);
        curr.contact.address.province = line;

        std::getline(ifs_employees, line);
        curr.contact.address.postal_code = line;

        std::getline(ifs_employees, line);
        curr.contact.address.country = line;

        std::getline(ifs_employees, line);
        curr.contact.phone_number = line;

        std::getline(ifs_employees, line);
        curr.contact.email = line;

        curr.contact.note = line;
    }

}
void loadProductList()
{

}
void loadBudgetList()
{

}

void saveEntInfo()
{
    std::ofstream ofs_info ("data/info");

    if (!ofs_info.is_open()) {
        std::cerr << "saveEntInfo(): file was not opened";
        return;
    }

    // write name
    ofs_info << ent_name << "\n";

    // ent addr: write street addr
    ofs_info << ent_address.street_address << "\n";

    // ent addr: write city
    ofs_info << ent_address.city << "\n";

    // ent addr: write prov
    ofs_info << ent_address.province << "\n";

    // ent addr: write postal code
    ofs_info << ent_address.postal_code << "\n";

    // ent addr: write country
    ofs_info << ent_address.country << "\n";

    // write phone
    ofs_info << ent_phone << "\n";

    // write email
    ofs_info << ent_email << "\n";

    ofs_info.close();
}

void saveEmployeeList()
{
    // open file
    std::ofstream ofs_employees ("data/employees");

    if (!ofs_employees.is_open()) {
        std::cerr << "saveEmployeeList(): file was not opened";
        return;
    }

    // current var
    staff::Employee curr;
    // begin iterating through list in memory
    for (auto & it : employee_list)
    {
        curr = it;
        // employee id
        ofs_employees << curr.id << "\n";
        // user and pass - should have security added
        ofs_employees << curr.user << "\n";
        ofs_employees << curr.pass << "\n";
        ofs_employees << curr.security_question << "\n";
        ofs_employees << curr.security_answer << "\n";
        ofs_employees << curr.hourly_wage << "\n";

        // budget employee is paid from (a store might have a Afternoon Team Wages and Morning Team Wages budget etc.)
        ofs_employees << curr.pay_budget << "\n";

        // date of birth is written by writing year, then month, then month day (0-31).
        ofs_employees << curr.dob.tm_year << "\n";
        ofs_employees << curr.dob.tm_mon << "\n";
        ofs_employees << curr.dob.tm_mday << "\n";

        // writing contact data points one by one
        ofs_employees << curr.contact.surname << "\n";
        ofs_employees << curr.contact.given_name << "\n";
        ofs_employees << curr.contact.address.street_address << "\n";
        ofs_employees << curr.contact.address.city << "\n";
        ofs_employees << curr.contact.address.province << "\n";
        ofs_employees << curr.contact.address.postal_code << "\n";
        ofs_employees << curr.contact.address.country << "\n";
        ofs_employees << curr.contact.phone_number << "\n";
        ofs_employees << curr.contact.email << "\n";
        ofs_employees << curr.contact.note << "\n";
    }
}

void saveItemList()
{
    std::ofstream ofs_products ("data/items");

    if (!ofs_products.is_open()) {
        std::cerr << "saveItemList(): file was not opened";
        return;
    }

    inventory::Item curr;

    for (auto & it : item_list)
    {
        curr = it;
        // TODO: Determine product load order and write the data points to the file
        ofs_products << curr.name << '\n';
        ofs_products << curr.desc << '\n';
        ofs_products << curr.note << '\n';
        ofs_products << curr.image_filename << '\n';
        ofs_products << std::to_string(curr.cost) << '\n';
        ofs_products << std::to_string(curr.price) << '\n';
        ofs_products << std::to_string(curr.qty) << '\n';
        ofs_products << std::to_string(curr.qty_sold) << '\n';
        ofs_products << std::to_string(curr.upc) << '\n';
    }

    ofs_products.close();
}

void saveBudgetList()
{
    std::ofstream ofs_budgets ("data/budgets");

    if (!ofs_budgets.is_open()) {
        std::cerr << "saveBudgetList(): file was not opened";
        return;
    }

    finance::Budget curr;

    for (auto & it : budget_list)
    {
        curr = it;
        ofs_budgets << curr.name << '\n';
        ofs_budgets << curr.desc << '\n';
        ofs_budgets << std::to_string(curr.amount) << '\n';
    }

    ofs_budgets.close();
}