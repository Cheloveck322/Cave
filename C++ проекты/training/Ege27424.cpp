#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

int minimum(const std::ifstream& file)
{
    auto minAndNonMultiple = [](int a, int b)
            {
                return a < b && std::min(a, b) % 3 == 0;
            };

    int min { std::min(file, minAndNonMultiple) };
}

int main()
{
    std::ifstream fileA { "27424-B.txt" };

    if (!fileA)
    {
        std::cerr << "Something went wrong\n";
        return 1;
    }

    std::string str{};
    while( std::getline(fileA, str) )
        std::cout << str << '\n';

    return 0;
}