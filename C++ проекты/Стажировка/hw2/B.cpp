#include <iostream>
#include <algorithm>
#include <array>
#include <string>
#include <string_view>
#include <cassert>  
#include <vector>
#include <list>
#include <fstream>

namespace Type
{
    enum Name
    {
        constant,
        ascending,
        weakly_asceniding,
        descending,
        weakly_descanding,
        random,
        all_name
    };

    constexpr std::array<std::string_view, all_name> name
    {
        "CONSTANT",
        "ASCENDING",
        "WEAKLY ASCENDING",
        "DESCENDING",
        "WEAKLY DESCENDING", 
        "RANDOM"
    };

    static_assert(std::size(name) == all_name);
}

int ascending(const std::vector<int>& array)
{
    bool weakly { false }; // for weakly ascending
    bool ascending { true };
    int answer {};

    for (int i{}; i < array.size() - 1; ++i)
    {
        if (ascending)
        {
            if (array[i] == array[i+1])
            {
                weakly = true;
            }
        }
        if (array[i] > array[i+1])
        {
            ascending = false;
            weakly = false;
        }
    }

    answer = (ascending ? 1 : -1);
    answer = (weakly ? 2 : answer);

    return answer;
}

int descending(const std::vector<int>& array)
{
    bool weakly { false }; // for weakly descending
    bool descending { true };
    int answer {};

    for (int i{}; i < array.size() - 1; ++i)
    {
        if (descending)
        {
            if (array[i] == array[i+1]) 
            {
                weakly = true;
            }
        }
        if (array[i] < array[i+1])
        {
            descending = false;
            weakly = false;
        }
    }

    answer = (descending ? 3 : -1);
    answer = (weakly ? 4 : answer);

    return answer;
}

bool constant(const std::vector<int>& array)
{
    bool flag { true };

    for (int i{}; i < array.size() - 1; ++i)
    {
        if (array[i] != array[i+1])
            flag = false;
    }

    return flag;
}

std::string_view defineTypeArray(const std::vector<int>& array)
{
    if (constant(array))
    {
        return Type::name[Type::constant];
    }

    int define { ascending(array) };
    
    if (define == -1)
    {
        define = descending(array);
        if (define == -1)
        {
            return Type::name[Type::random];
        }
    }

    return Type::name[define];
}

int main()
{
    std::ifstream input { "input.txt" };
    std::list<int> list {};

    if (!input)
    {
        std::cerr << "Something went wrong with opening file.\n";
        return 1;
    }

    int element {};
    while (input >> element && element != -2000000000)
        list.push_back(element);
    
    std::vector<int> array { list.begin(), list.end() };

    std::cout << defineTypeArray(array) << '\n';

    return 0;
}