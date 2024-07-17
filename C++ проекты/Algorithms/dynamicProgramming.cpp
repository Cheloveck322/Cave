#include <iostream>
#include <memory>
#include <string>
#include <array>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string_view>

using Column = std::unique_ptr<int[]>[];
using Graph = std::unique_ptr<Column>;

namespace Item
{
    enum Name
    {
        water,
        book,
        food,
        jacket,
        camera,
        all_name
    };

    constexpr std::array weight{ 3, 1, 2, 2, 1 };
    constexpr std::array value{ 10, 3, 9, 5, 6 };
    constexpr std::array names { 'w', 'b', 'f', 'j', 'c' };

    static_assert(std::size(names) == all_name);
    static_assert(std::size(weight) == all_name);
    static_assert(std::size(value) == all_name);
}

std::string dynamicProgramming(int weight)
{
    auto graph { std::make_unique<Column>(Item::all_name + 1) };
    std::unique_ptr<std::unique_ptr<std::string[]>[]> setOfItem { std::make_unique<std::unique_ptr<std::string[]>[]>(Item::all_name + 1) };
    
    for (int i{}; i < weight; ++i)
    {
        graph[i] = std::make_unique<int[]>(weight + 1);
        setOfItem[i] = std::make_unique<std::string[]>(weight + 1);
    }

    for (int item{ 1 }; item <= Item::all_name; ++item)
    {
        for (int size{}; size <= weight; ++size)
        {
            int cell{};
            if (Item::weight[item-1] > size)
            {
                cell = graph[item-1][size];
                setOfItem[item][size] = setOfItem[item-1][size];
            }
            else 
            {
                cell = std::max(graph[item-1][size], graph[item-1][size-Item::weight[item-1]]+Item::value[item-1]);
                if (graph[item-1][size] > graph[item-1][size-Item::weight[item-1]]+Item::value[item-1])
                {
                    setOfItem[item][size] = setOfItem[item-1][size];
                }
                else
                {
                    setOfItem[item][size] = setOfItem[item-1][size-Item::weight[item-1]];
                    setOfItem[item][size].push_back(Item::names[item-1]);
                }
            }
            graph[item][size] = cell;
        }
    }

    return setOfItem[Item::all_name][weight];
}

int main()
{
    int weight { 6 };

    std::string answer { dynamicProgramming(weight) };

    std::cout << "The best value to ykrast' is " << answer << '\n';

    return 0;
}