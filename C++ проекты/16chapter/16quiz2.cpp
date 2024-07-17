#include <iostream>
#include <vector>
#include <cassert>

namespace Player
{
    enum Items
    {
        health_potion,
        torches,
        arrows,
        countItems
    };
}

int countTotalItems(const std::vector<int>& player)
{
    int count{ };
    for (int element : player)
    {
        count += element;
    }
    return count;
}

void printInventory(const std::vector<int>& inventory)
{
    assert(inventory.size() == Player::countItems);

    for (std::size_t index { 0 }; index < Player::countItems; ++index)
    {
        std::cout << "You have ";
        switch(index)
        {
            case Player::health_potion:
            { 
                std::cout << inventory[Player::health_potion] << " health potion\n"; 
                break; 
            }
            case Player::torches: 
            { 
                std::cout << inventory[Player::torches] << " torches\n"; 
                break; 
            }
            case Player::arrows: 
            { 
                std::cout << inventory[Player::arrows] << " arrows\n"; 
                break; 
            }
            case Player::countItems:
            {
                std::cout << countTotalItems(inventory) << " total items\n";
            }
        }
    }
}

int main()
{
    std::vector player{1, 5, 10};


    printInventory(player);
    
    return 0; 
}