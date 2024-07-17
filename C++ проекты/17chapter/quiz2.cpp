//correct answer for quiz
#include <iostream>
#include <array>
#include <string_view>
#include "Random.h"
#include <limits>

namespace Potion
{
    enum Type 
    {
        healing,
        mana, 
        speed, 
        invisibility,
        max_potions
    };

    constexpr std::array types { healing, mana, speed, invisibility };

    constexpr std::array<std::string_view, max_potions> name { "healing", "mana", "speed", "invisibility" };
    constexpr std::array cost { 20, 30, 12, 50 };

    static_assert(types.size() == max_potions);
    static_assert(name.size() == max_potions);
    static_assert(cost.size() == max_potions);
}

class Player
{
private:
    std::string m_name {};
    int m_gold {};
    std::array<int, Potion::max_potions> m_inventory{};

public:
    explicit Player(std::string_view name) :
        m_name { name }, 
        m_gold { Random::get(80, 120) }
    {
    }

    bool buy(Potion::Type type)
    {
        if (m_gold < Potion::cost[type])
            return false;
        
        m_gold -= Potion::cost[type];
        ++m_inventory[type];
        return true;
    }

    int gold() const { return m_gold; }
    int inventory(Potion::Type p) const { return m_inventory[p]; }
};

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int charNumToInt(char c)
{
    return c - '0';
}

Potion::Type whichPotion()
{
    std::cout << "Enter the number of the you'd like to buy, or 'q' to quit: ";
    char input{};
    while (true)
    {
        std::cin >> input;
        if (!std::cin)
        {
            std::cin.clear();
            ignoreLine();
            continue;
        }
        
        if (!std::cin.eof() && std::cin.peek() != '\n')
        {
            std::cout << "That is an invalid input. Try again: ";
            ignoreLine();
            continue;
        }

        if (input == 'q')
        {
            return Potion::max_potions;
        }

        int val { charNumToInt(input) };
        if (val >= 0 && val < Potion::max_potions)
            return static_cast<Potion::Type>(val);

        std::cout << "That is an invalid input. Try again: ";
        ignoreLine();
    }
}

void shop(Player &player)
{
    while (true)
    {
        std::cout << "Here is our selection for today:\n";

        for (auto& p: Potion::types)
            std::cout << p << ") " << Potion::name[p] << " costs " << Potion::cost[p] << '\n';

        Potion::Type which { whichPotion() };
        if (which == Potion::max_potions)
            return;
        
        bool success { player.buy(which) };
        if (!success)
            std::cout << "You can not afford that.\n\n";
        else
            std::cout << "You purchased a potion of " << Potion::name[which] << ".  You have " << player.gold() << " gold left.\n\n";
    }
}

void printInventory(Player &player)
{
    std::cout << "Your inventory contains: \n";

    for (const auto& p: Potion::types)
    {
        if (player.inventory(p) > 0)
            std::cout << player.inventory(p) << "x potion of " << Potion::name[p] << '\n';
    }

    std::cout << "You escaped with " << player.gold() << " gold remaining.\n";
}

int main()
{
    std::cout << "Welcome to Roscoe's potion emporium!\n";
    std::cout << "Enter your name: ";

    std::string name{};
    std::cin >> name;

    Player player { name };

    std::cout << "Hello, " << name << ", you have " << player.gold() << " gold.\n\n";

    shop(player);

    std::cout << '\n';

    printInventory(player);

    std::cout << "\nThanks for shopping at Roscoe's potion emporium!\n";

    return 0;
}

/*my answer to quiz

constexpr char g_CharToQuit { 'q' };

namespace Potion
{
    using namespace std::literals::string_view_literals;

    enum Type
    {
        healing,
        mana,
        speed,
        invisibility,
        max_type
    };
    
    constexpr std::array types { healing, mana, speed, invisibility };

    constexpr std::array costs { 20, 30, 12, 50 };
    constexpr std::array name { "healing"sv, "mana"sv, "speed"sv, "invisibility"sv };

    static_assert(std::size(costs) == max_type);
    static_assert(std::size(name) == max_type);
    static_assert(std::size(types) == max_type); 
};

class Player 
{
private:
    std::string m_name {};
    int m_gold {};
    std::array<int, Potion::max_type> m_inventory{};

public:
    explicit Player(std::string_view name)
        : m_name { name }, m_gold { Random::get(80, 120) }
    {
    }

    std::string_view getName() const { return m_name; }
    int getGold() const { return m_gold; } 
    int inventory(Potion::Type p) const { return m_inventory[p]; }
    void addToInventory(std::size_t index) { ++m_inventory[index]; }
    void removeGold(int cost) { m_gold -= cost; }
};

int charNumToInt(char c)
{
    return c - '0';
}

Potion::Type getDecision()
{
    while (true)
    {
        char input {};
        Potion::Type potion {};

        std::cin >> input;

        if ((charNumToInt(input) > Potion::max_type || charNumToInt(input) < 0) && input != g_CharToQuit || std::cin.peek() != '\n')
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "That is an invalid input. Try again: ";
            continue;
        }   
        for (std::size_t index=0; index < Potion::types.size(); ++index)
        {
            if (charNumToInt(input) == Potion::types[index])
            {
                potion = static_cast<Potion::Type>(index);
                return potion;
            }
            else if (input == g_CharToQuit)
            {
                potion = static_cast<Potion::Type>(Potion::max_type);
                return potion;
            }
        }  
    }
}

void shop()
{
    std::cout << "\nHere is our selection for today:\n";

    for (const auto& p : Potion::types)
    {
        std::cout << p << ") " << Potion::name[p] << " costs " << Potion::costs[p] << '\n';
    }

    return;
}

void playGame(Player& player)
{
    while (true)
    {
        shop();
        std::cout << "Enter the number of the potion you'd like to buy, or 'q' to quit: ";
        Potion::Type potion(getDecision());

        for (std::size_t index{}; index < Potion::types.size(); ++index)
        {
            if (potion == Potion::types[index])
            {
                if (player.getGold() < Potion::costs[index])
                {
                    std::cout << "You can not afford that.\n";
                    continue;
                }
                player.addToInventory(index);
                player.removeGold(Potion::costs[index]);
                std::cout << "You purchased a potion of " << Potion::name[index] << ".  ";
                std::cout << "You have " << player.getGold() << " gold left.\n";
            }
        }
        if (potion == Potion::max_type)
        {
            break;
        }
    }

    std::cout << "\nYour inventory contains:\n";
    for (const auto& e : Potion::types)
    {
        if (player.inventory(e) > 0)
        {
            std::cout << player.inventory(e) << "x potion of " << Potion::name[e] << '\n';
        }
    }
    std::cout << "You escaped with " << player.getGold() << " gold remaining.\n";
}

int main()
{
    std::cout << "Welcome to Roscoe's potion emporium!\n";
    std::cout << "Enter your name: "; 
    
    std::string name{};
    std::getline(std::cin >> std::ws, name);

    Player player { name };

    std::cout << "Hello, " << name << ", you have " << player.getGold() << " gold.\n";

    playGame(player);

    std::cout << "\nThanks for shopping at Roscoe's potion emporium!\n";

    return 0;
}
*/