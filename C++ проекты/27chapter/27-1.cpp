#include <iostream>
#include <cmath>

int main()
{
    std::cout << "Enter a number: ";
    double x {};
    std::cin >> x;

    try
    {
        if (x < 0.0)
            throw "Can not take a sqrt of negative number";
        
        std::cout << "The sqrt of " << x << " is " << std::sqrt(x) << '\n';
    }
    catch(const char* exception)
    {
        std::cerr << "Error: " << exception << '\n';
    }
    

    return 0;
}