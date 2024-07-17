#include <iostream>

int main()
{
    constexpr int numRows{ 10 };
    constexpr int numColms{ 10 };

    int product[numRows][numColms] {};

    for ( std::size_t row { 1 }; row < numRows; ++row )
    {
        for (std::size_t col { 1 }; col < numColms; ++col)
        {
            product[row][col] = static_cast<int>(row * col);
        }
    }

    for ( std::size_t row { 1 }; row < numRows; ++row )
    {
        for (std::size_t col { 1 }; col < numColms; ++col)
        {
            std::cout << product[row][col] << '\t';
        }
        std::cout << '\n';
    }

    return 0;
}