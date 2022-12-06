//
// Created by AMC on 12/5/2022.
//

#ifndef RETAILMICROMANAGER_FINANCE_H
#define RETAILMICROMANAGER_FINANCE_H

#include "utility.h"
namespace finance {
    struct Budget {
        string name;
        string desc;
        cents amount;
        bool can_remove;
    };
}
#endif //RETAILMICROMANAGER_FINANCE_H
