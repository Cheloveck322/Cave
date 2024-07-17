#include <iostream>
#include <vector>
#include <fstream>
#include <list>
#include <utility>
#include <unordered_map>
#include <algorithm>

int truthfulTurtle(const std::vector<std::pair<int, int>>& array, int count)
{
    std::unordered_map<int, int> table{};

    for(auto a : array)
    {
        ++table[a.first + a.second + 1]; 
    }

    auto answer { std::max_element(table.begin(), table.end(), [=](const auto& a, const auto& b)
                    {
                       return a.second < b.second || (a.first == count || b.first == count);
                    }) };

    return answer->second;
}

int main()
{
    std::ifstream input { "input.txt" };

    if(!input)
    {
        std::cerr << "Error opening file.\n";
        return -1;
    }

    std::list<std::pair<int, int>> list{};
    int countTurtle{};

    input >> countTurtle;

    std::pair<int, int> element{};
    while(input >> element.first && input >> element.second && countTurtle > 0)
    {
        list.push_back(element);
        --countTurtle;
    }

    std::vector<std::pair<int, int>> array { list.begin(), list.end() };

    auto answer { truthfulTurtle(array, countTurtle) };

    std::cout << answer << '\n';

    return 0;
}