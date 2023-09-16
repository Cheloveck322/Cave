#include <iostream>
#include <string>
#include <string_view>
#include "Random.h"
#include <array>




class Monster
{
public:
    enum Type
    {
        dragon,
        goblin,
        ogre,
        orc,
        skeleton,
        troll,
        vampire,
        zombie,
        max_monster_types
    };

private:
    Type m_type{};
    std::string m_name{};
    std::string m_roar{};
    int m_hitPoints{};

public:
    Monster(Type type, std::string_view name, std::string_view raor, int hitPoints):
        m_type{ type },
        m_name{ name },
        m_roar{ raor },
        m_hitPoints{ hitPoints }
    {
    }

    std::string_view getTypeString() const
    {
        switch (m_type)
        {
        case Type::dragon: return "dragon";
        case Type::goblin: return "goblin";
        case Type::ogre: return "ogre";
        case Type::orc: return "orc";
        case Type::skeleton: return "skeleton";
        case Type::troll: return "troll";
        case Type::vampire: return "vampire";
        case Type::zombie: return "zombie";
        default: return "???";
        }
    }

    void print()
    {
        std::cout << m_name << " the " << getTypeString() << " has " << m_hitPoints << " hit points and says " << m_roar << '\n';
    }
};

namespace MonsterGenerator
{
    Monster generate()
    {
        static constexpr std::array s_names{"Bones", "James", "BLAH-BLAH", "Jah'rakal", "Sploon", "Smaug"};
        static constexpr std::array s_roars{"*rattle*", "ARGH!!!", "KIYA!!!", "EEEEAT!", "*grinding*", "*scary sounds*"};
        return {static_cast<Monster::Type>(Random::get<std::size_t>(0, Monster::Type::max_monster_types - 1)), s_names[Random::get<size_t>(0,6)], s_roars[Random::get<size_t>(0,6)], Random::get<int>(1,100)};
    }
}


int main()
{
	Monster m{ MonsterGenerator::generate() };  
	m.print();

	return 0;
}