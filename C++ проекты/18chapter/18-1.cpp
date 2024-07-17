#include <iostream>
#include <iterator>
#include <utility>

int main()
{
    int array[]{ 30, 50, 20, 10, 40};
    constexpr int length{ static_cast<int>(std::size(array)) };

    for (int startIndex{}; startIndex < length - 1; ++startIndex)
    {
        int maxIndex { startIndex };
        for (int currentIndex{ startIndex }; currentIndex < length; ++currentIndex)
        {
            if (array[maxIndex] < array[currentIndex])
                maxIndex = currentIndex;
        }
        std::swap(array[startIndex], array[maxIndex]);
    }

    for (const auto& a : array)
    {
        std::cout << a << ' ';
    }

    return 0;
}