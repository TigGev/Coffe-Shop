#ifndef COFFESHOP_MANAGER_H
#define COFFESHOP_MANAGER_H
#include "Order.h"
#include "Beverage.h"
#include "Utility.h"

class Manager {
        MobileCreator mbCreator;
        CashierCreator cshCreator;
        KioskCreator kiCreator;
    public:
        Manager(std::string mobile, std::string cashier, std::string kiosk) : mbCreator(mobile), cshCreator(cashier), kiCreator(kiosk) {}
        Beverage* takeMobileOrder() {
            Beverage* newBeverage = nullptr;
            std::cout << "Choose a drink!\n"
            << "1.Espresso\n"
            << "2.Latte\n"
            << "3.Green tea\n";
            int inp = Utility::validationInput(1, 3);
            switch (inp) {
                case 1: newBeverage = mbCreator.createOrder()
            }
        }

};

#endif