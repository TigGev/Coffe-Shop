#ifndef UTILITY_H
#define UTILITY_H
#include <iostream>

enum class OrderType {MOBILE, CASHIER, KIOSK};

namespace Utility {
    int validationInput(int from, int to) {
        int input;
        while (true)  {
            std::cin >> input;
            if (input < from || input > to) {
                std::cout << "Invalid input: Please selec a number from " << from << " to " << to << ": ";
                continue;
            }
            break;
        }
        return input;
    }

    void suggestSupplements() {
        std::cout << "1. +Shugar\n"
        << "2. +Caramel\n"
        << "3. +Milk\n"
        << "4. +Whipped cream\n"
        << "5. Order\n>";
        
    }
}

#endif