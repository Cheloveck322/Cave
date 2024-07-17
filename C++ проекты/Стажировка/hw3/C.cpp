#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>
#include <vector>
#include <set>

void printBothHeap(std::set<int>& a, std::set<int>& b)
{
    std::set<int> intersection{};

    std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), std::inserter(intersection, intersection.begin()));

    std::cout << intersection.size() << '\n';
    for(auto e : intersection)
    {
        a.erase(e);
        b.erase(e);
        std::cout << e << ' ';
    }
    std::cout << '\n';

}

void printHeapPerson(std::set<int>& a)
{
    std::cout << a.size() << '\n';
    for(auto e : a)
    {
        std::cout << e << ' ';
    }
    std::cout << '\n';
}

int main()
{
    std::ifstream input { "input.txt" };

    if (!input)
    {
        std::cerr << "Error with opening file.\n";
        return -1;
    }

    std::list<int> listA{};
    std::list<int> listB{};
    int N{}, M{};
    int element{};

    input >> N;
    input >> M;

    while(input >> element && (N > 0 || M > 0))
    {
        if (N > 0)
        {
            listA.push_back(element);
            --N;
        }
        else
        {
            listB.push_back(element);
            --M;
        }
    }

    std::set<int> anya{ listA.begin(), listA.end() };
    std::set<int> borya{ listB.begin(), listB.end() };

    printBothHeap(anya, borya);
    printHeapPerson(anya);
    printHeapPerson(borya);

    return 0;
}