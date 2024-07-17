#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <algorithm>

std::list<int> alternativeDecision(std::vector<int>& array)
{
    std::list<int> list{};
    std::sort(array.begin(), array.end());

    if (array[0] * array[1] < array[array.size()-1] * array[array.size()-2])
    {
        list.push_back(array[array.size()-2]);
        list.push_back(array[array.size()-1]);
    }
    else
    {
        list.push_back(array[0]);
        list.push_back(array[1]);
    }

    return list;
}

int main()
{
    std::ifstream input { "input.txt" };

    if (!input)
    {
        std::cerr << "Something went wrong with opening file.\n";
        return 1;
    } 

    std::list<int> list{};
    int element{};
    while (input >> element)
    {
        list.push_back(element);
    }

    std::vector<int> array{ list.begin(), list.end() };

    auto answer { alternativeDecision(array) };

    for (const auto& e : answer)
    {
        std::cout << e << ' ';
    }
    std::cout << '\n';

    return 0;
}