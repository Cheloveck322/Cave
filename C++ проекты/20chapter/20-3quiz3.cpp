#include <iostream>

void printBinary(unsigned int number)
{
    if (number > 1)
        printBinary(number / 2);

    std::cout << number % 2;
}

int main()
{
    int number {};
    std::cin >> number;

    printBinary(static_cast<unsigned int>(number));

    return 0;
}