#ifndef ORDER_H
#define ORDER_H
#include "Beverage.h"
#include <iostream>

class Order {
    protected:
        static int UniqOrderNo;
        int m_OrderNo;
        std::string m_address;
    public:
        Order(std::string address) : m_OrderNo(UniqOrderNo++), m_address(address) {}
        virtual ~Order() {};
        virtual void displayOrder() = 0;
};

int Order::UniqOrderNo = 1;

class Mobile: public Order {
    public:
        Mobile(std::string address) : Order(address) {}
        virtual void displayOrder() override {
            std::cout << "Order made from: " << m_address << "\n"
            << "----------------------------------\n"
            << "             ORDER " << m_OrderNo << std::endl;
        }
};

class Cashier: public Order {
    public:
        Cashier(std::string address) : Order(address) {}
        virtual void displayOrder() override {
            std::cout << "The order was made from the mobile site: " << m_address << "\n"
            << "----------------------------------\n"
            << "             ORDER " << m_OrderNo << std::endl;
        }
};

class Kiosk: public Order {
    public:
        Kiosk(std::string address) : Order(address) {}
        virtual void displayOrder() override {
            std::cout << "Order placed at kiosk on " << m_address << "\n"
            << "----------------------------------\n"
            << "             ORDER " << m_OrderNo << std::endl;
        }
};

class OrderCreator {
    public:
        virtual ~OrderCreator() {}
        virtual Order* createOrder(std::string address) = 0;
};

class MobileCreator: public OrderCreator {
    public:
        virtual Order* createOrder(std::string address) override { return new Mobile(address); }
};

class CashierCreator: public OrderCreator {
    public:
        virtual Order* createOrder(std::string address) override { return new Cashier(address); }
};

class KioskCreator: public OrderCreator {
    public:
        virtual Order* createOrder(std::string address) override { return new Kiosk(address); }
};

#endif