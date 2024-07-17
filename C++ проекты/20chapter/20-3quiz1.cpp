#include <iostream>
#include <vector>


int factorial(std::size_t count)
{
    static std::vector result{ 0, 1 };
    
    if (count <= 0)
        return 1;

    if (count < std::size(result))
        return result[count];
    
    result.push_back(factorial(count - 1) * count);
    return result[count];
}

int main()
{
    std::cout << "Factorial of 7 is " << factorial(7) << '\n';

    return 0;
}