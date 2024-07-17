#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <algorithm>

constexpr int conditionOne { 5 }; // ends 5 

int findMaxThowerIndex(const std::vector<int>& array)
{
    int index{};
    for (int i{ 1 }; i < array.size(); ++i)
    {
        if (array[i] > array[index])
        {
            index = i;
        }
    }

    return index;
}
                                       
int findPlace(std::vector<int>& array)
{
    int indexVasya{};
    int maxThrowerIndex{ findMaxThowerIndex(array) };

    for (int i{}; i < array.size() - 1; ++i)
    {
        if ((array[i] > 10 && array[i] % 10 == conditionOne) || (array[i] < 10 && array[i] == conditionOne))
        {
            if (maxThrowerIndex < i)
            {
                if (array[i] > array[i+1])
                {
                    indexVasya = std::max(indexVasya, i);
                }
            }
        }
    }

    if (indexVasya > 0)
    {
        int vasyasValue{ array[indexVasya] };
        int count { static_cast<int>(array.size()) };
        std::sort(array.begin(), array.end());
        
        int howEquals { static_cast<int>(std::count(array.begin(), array.end(), vasyasValue)) };

        for (int i : array)
        {
            if (i < vasyasValue)
            {
                --count;    
            }
            else if (i == vasyasValue && howEquals > 1)
            {
                --count;
                --howEquals;
            }
        }
        return count;
    }

    return 0;
}

int main()
{
    std::ifstream input { "input.txt" };
    std::list<int> list{};

    int size{};
    input >> size;
    int element{};
    while(input >> element && size > 0)
    {
        list.push_back(element);
        --size;
    }

    std::vector<int> array { list.begin(), list.end() };

    std::cout << findPlace(array) << '\n';

    return 0;
}