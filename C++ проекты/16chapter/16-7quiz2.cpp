#include <iostream>
#include <vector>


template <typename T>
bool isValueInArray(const std::vector<T>& v, const T& value)
{
    for (const auto& element : v)
    {
        if (value == element)
            return true;
    }
    return false;
}

int main()
{
    using namespace std::literals::string_view_literals;

    std::string name{ };
    std::vector names { "Alex"sv, "Betty"sv, "Caraline"sv, "Dave"sv, "Emily"sv, "Fred"sv, "Greg"sv, "Holly"sv};
    std::cout << "Enter a name: ";
    std::cin >> name;

    bool found { isValueInArray<std::string_view>(names, name) };

    if (found)
        std::cout << name << " was found.\n";
    else
        std::cout << name << " was not found.\n";
}