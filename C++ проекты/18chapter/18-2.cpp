#include <iostream>
#include <iterator>
#include <utility>

int main()
{
    int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
    constexpr int length { static_cast<int>(std::size(array)) };

    for (int countOfIterator{}; countOfIterator < length - 1; ++countOfIterator)
    {
        bool swapped { false };

        for (int compare{}; compare < length - 1 - countOfIterator; ++compare)
        {
            if (array[compare] > array[compare + 1])
            {
                std::swap(array[compare], array[compare + 1]);
                swapped = true;
            }
        }

        if (!swapped)
        {
            std::cout << "Early termination on iteration " << countOfIterator + 1 << '\n';
            break;
        }
    }

    for (const auto& a : array)
    {
        std::cout << a << ' ';
    }

    return 0;
}