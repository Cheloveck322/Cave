#include <iostream>
#include <vector>
#include <string>
#include <string_view>



int main()
{
    using namespace std::literals::string_view_literals;

    std::string name{ };
    std::vector names { "Alex"sv, "Betty"sv, "Caraline"sv, "Dave"sv, "Emily"sv, "Fred"sv, "Greg"sv, "Holly"sv};
    std::cout << "Enter a name: ";
    std::cin >> name;
    bool flag{ false }; 
     
    for (std::string_view element : names)
    {
        if (name == element)
        {    
            flag = true;
            break;
        }
    }
    if (flag)
        std::cout << name << " was found.\n";
    else 
        std::cout << name << " was not found.\n";

    return 0;
}