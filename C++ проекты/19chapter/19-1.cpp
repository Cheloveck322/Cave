#include <iostream>

int main()
{
    auto* array { new int[8] { 1, 2, 3, 4, 5, 6, 7, 8 } };

    std::cout << *array << *array + 1 << '\n';

    return 0;
}