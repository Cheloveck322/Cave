#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <utility>
#include <algorithm>

constexpr int asterisk { 10 };

void printTable(const std::vector<std::vector<int>>& table)
{
    for (const auto& array : table)
    {
        for (auto element : array)
        {
            if (element >= asterisk)
            {
                std::cout << "* ";
            }
            else 
            {
                std::cout << element << ' ';
            }
        }
        std::cout << '\n';
    }
}

void changeTable(std::vector<std::vector<int>>& table, const std::pair<int, int>& pair)
{
    int count{};

    int limit_row { static_cast<int>(table.size()) - 1 };
    int limit_colomn { static_cast<int>(table[0].size()) - 1 };

    for (int x { std::max(0, pair.first-1) }; x <= std::min(pair.first+1, limit_row); ++x)
    {
        for (int y { std::max(0, pair.second-1) }; y <= std::min(pair.second+1, limit_colomn); ++y)
        {
            if (x != pair.first || y != pair.second)
            {
                ++table[x][y];
            }
        }
    }
}

int main()
{
    std::fstream input { "input.txt" };

    int length{};
    int width{};
    int countMine{};

    input >> length;
    input >> width;
    input >> countMine;

    std::vector<std::vector<int>> table(length);
    
    for (int i {}; i < table.size(); ++i)
    {
        table[i] = std::vector<int>(width);
    }

    int x{}, y{};

    while (countMine > 0)
    {
        input >> x;
        input >> y;
        table[x-1][y-1] = asterisk;
        changeTable(table, { x-1, y-1 });
        --countMine;
    }

    printTable(table);

    return 0;    
}