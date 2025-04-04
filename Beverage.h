#ifndef BEVERAGE_H
#define BEVERAGE_H
#include <string>

class Beverage {
    // protected:
    //     std::string m_name;
    //     double m_cost;
    public:
        virtual ~Beverage() {};`
        virtual std::string getDescription() const = 0;
        virtual double getCost() const = 0;
};

class Espresso: public Beverage {
    public:
        Espresso() : Beverage("Espresso", 3) {}
        virtual std::string getDescription() const override {return m_name;}
        virtual double getCost() const override {return m_cost;}
};

class Latte: public Beverage {
    public:
        Latte() : Beverage("Latte", 8) {}
        virtual std::string getDescription() const override {return m_name;}
        virtual double getCost() const override {return m_cost;}
};

class GreenTea: public Beverage {
    public:
        GreenTea() : Beverage("Green-tea", 4) {}
        virtual std::string getDescription() const override {return m_name;}
        virtual double getCost() const override {return m_cost;}
};

class BevCreator {
    public:
        virtual ~BevCreator() {};
        virtual Beverage* createBeverage() = 0;
};

class EspCreator: public BevCreator {
    public:
    virtual Beverage* createBeverage() override { return new Espresso(); }
};

class LatteCreator: public BevCreator {
    public:
    virtual Beverage* createBeverage() override { return new Latte(); }
};

class TeaCreator: public BevCreator {
    public:
    virtual Beverage* createBeverage() override { return new GreenTea(); }
};

class Decorator: public Beverage {
    protected:
        Beverage* m_bev;
    public:
        Decorator(Beverage* bev) : m_bev(bev) {}
        virtual ~Decorator() {}
        virtual std::string getDescription() const override { m_bev->getDescription(); }
        virtual double getCost() const override { m_bev->getCost(); }
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
        // virtual double getCost() const override { return m_bev->getCost();}
};

class WhippedCream: public Decorator {
    public:
        WhippedCream(Beverage* bev) : Decorator(bev) {}
        virtual std::string getDescription() const override { return m_bev->getDescription() + ", Whipped cream"; }
        virtual double getCost() const override { return m_bev->getCost() + 2.5; }
};

#endif