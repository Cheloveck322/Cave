#include <iostream>
#include <vector>
#include <limits>

namespace Data
{
    std::vector board
    {
        std::vector<char>(3), 
        std::vector<char>(3), 
        std::vector<char>(3)
    };


};

int getInt(int x)
{
    while(true)
    {
        std::cin >> x;

        if (!std::cin || x > 9 || x < 1)
        {
            if (std::cin.eof())
            {
                exit(0);
            }

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Invalid input, try again\n";
        }
        else 
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return x;
        }
    }
}

void makeMove()
{
    std::cout << "Where do want to put the sign?\n";
    std::cout << "(input number between 1-9) ";
    int x{};
    int y{};
    getInt(x);
    getInt(y);

    
}