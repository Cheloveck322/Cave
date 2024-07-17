#include <iostream>
#include <fstream>
#include <set>

constexpr int countInput{ 3 };

int numberButtons(std::set<int>& set, int number)
{
    std::set<int> set1 {};

    while(number > 0)
    {
        set1.insert(number % 10);
        number /= 10;
    }

    std::size_t sizeUnkown { set1.size() };

    set.merge(set1);

    return sizeUnkown - set1.size();
}

int main()
{
    std::ifstream input { "input.txt" };

    if (!input)
    {
        std::cerr << "Error with opening file.\n";
        return -1;
    }

    std::set<int> set{};
    int element{};

    for(int i{}; i < countInput; ++i)
    {
        input >> element;
        set.insert(element);
    }

    input >> element;

    auto answer { numberButtons(set, element) };

    std::cout << answer << '\n';

    return 0;
}