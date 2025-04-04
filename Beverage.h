#ifndef BEVERAGE_H
#define BEVERAGE_H
#include <string>

class Beverage {
    public:
        Beverage() = default;
        virtual ~Beverage() {};
        virtual std::string getDescription() const = 0;
        virtual double getCost() const = 0;
};

class Espresso: public Beverage {
    public:
        virtual std::string getDescription() const override {return "Espresso";}
        virtual double getCost() const override {return 1.5;}
};

class Latte: public Beverage {
    public:
        virtual std::string getDescription() const override {return "Latte";}
        virtual double getCost() const override {return 4.0;}
};

class GreenTea: public Beverage {
    public:
        virtual std::string getDescription() const override {return "Green tea";}
        virtual double getCost() const override {return 2.0;}
};

class Decorator: public Beverage {
    protected:
        Beverage* m_bev;
    public:
        Decorator(Beverage* bev) : m_bev(bev) {}
        virtual ~Decorator() {}
        virtual std::string getDescription() const override = 0;
        virtual double getCost() const override = 0;
};

class Caramel: public Decorator {
    public:
        Caramel(Beverage* bev) : Decorator(bev) {}
        virtual std::string getDescription() const override {return m_bev->getDescription() + ", Caramel";}
        virtual double getCost() const override {return m_bev->getCost() + 1.25;}
};

class Milk: public Decorator {
    public:
        Milk(Beverage* bev) : Decorator(bev) {}
        virtual std::string getDescription() const override { return m_bev->getDescription() + ", Milk"; }
        virtual double getCost() const override { return m_bev->getCost() + 1.2; }
};

class Shugar : public Decorator {
    public:
        Shugar(Beverage* bev) : Decorator(bev) {}
        virtual std::string getDescription() const override { return m_bev->getDescription() + ", Shugar"; }
        virtual double getCost() const override { return m_bev->getCost(); } //for free
};

class WhippedCream: public Decorator {
    public:
        WhippedCream(Beverage* bev) : Decorator(bev) {}
        virtual std::string getDescription() const override { return m_bev->getDescription() + ", Whipped cream"; }
        virtual double getCost() const override { return m_bev->getCost() + 2.5; }
};

#endif