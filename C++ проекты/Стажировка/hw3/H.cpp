#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <list>
#include <set>

using vectorPair = std::vector<std::pair<int, int>>;

int countShot(const vectorPair& array)
{
    std::set<int> table{};
    for(auto a : array)
    {
        table.insert(a.first);
    }

    return table.size();
}

int main()
{
    std::ifstream input { "input.txt" };

    if (!input)
    {
        std::cerr << "Error file opening.\n";
        return -1;
    }

    int countBirds{};
    input >> countBirds;

    std::list<std::pair<int, int>> list{};
    std::pair<int, int> element{};
    int a{}, b{};
    
    while (input >> element.first && input >> element.second && countBirds > 0)
    {
        list.push_back(element);
        --countBirds;
    }

    std::vector<std::pair<int, int>> array{ list.begin(), list.end() };

    auto answer { countShot(array) };

    std::cout << answer << '\n';

    return 0;
}