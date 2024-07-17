#include <algorithm>
#include <string>
#include <iostream>
#include <cstddef>

std::size_t getNameCount()
{
    std::size_t length{ 0 };
    std::cout << "How many names would you like to enter? ";
    std::cin >> length;

    return length;
}

void enterNames(std::string* array, std::size_t length)
{
    for (std::size_t index{ 0 }; index < length; ++index)
    {
        std::cout << "Enter name #" << index + 1 << ": ";
        std::getline(std::cin >> std::ws, array[index]);
    }
}

void printNames(std::string* array, std::size_t length)
{
    std::cout << "\nHere is your sorted list:\n";

    for (std::size_t index{ 0 }; index < length; ++index)
    {
        std::cout << "Name #" << index + 1 << ": " << array[index] << '\n';
    }
}

int main()
{
    std::size_t length { getNameCount() };

    auto* array { new std::string[length]{} };

    enterNames(array, length);

    std::sort(array, array + length);

    printNames(array, length);

    delete[] array;

    return 0;
}