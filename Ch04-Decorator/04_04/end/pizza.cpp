#include <iostream>
using namespace std;

class Pizza
{
public:
    virtual string description() const = 0;
    virtual double price() const = 0;
    virtual ~Pizza() = default;
};

class MargheritaPizza : public Pizza
{
public:
    string description() const override
    {
        return "Margherita Pizza";
    }

    double price() const override
    {
        return 9.99;
    }
};

class HawaiianPizza : public Pizza
{
public:
    string description() const override
    {
        return "Hawaiian Pizza";
    }

    double price() const override
    {
        return 11.99;
    }
};

class PepperoniPizza : public Pizza
{
public:
    string description() const override
    {
        return "Pepperoni Pizza";
    }

    double price() const override
    {
        return 12.99;
    }
};

class PizzaDecorator : public Pizza
{
    public:
        explicit PizzaDecorator(unique_ptr<Pizza> pizza) : m_Pizza(move(pizza)) {}
        string description() const override
        {
            return m_Pizza->description();
        }
        double price() const override
        {
            return m_Pizza->price();
        }

        virtual ~PizzaDecorator() = default;
    
    protected:
        const unique_ptr<Pizza> m_Pizza;
};

class MushroomDecorator : public PizzaDecorator
{
    public:
        explicit MushroomDecorator(unique_ptr<Pizza> *pizza) : PizzaDecorator(move(pizza)) {}
        string description() const override
        {
            return m_Pizza->description() + " with mushrooms";
        }
        double price() const override
        {
            return m_Pizza->price() + 1.0;
        }
};

class CheeseDecorator : public PizzaDecorator
{
    public:
        explicit CheeseDecorator(Pizza *pizza) : PizzaDecorator(pizza) {}
        string description() const override
        {
            return m_Pizza->description() + " with extra cheese";
        }
        double price() const override
        {
            return m_Pizza->price() + 1.5;
        }
};

int main()
{
    const std::unique_ptr<Pizza> pizzas[]{
        make_unique<MargheritaPizza>(),
        make_unique<PepperoniPizza>(),
        make_unique<HawaiianPizza>()};

    for (const auto &pizza : pizzas)
    {
        cout << pizza->description() << " costs $" << pizza->price() << endl;
    }

    return 0;
}
