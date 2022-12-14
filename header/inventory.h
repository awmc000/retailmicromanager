//
// Created by AMC on 12/5/2022.
//

#ifndef RETAILMICROMANAGER_INVENTORY_H
#define RETAILMICROMANAGER_INVENTORY_H

#include "utility.h"

namespace inventory {
    struct Item {
        string name;
        string desc;
        string note;
        long long upc;

        cents cost;
        cents price;

        int qty;
        unsigned int qty_sold;

        string image_filename;

        string supplier_email;
        string supplier_phone;
    };
    Item createItem();
}

#endif //RETAILMICROMANAGER_INVENTORY_H
