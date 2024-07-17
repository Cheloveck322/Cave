#include <iostream>

class Base
{
public:
    Base() {}
};

class Derived
{
public:
    Derived() {}
};

int main()
{
    try
    {
        throw Derived();
    }
    catch(const Derived& derived)
    {
        std::cerr << "Caught Derived";
    }
    catch(const Base& base)
    {
        std::cerr << "caught Base";
    }
    
    return 0;
}