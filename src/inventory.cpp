//
// Created by AMC on 12/6/2022.
//
#include "../header/inventory.h"

using std::cout;
using std::cin;
using std::endl;

namespace inventory {
    Item createItem() {
        Item new_item;

        string line;

        cout << "Enter the item's name:" << endl;
        std::getline(cin, line);
        new_item.name = line;

        cout << "Enter the item's description:" << endl;
        std::getline(cin, line);
        new_item.desc = line;

        cout << "Enter the item's note [empty OK]:" << endl;
        std::getline(cin, line);
        new_item.note = line;

        cout << "Enter the item's UPC:" << endl;
        std::getline(cin, line);
        new_item.upc = stol(line);

        cout << "Enter the cost in cents the store pays :" << endl;
        std::getline(cin, line);
        new_item.cost = stol(line);

        cout << "Enter the retail price in cents the customer pays:" << endl;
        std::getline(cin, line);
        new_item.price = stol(line);

        cout << "Enter the quantity in stock: " << endl;
        std::getline(cin, line);
        new_item.qty = stoi(line);

        cout << "Quantity sold has been set to 0." << endl;
        new_item.qty_sold = 0;

        cout << "Enter the image filename, not including path: " << endl;
        std::getline(cin, line);
        new_item.image_filename = line;

        cout << "Enter the supplier email address:" << endl;
        std::getline(cin, line);
        new_item.supplier_email = line;

        cout << "Enter the supplier phone number:" << endl;
        std::getline(cin, line);
        new_item.supplier_phone = line;

        return new_item;
    }
}