#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <string_view>

bool isValidName(std::string_view name)
{
    return std::all_of(name.begin(), name.end(), [](char ch){
        return std::isalpha(ch) || std::isspace(ch);
    });
}

int main()
{
    std::string name{};

    do
    {
        std::cout << "Enter your name: ";
        std::getline(std::cin, name);
    }
    while(!isValidName(name));

    return 0;
}