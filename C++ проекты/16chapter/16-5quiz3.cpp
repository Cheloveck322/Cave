#include <iostream>
#include <vector>
#include <limits> // for std::numeric_limits


using Index = std::size_t;

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

template <typename T>
void printArray(const std::vector<T>& arr)
{
    for (Index index{}; index < arr.size(); ++index)
    {
        std::cout << arr[index] << ' ';
    }

    std::cout << '\n';
}

int getNumberBetween1and9()
{
    while (true)
    {
        int num{};
        std::cout << "Enter a number between 1 and 9: ";
        std::cin >> num;

        if (!std::cin)
        {
            std::cin.clear();
            ignoreLine();
        }
        else 
        {
            if (num > 9 || num < 1)
            {
                std::cin.clear();
                ignoreLine();
            }
            else
            {
                ignoreLine();
                return num;
            }
        }
    }
}

int main()
{
    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };
    
    int num { getNumberBetween1and9() };

    printArray(arr);
    Index ans{};
    bool flag{ false };

    for (Index index{}; index < arr.size(); ++index)
    {
        if (num == arr[index])
        {
            ans = index;
            flag = true;
        }
    }
    if (flag)
            std::cout << "The number " << num << " has index " << ans << '\n';
        else 
            std::cout << "The number " << num << " could was not found\n";

    return 0;
}