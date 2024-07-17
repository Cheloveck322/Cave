#include <iostream>
#include <list>
#include <fstream>
#include <vector>

bool increaseDecrease(const std::vector<int>& array)
{
    bool flag{ true };
    for (int i{}; i < array.size() - 1; ++i)
    {
        if (array[i] >= array[i+1])
        {
            flag = false;
            break;
        }
    }
    return flag;
}

int main() 
{
    std::list<int> list{};
    std::ifstream inp { "input.txt" };

    if (!inp)
    {
        std::cerr << "Something went wrong\n";
        return 1;
    }

    int element{};
    while (inp >> element)
        list.push_back(element);
    
    std::vector<int> array { list.begin(), list.end() };

    std::cout << (increaseDecrease(array) ? "YES" : "NO") << '\n';

    return 0;
}