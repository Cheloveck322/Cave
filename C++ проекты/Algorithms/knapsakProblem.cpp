#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <cassert>
#include <set>

void printGraph(const std::vector<std::vector<int>>& graph)
{
    for (int i{}; i < graph.size(); ++i)
    {
        for (int j{}; j < graph[i].size(); ++j)
        {
            std::cout << graph[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

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

    constexpr std::array weight { 3, 1, 2, 2, 1 };
    constexpr std::array value { 10, 3, 9, 5, 6 };
    constexpr std::array names { "water", "book", "food", "jacket", "camera" };

    static_assert(std::size(weight) == all_name && std::size(value) == all_name && std::size(names) == all_name); 
}

void knapsakProblem(int weight)
{   
    std::vector<std::vector<int>> graph(Item::all_name + 1);
    std::set<std::string> names{};

    for (int i{}; i <= graph.size(); ++i)
    {
        graph[i] = std::vector<int>(weight+1);
        for (int j{}; j <= graph[i].size(); ++j)
        {
            graph[i][j] = 0;
        }
    } 

    for (int item{1}; item < graph.size(); ++item)
    {
        for (int size{}; size < graph[item].size(); ++size)
        {
            int cell {};
            if (Item::weight[item-1] > size)
            {
                cell = graph[item-1][size];
            }
            else
            {
                if (graph[item-1][size] > graph[item-1][size-Item::weight[item-1]]+Item::value[item-1])
                {
                    cell = graph[item-1][size];
                }
                else
                {
                    cell = graph[item-1][size-Item::weight[item-1]]+Item::value[item-1];
                }
            }
            graph[item][size] = cell;
        }
    }
    
    printGraph(graph);

    std::cout << "Optimal set of items is ";

    for (const auto& e: names)
    {
        std::cout << e << ' ';
    }
    std::cout << '\n';
}

int main()
{
    int weight{ 6 };
    
    knapsakProblem(weight);

    return 0;
}