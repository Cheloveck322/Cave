#include <iostream>

int main()
{
    try
    {
        throw 5;
    }
    catch(double x)
    {
        std::cerr << "We caught an exception of type double: " << x << '\n';    
    }
    catch(...)
    {
        std::cerr << "We caught an exception of an underteminated type\n";
    }
    

    return 0;
}