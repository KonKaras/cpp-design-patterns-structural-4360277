#include <iostream>

class IVehicle
{
    public:
        explicit IVehicle(const IEngine &engine) : m_engine(engine) {}
        void drive() {
            m_engine.start();
            driveVehicle();
        }
        protected:
            virtual void driveVehicle() const = 0;

    private:
        const IEngine  &m_engine;

};

class IEngine
{
    public:
        virtual void start() const = 0;
        virtual ~IEngine() = default;
};

class GasEngine : public IEngine
{
    public:
        void start() const override
        {
            std::cout << "Starting gas engine." << std::endl;
        }
};

class ElectricEngine : public IEngine
{
    public:
        void start() const override
        {
            std::cout << "Starting electric engine." << std::endl;
        }
};

class Car : public IVehicle
{
    public:
        Car(const IEngine &engine) : IVehicle(engine) {}

        void driveVehicle() const override
        {
            std::cout << "Driving car." << std::endl;
        }
};