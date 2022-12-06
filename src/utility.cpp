//
// Created by AMC on 12/5/2022.
//
#include "../header/utility.h"
#include <fstream>
#include <algorithm>

char getOption(int num_options)
{
    char char_input;
    bool valid = false;
    while (!valid)
    {
        std::cout << "Enter a lowercase character: " << std::endl;
        std::cin >> char_input;
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