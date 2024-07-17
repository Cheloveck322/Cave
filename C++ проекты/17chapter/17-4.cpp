#include <iostream>
#include <array>
#include <string_view>

struct Item
{
    std::string_view name{};
    int gold{};
};

void printItem(const Item& item)
{
    std::cout << "A " << item.name << " costs " << item.gold << " gold.\n";
}

int main()
{
    constexpr std::array<Item, 4> items 
    { 
        {{"sword", 5}, {"dagger", 3}, {"club", 2}, {"spear", 7}}
    };

    for (auto& ch : items)
    {
        printItem(ch);
    }

    return 0;
}