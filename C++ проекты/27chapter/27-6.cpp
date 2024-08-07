#include <iostream>

class Base 
{
public:
    Base() {}
    virtual void print() const { std::cout << "Base"; }
};

class Derived: public Base
{
public: 
    Derived() {}
    void print() const override { std::cout << "Derived"; }
};

int main()
{
    try
    {
        try
        {
            throw Derived{};
        }
        catch(Base& b)
        {
            std::cout << "Caught Base b, which is actually a "; 
            b.print();
            std::cout << '\n';
            throw;
        }
    }
    catch(Base& b)
    {
        std::cout << "Caught Base b, which is actually a ";
        b.print();
        std::cout << '\n';
    }
    

    return 0;
}