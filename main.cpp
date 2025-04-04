#include <iostream>
#include "Utility.h"  
#include "Manager.h"

int main() {
    Manager manager;
    
    while (true) {
        OrderType type;
        std::cout << "1. Mobile\n"
                  << "2. Cashier\n"  
                  << "3. Kiosk\n";

        switch (Utility::validationInput(1, 3)) {
            case 1: type = OrderType::MOBILE; break;
            case 2: type = OrderType::CASHIER; break;
            case 3: type = OrderType::KIOSK; break;
        }
        Order* newOrder = manager.takeOrder(type);

        newOrder->displayOrder();
        delete newOrder;
    }
}