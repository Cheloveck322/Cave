#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

std::vector<std::vector<int>> groupThePeople(std::vector<int>& groupSizes) {
        std::vector<std::vector<int>> answer{{}};
        for (int i{}; i < groupSizes.size(); ++i)
        {
            int index{};
            for (int j{}; j < answer.size(); ++j)
            {
                if (groupSizes[i] == answer[j].size())
                {

                }
                else 
                {
                    
                }
            }
        }
        return answer;
    }

int main()
{
    std::vector<int> group{ 3, 3, 3, 3, 3, 1, 3 }; // [ [5], [0, 1, 2], [3, 4, 6] ]

    std::vector<std::vector<int>> answer{ groupThePeople(group) };

    for(const auto& element: answer)
    {
        std::cout << "[ ";
        for(const auto& innerElement: element)
        {
            std::cout << innerElement << ' ';
        }
        std::cout << "] ";
    }

    return 0;
}