#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> candies{ 2, 3, 4, 5, 6, 1 };

    auto* greatest { &std::max(candies.begin(), candies.end()) };

    std::cout << greatest;

    return 0;
}