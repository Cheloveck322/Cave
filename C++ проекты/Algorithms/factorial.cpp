#include <iostream>

int factorial(int n)
{
    if (n == 1)
        return 1;
    else if (n < 1)
        return 0;
    return n * factorial(n - 1);
}

int main()
{
    int n {};
    std::cout << "Enter your n: ";
    std::cin >> n;

    std::cout << factorial(n) << '\n';

    return 0;
}