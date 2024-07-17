#include <iostream>
#include <algorithm>

int divideConquer(int a, int b)
{
    int min { std::min(a, b) };
    int max { std::max(a, b) };

    if (min * 2 == max)
        return min;

    return divideConquer(min, max - min);
}

int main()
{
    int a {};
    int b {};
    std::cout << "Enter two integer: "; 
    std::cin >> a >> b;

    std::cout << "Minimum square side is " << divideConquer(a, b) << '\n';

    return 0;
}