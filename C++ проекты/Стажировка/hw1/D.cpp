#include <iostream> 
#include <cmath>



int main()
{
    int a {};
    int b {};
    int c {};
    int x {};
    
    std::cin >> a >> b >> c;

    if (c < 0)
        std::cout << "NO SOLUTION";
    else if (a == 0 && b == 0 && c == 0)
        std::cout << "MANY SOLUTIONS";
    else
    {
        if (a == 0)
        {
            std::cout << "NO SOLUTION"; 
            return 0;
        }
        x = (c * c - b) / a;
        if (a * x + b < 0)
            std::cout << "NO SOLUTION";      
        else 
            std::cout << x;
    }

    return 0;
}