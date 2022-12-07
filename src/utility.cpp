//
// Created by AMC on 12/5/2022.
//
#include <iomanip>
#include <locale>
#include <ctime>
#include <sstream>
#include "../header/staff.h"
#include "../header/global.h"
#include "../header/menu.h"
#include "../header/utility.h"
#include <fstream>
#include <algorithm>

string formatMoney(cents amount);

char getOption(int num_options)
{
    char char_input;
    bool valid = false;
    while (!valid)
    {
        std::cout << "Enter a lowercase character: " << std::endl;
        string line;
        std::getline(std::cin, line);
        char_input = line[0];

        int alphabet_index = char_input - 'a';
        if ((alphabet_index < num_options) && (alphabet_index >= 0))
        {
            valid = true;
        }
        else
        {
            std::cout << "Invalid character, try again: " << std::endl;
        }
    }
    return char_input;
}



bool fileExists (const std::string& name) {
    std::ifstream f(name.c_str());
    return f.good();
}

bool setUp()
{
    bool info_exists = fileExists("data/info");
    bool budgets_exists = fileExists("data/budgets");
    bool items_exists = fileExists("data/items");
    bool employees_exist = fileExists("data/employees");

    return ((info_exists && budgets_exists) && (items_exists && employees_exist));
}

long long linesInFile(const string& filename)
{
    std::ifstream inFile(filename);
    return std::count(std::istreambuf_iterator<char>(inFile),
               std::istreambuf_iterator<char>(), '\n');
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