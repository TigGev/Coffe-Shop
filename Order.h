#ifndef ORDER_H
#define ORDER_H
#include "Beverage.h"
#include <iostream>

class Order {
    protected:
        static int UniqOrderNo;
        int m_OrderNo;
        std::string m_address;
        Beverage* m_bev;
    public:
        Order(const std::string& address, Beverage* beverage) : m_OrderNo(UniqOrderNo++), m_address(address), m_bev(beverage) {}
        virtual ~Order() { delete m_bev;};
        virtual void displayOrder() {
            std::cout << "\033[32m" << "Order from " << m_address << ": " << m_bev->getDescription() << " - " << m_bev->getCost() << "$\n"
            << "Thank you for order!\n" << "\033[0m" << std::endl;
        };
        
};

int Order::UniqOrderNo = 1;

class Mobile: public Order {
    public:
        Mobile( Beverage* beverage) : Order("www.CoffeShop.com", beverage) {}
};

class Cashier: public Order {
    public:
    Cashier(Beverage* beverage) : Order("Cashier", beverage) {}
};

class Kiosk: public Order {
    public:
    Kiosk(Beverage* beverage) : Order("Kiosk", beverage) {}
};


class OrderCreator {
    public: 
        Order* createOrder(OrderType type, Beverage* beverage) { 
            switch (type) {
                case OrderType::CASHIER: return new Cashier(beverage); break;
                case OrderType::MOBILE: return new Mobile(beverage); break;
                case OrderType::KIOSK: return new Kiosk(beverage); break;
            }
        }
};

#endif