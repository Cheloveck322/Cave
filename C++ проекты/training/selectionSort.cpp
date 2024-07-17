#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
int findSmallestIndex(const std::vector<T>& array)
{
    if (array.size() <= 0)
    {
        throw -1;
    }

    int smallInd{};
    int smallElem{ array[0] };

    for (int i{}; i < array.size(); ++i)
    {
        if (array[i] < smallElem)
        {
            smallInd = i;
            smallElem = array[i];
        }
    }

    return smallInd;
}

template <typename T>
std::vector<T> selectionSort(std::vector<T>& array)
{
    std::vector<T> sortedArr{};
    try
    {
        for (int i{}; i < array.size();)
        {
            int smallest { findSmallestIndex(array) };
            sortedArr.push_back(array[smallest]);
            array.erase(array.begin() + smallest);
        }
    }
    catch(int)
    {
        std::cout << "Array is not existing.\n";
    }
    return sortedArr;
}

int main()
{
    std::vector<int> array{ 1, 4, 234, -1, 423, 0, 9, 43 };

    std::vector<int> sortedArr { selectionSort(array) };

    for (auto element: sortedArr)
    {
        std::cout << element << ' ';
    }
    std::cout << '\n';

    return 0;
}