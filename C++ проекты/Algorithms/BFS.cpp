#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using Map = std::unordered_map<std::string, std::vector<std::string>>;

bool personIsSeller(const std::string& name)
{
    return (*(name.end() - 1) == 'm');
}

void addToQueue(Map& graph, std::queue<std::string>& queue, const std::string& name)
{
    for (int i{ 0 }; i < graph[name].size(); ++i)
    {
        queue.push(graph[name][i]);
    }
}

void searchMangoSeller(Map& graph, const std::string& name)
{
    std::queue<std::string> search_queue{};
    std::vector<std::string> searched{};

    addToQueue(graph, search_queue, name);

    while (search_queue.size() > 0)
    {
        std::string person { search_queue.front() };
        search_queue.pop();
        bool find { false };

        for (int i{ 0 }; i < searched.size(); ++i)
        {
            find = (person == searched[i] ? true : false);
        }

        if (find == false)
        {
            if (personIsSeller(person))
            {
                std::cout << person << " is a mango seller!\n";
                return;
            }
            else
            {
                addToQueue(graph, search_queue, person);
                searched.push_back(person); 
            }
        }
    }
}

int main()
{
    Map graph {};
    graph["you"] = { "bob", "alice", "claire" };
    graph["bob"] = { "anuj", "peggy" };
    graph["alice"] = { "peggy" };
    graph["claire"] = { "thom", "jonny" };
    graph["anuj"] = {};
    graph["peggy"] = {};
    graph["thom"] = {};
    graph["jonny"] = {};

    searchMangoSeller(graph, "you");

    return 0;
}