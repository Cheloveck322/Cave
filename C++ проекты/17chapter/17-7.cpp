#include <iostream>
#include <limits>

/*question #1
int main()
{
    constexpr int a[3] {};

    return 0;
}
*/

constexpr int squares[] { 0, 1, 4, 9};

int getSqueares()
{
    while(true)
    {
        int digit{};
        std::cout << "Enter a single digit integer, or -1 to quit: ";
        std::cin >> digit;

        if (!std::cin)
        {
            if (std::cin.eof())
                exit(0);

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Oops, that input is invalid. Please try again.\n";
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return digit;
        }
    }
}

int main()
{
    while(true)
    {
        bool found{ false };
        int digit{ getSqueares() };

        if (digit == -1)
        {
            std::cout << "Bye\n";
            break;
        }

        for (auto& ch : squares)
        {
            if (digit == ch)
            {
                found = true;
                break;
            }
        }

        if (found)
            std::cout << digit << " is a perfect square\n\n";
        else 
            std::cout << digit << " is not a perfect square\n\n";
    }

    return 0;
}