#include <iostream>
#include <unordered_map>
#include <string>
#include <limits>
#include <vector>
#include <algorithm>

using Cost = std::unordered_map<std::string, double>;
using Parent = std::unordered_map<std::string, std::string>;
using Graph = std::unordered_map<std::string, Cost>;
using UOIterator = Cost::iterator;

std::string find_lowest_cost_node(Cost& costs, const std::vector<std::string> processed)
{
    std::string node{ "" };
    double lowest{ std::numeric_limits<double>::infinity() };
    for (UOIterator it{ costs.begin() }; it != costs.end(); ++it)
    {
        if(it->second < lowest && std::find(processed.begin(), processed.end(), it->first) == processed.end())
        {
            it->second = std::min(it->second, lowest);
            node = it->first;
        }
    }
    return node;
}

void Dijkstra(Graph& graph, Parent& parents, Cost& costs, std::vector<std::string>& processed)
{
    std::string node { find_lowest_cost_node(costs, processed) };

    while (node != "")
    {
        double cost { costs[node] };
        Cost neighbors { graph[node] };
        for (UOIterator it { neighbors.begin() }; it != neighbors.end(); ++it)
        {
            double newCost { cost + it->second };
            if (costs[it->first] > newCost)
            {
                costs[it->first] = newCost;
                parents[it->first] = node;
            } 
        }
        processed.push_back(node);
        node = find_lowest_cost_node(costs, processed);
    } 
}

int main()
{
    Cost costs{};
    Parent parents{};
    Graph graph{};
    std::vector<std::string> processed{};

    double inf { std::numeric_limits<double>::infinity() };

    graph["start"] = {};
    graph["start"]["a"] = 6;
    graph["start"]["b"] = 2;
    graph["a"] = {};
    graph["a"]["fin"] = 1;
    graph["b"] = {};
    graph["b"]["a"] = 3;
    graph["b"]["fin"] = 5;
    graph["fin"] = {};

    costs["a"] = 6;
    costs["b"] = 2;
    costs["fin"] = inf;

    parents["a"] = "start";
    parents["b"] = "start";
    parents["fin"] = "";

    Dijkstra(graph, parents, costs, processed);

    std::cout << "The lowest path from start to finish is " << costs["fin"] << ".\n";
    std::cout << "Finish parent is " << parents["fin"] << '\n';

    return 0; 
}