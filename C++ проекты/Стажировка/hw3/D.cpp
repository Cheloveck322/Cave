#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <set>

int main()
{
    std::ifstream input { "input.txt" };

    if(!input)
    {
        std::cerr << "Wrong with opening file.\n";
        return -1;
    }

    std::string str{};
    std::list<std::string> list{};

    while(input >> str)
    {
       list.push_back(str); 
    }

    std::set<std::string> set { list.begin(), list.end() };

    std::cout << set.size() << '\n';

    return 0;
}