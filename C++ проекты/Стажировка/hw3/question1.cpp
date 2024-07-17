#include <iostream>
#include <set>
#include <utility>
#include <array>

template <size_t N>
std::pair<int, int> findTwoNumWithSumX(const std::array<int, N>& array, int x)
{
    std::set<int> prevNumbers{};

    for (int number : array)
    {
        if (prevNumbers.find(x - number) != prevNumbers.end())
        {
            return std::pair{ number, x - number };
        }
        prevNumbers.insert(number);
    }

    return std::pair{ 0, 0 };
}

int main()
{
    std::array array { 1, 2, 3, 4, 5, 6, 7, 8, 10, 23, 453 };
    int x { 31 };

    auto answer { findTwoNumWithSumX(array, x) };

    std::cout << answer.first << ' ' << answer.second << '\n';

    return 0;
}