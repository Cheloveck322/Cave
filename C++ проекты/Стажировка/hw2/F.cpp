#include <iostream>
#include <list>
#include <fstream>
#include <vector>
#include <utility>

using Pair = std::pair<int, std::vector<int>>;

bool isPolimorph(const std::vector<int>& array)
{
    std::vector<int> invertedArray { array.crbegin(), array.crend() };

    return invertedArray == array;
}

Pair symmetricSeq(std::vector<int>& array)
{
    int count {};
    int index {};
    std::list<int> list{ };
    std::vector<int> copyArray{ array };

    while(!isPolimorph(array))
    {
        array = copyArray;
        list.push_back(array[index]);
        array.insert(array.end(), list.crbegin(), list.crend());
        ++index;
        ++count;
    }

    return { count, { list.crbegin(), list.crend() } };
}

int main()
{
    std::ifstream input { "input.txt" };

    if (!input)
    {
        std::cerr << "Something went wrong with opening file.\n";
        return 1;
    }

    std::list<int> list{};
    int size{};
    input >> size;
    int element{};
    while (size > 0 && input >> element)
    {
        list.push_back(element);
        --size;
    }

    std::vector<int> array{ list.begin(), list.end() };

    auto answer { symmetricSeq(array) };

    std::cout << answer.first << '\n';
    for (int e : answer.second)
    {
        std::cout << e << ' ';
    }
    std::cout << '\n';

    return 0;
}