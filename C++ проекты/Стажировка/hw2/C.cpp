#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>

int nearestNum(std::vector<int>& array, int x)
{
    std::sort(array.begin(), array.end());

    for (int i{}; i < array.size(); ++i)
    {
        if (array[i] == x)
        {
            return array[i];
        }
        else if (array[i] > x)
        {
            if (i == 0)
            {
                return array[i];
            }
            else if (array[i-1] < x)
            {
                return (std::abs(x - array[i]) < std::abs(x - array[i-1]) ? array[i] : array[i-1]);
            }
        }
        else if (array[i] < x)
        {
            if (i == array.size() - 1)
            {
                return array[i];
            }
        }
    }

    return 0;
}

int main()
{
    std::ifstream input { "input.txt" };
    std::list<int> list{};

    if (!input)
    {
        std::cerr << "Something went wrong with opening file.\n";
        return 1;
    }

    int size{};
    input >> size;
    int element{};
    while (size > 0)
    {
        input >> element;
        list.push_back(element);
        --size;
    }
    int x {};
    input >> x;

    std::vector<int> array { list.begin(), list.end() };

    std::cout << nearestNum(array, x);

    return 0;
}