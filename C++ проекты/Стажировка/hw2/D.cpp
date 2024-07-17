#include <iostream>
#include <vector>
#include <list>
#include <fstream>

int greaterNeighbors(const std::vector<int>& array)
{
    int count{};
    std::list<int> list{};

    for(int i{}; i < array.size() - 1; ++i)
    {
        if (array[i] > array[i+1] && i != 0 && i != (array.size() - 1))
        {
            list.push_back(i);
        }
    }

    for (int i : list)
    {
        if (array[i] > array[i-1])
        {
            ++count;
        }
    }

    return count;
}

int main()
{
    std::ifstream input { "input.txt" };
    std::list<int> list{};

    int element{};
    while(input >> element)
    {
        list.push_back(element);
    }

    std::vector<int> array{ list.begin(), list.end() };

    std::cout << greaterNeighbors(array) << '\n';

    return 0;
}