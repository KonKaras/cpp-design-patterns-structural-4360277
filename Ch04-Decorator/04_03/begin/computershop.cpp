#include <iostream>
#include <string>

using namespace std;

class Computer
{
public:
    virtual string description() const = 0;
    virtual double price() const = 0;
    virtual ~Computer() = default;
};

class Desktop : public Computer
{
public:
    string description() const override
    {
        return "Desktop";
    }

    double price() const override
    {
        return 1000.0;
    }
};

class Laptop : public Computer
{
public:
    string description() const override
    {
        return "Laptop";
    }

    double price() const override
    {
        return 1500.0;
    }
};

class ComputerDecorator : public Computer
{
    public:
        explicit ComputerDecorator(Computer *computer) : m_Computer(computer) {}
        string description() const override
        {
            return m_Computer->description();
        }
        double price() const override
        {
            return m_Computer->price();
        }
    protected:
        Computer *m_Computer;
};

class MemoryUpgradeDecorator : public ComputerDecorator
{
    public:
        explicit MemoryUpgradeDecorator(Computer *computer) : ComputerDecorator(computer) {}
        string description() const override
        {
            return m_Computer->description() + " with memory upgrade";
        }
        double price() const override
        {
            return m_Computer->price() + 50.0;
        }
};

class GraphicsCardDecorator : public ComputerDecorator
{
    public:
        explicit GraphicsCardDecorator(Computer *computer) : ComputerDecorator(computer) {}
        string description() const override
        {
            return m_Computer->description() + " with graphics card";
        }
        double price() const override
        {
            return m_Computer->price() + 100.0;
        }
};

int main()
{
    Computer *desktop = new Desktop();
    cout << desktop->description() << " costs $" << desktop->price() << endl;


    return 0;
}
