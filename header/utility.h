/*
 * Functions and structures used elsewhere are defined here
 */
#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <iostream>
#include <ctime>

using std::string;

typedef long cents;

struct Address {
    string street_address;
    string city;
    string province;
    string postal_code;
    string country;
};

struct Contact {
    string surname;
    string given_name;
    Address address;
    string phone_number;
    string email;
    string note;
};

char getOption(int num_options);
bool fileExists (const std::string& name);
bool setUp();
long long linesInFile(const string& filename);
string formatMoney(cents amount);

#endif