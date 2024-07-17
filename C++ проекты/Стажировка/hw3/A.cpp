#include <iostream>
#include <unordered_set>
#include <fstream>
#include <list>
#include <vector>

int countDifferentNumbers(const std::vector<int>& array)
{
    std::unordered_set<int> different {};

    for (int i{}; i < array.size(); ++i)
    {
        different.insert(array[i]);
    }

    return different.size();
}

int main()
{
    std::ifstream input { "input.txt" };
    std::list<int> list {};

    int element{};
    while(input >> element)
    {
        list.push_back(element);
    }

    std::vector<int> array { list.begin(), list.end() };

    auto answer { countDifferentNumbers(array) };

    std::cout << answer << '\n';

    return 0;
}