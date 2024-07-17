#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <list>
#include <iterator>

void printArray(const std::vector<int>& array)
{
    for(auto a : array)
    {
        std::cout << a << ' ';
    }
    std::cout << '\n';
}

std::vector<int> intersection(std::vector<int>& a1, std::vector<int>& a2)
{
    std::vector<int> intersected{};
    std::sort(a1.begin(), a1.end());
    std::sort(a2.begin(), a2.end());

    std::set_intersection(a1.begin(), a1.end(), a2.begin(), a2.end(), 
                            std::back_inserter(intersected)); 

    return intersected;
}

int main()
{
    std::ifstream input { "input.txt" };
    std::list<int> list {};

    if (!input)
    {
        std::cerr << "Something went wrong with opening file.\n";
        return 1;
    }

    int element{};
    while(input >> element)
    {
        list.push_back(element);
    }

    auto iteratorToMiddle { list.begin() };
    std::advance(iteratorToMiddle, list.size() + 1);

    std::vector<int> array1 { list.begin(), iteratorToMiddle };
    std::vector<int> array2 { iteratorToMiddle, list.end() };

    printArray(array1);

    auto answer { intersection(array1, array2) };

    for (auto a : answer)
    {
        std::cout << a << ' ';
    }
    std::cout << '\n';

    return 0;
}