#include <iostream>
#include <unordered_map>
#include <string>

void checker(std::unordered_map<std::string, bool>& voted, const std::string& name)
{
    if (voted[name])
    {
        std::cout << "kick him out!\n";
        return; 
    }
    voted[name] = true;
    std::cout << "let him vote!\n";
}

int main()
{
    std::unordered_map<std::string, bool> voted {};

    while(true)
    {
        std::string name;
        std::cout << "Enter name of voter: "; 
        std::cin >> name;
        if (!std::cin)
            break;
        checker(voted, name);
    }

    return 0;
}