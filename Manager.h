#ifndef COFFESHOP_MANAGER_H
#define COFFESHOP_MANAGER_H
#include <iostream>
#include "Order.h"
#include "Beverage.h"
#include "Utility.h"


class Manager {
        OrderCreator creator;
    public:
        Order* takeOrder(OrderType type) {
            std::cout << "Choose a drink!\n"
            << "1.Espresso\n"
            << "2.Latte\n"
            << "3.Green tea\n>";
            int inp = Utility::validationInput(1, 3);
            Beverage* beverage; 
            switch (inp) {
                case 1: beverage = new Espresso(); break;
                case 2: beverage = new Latte(); break;
                case 3: beverage = new GreenTea(); break;
            }
            while (inp != 5) {
                Utility::suggestSupplements();
                inp = Utility::validationInput(1, 5);
                switch (inp) {
                    case 5: break;
                    case 1: beverage = new Shugar(beverage); break;
                    case 2: beverage = new Caramel(beverage); break;
                    case 3: beverage = new Milk(beverage); break;
                    case 4: beverage = new WhippedCream(beverage); break;
                }
            }
            return creator.createOrder(type, beverage);
        }
};

#endif