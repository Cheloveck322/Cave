#include <iostream>
#include <string>
#include <sstream>
#include <string_view>
#include <numeric>
#include "Random.h"

class Potion
{
public:
	enum Type
	{
		Health,
		Strength,
		Poison,
		all_types
	};

	enum Size
	{
		Small,
		Medium,
		Large,
		all_sizes
	};

	Potion(Type type, Size size)
		: m_type { type }, m_size { size }
	{
	}

	Type getType() const { return m_type; }
	Size getSize() const { return m_size; }

	static std::string_view getPotionTypeName(Type type)
	{
		static constexpr std::string_view names[all_types] {
			"Health",
			"Strength",
			"Poison"
		};

		return names[type];
	}

	static std::string_view getPotionSizeName(Size size)
	{
		static constexpr std::string_view effects[all_sizes] {
			"Small",
			"Medium",
			"Large"
		};

		return effects[size];
	}

	std::string getName() const 
	{
		std::stringstream result{};

		result << getPotionSizeName(getSize()) << " potion of " << getPotionTypeName(getType());

		return result.str();
	}

	static Potion getRandomPotion()
	{
		return { 
			static_cast<Type>(Random::get(0, all_types - 1)), 
			static_cast<Size>(Random::get(0, all_sizes - 1))
		};
	}
	
private:	
	Type m_type{};
	Size m_size{};
};

class Creature
{
public:
	Creature(std::string_view name, char symbol, int health, int attack, int gold)
		: m_name{name}
		, m_symbol{symbol}
		, m_health{health}
		, m_attack{attack}
		, m_gold{gold}
	{
	}

	const std::string& getName() const { return m_name; }
	char getSymbol() const { return m_symbol; }
	int getHealth() const { return m_health; }
	int getAttack() const { return m_attack; }
	int getGold() const { return m_gold; }

	void addGold(int gold){ m_gold += gold; }
	void reduceHealth(int damage){ m_health -= damage; }
	bool isDead() const { return (m_health <= 0); }

protected:
	std::string m_name{};
	char m_symbol{};
	int m_health{};
	int m_attack{};
	int m_gold{};
};

class Player: public Creature
{
public:
	Player(std::string_view name)
		: Creature(name, '@', 10, 1, 0)
	{
	}

	int getLevel() const { return m_level; }
	bool hasWon() const { return m_level >= 20; }

	void levelUp()
	{
		++m_level;
		++m_attack;
	}

	void drinkPotion(const Potion& potion)
	{
		switch (potion.getType())
		{
		case Potion::Health:
			m_health += ((potion.getSize() == Potion::Large) ? 5 : 2);
			break;
		case Potion::Strength:
			m_attack += ((potion.getSize() == Potion::Large) ? 4 : 1);
			break;
		case Potion::Poison:
			reduceHealth((potion.getSize() == Potion::Large) ? 5 : 1);
			break;
		case Potion::all_types:
			break;
		}
	}

private:
	int m_level{ 1 };
};

class Monster: public Creature
{
public:
	enum Type
	{
		dragon,
		orc,
		slime,
		max_types
	};

	static inline Creature monsterData[] 
	{
		{ "dragon", 'D', 20, 4, 100 },
		{ "orc", 'o', 4, 2, 25 },
		{ "slime", 's', 1, 1, 10 }
	};

	Monster(Type type)
		: Creature{ monsterData[type] }
	{
	}

	static Monster getRandomMonster()
	{
		return static_cast<Type>(Random::get(0, max_types-1));
	}
}; 

void onMonsterKilled(Player& player, const Monster& monster)
{
    std::cout << "You killed the " << monster.getName() << ".\n";
    player.levelUp();
    std::cout << "You are now level " << player.getLevel() << ".\n";
    std::cout << "You found " << monster.getGold() << " gold.\n";
    player.addGold(monster.getGold());

    // 30% chance of finding a potion
    constexpr int potionChance{ 30 };
    if (Random::get(1, 100) <= potionChance)
    {
        // Generate a random potion
        auto potion{ Potion::getRandomPotion() };

        std::cout << "You found a mythical potion! Do you want to drink it? [y/n]: ";
        char choice{};
        std::cin >> choice;

        if (choice == 'Y' || choice == 'y')
        {
            // Apply the effect
            player.drinkPotion(potion);
            // Reveal the potion type and size
            std::cout << "You drank a " << potion.getName() << ".\n";
        }
    }
}

std::string getName()
{
	std::cout << "Enter your name: ";
	std::string name{};
	std::cin >> name;
	return name;
}

bool escape() //returns true if chance more 50
{
	int chance { Random::get(1, 100) };
	return (chance > 50 ? true : false);
}

char getDecision()
{
	while(true)
	{
		char decision{}; 
		std::cout << "(R)un or (F)ight: ";
		std::cin >> decision;

		if (!std::cin)
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.clear();
		}
		else
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			switch (decision)
			{
			case 'R':
			case 'r':
			case 'F':
			case 'f':
				return decision;
			
			default:
				std::cout << "Invalid input, try again.\n";
				break;
			}
		}
	}
}

bool fightOrRun() // returns true if player fights and vice-versa
{
	char decision { getDecision() };
	if (decision == 'f' || decision == 'F')
		return true;
	return false;
}

void attackMonster(Player& player, Monster& monster)
{
	if(player.isDead())
		return;

	std::cout << "You hit the " << monster.getName() << " for " << player.getAttack() << " damage.\n";

	monster.reduceHealth(player.getAttack());

	if (monster.isDead()) 
	{
		onMonsterKilled(player, monster);
	}
}

void attackPlayer(Player& player, Monster& monster)
{
	if(monster.isDead())
		return;

	player.reduceHealth(monster.getAttack());
	std::cout << "The " << monster.getName() << " hit you for " << monster.getAttack() << " damage.\n";
}

void fightMonster(Player& player)
{
	Monster monster{ Monster::getRandomMonster() };
	std::cout << "You have encountered a " << monster.getName() << " (" << monster.getSymbol() << ").\n";

	while (!monster.isDead() && !player.isDead())
	{
		if (fightOrRun())
		{
			attackMonster(player, monster);

			if (monster.isDead())
				return;
			
			attackPlayer(player, monster);
		}
		else
		{
			if (escape())
			{
				std::cout << "You successfully fled.\n";
				return;
			}
			else 
			{
				std::cout << "You failed to flee.\n";
				attackPlayer(player, monster);
				continue;
			}
		}
	}
}

void winOrLose(Player& player)
{
	if (player.hasWon())
	{
		std::cout << "You win at level " << player.getLevel() << " and with " << player.getGold() << " gold.\n";
	}
	else if (player.isDead())
	{
		std::cout << "You died at level " << player.getLevel() << " and with " << player.getGold() << " gold.\n";
		std::cout << "Too bad you can't take it with you!\n";
	}
	else 
		return;
}

int main()
{
	Player player{ getName() };

	std::cout << "Welcome, " << player.getName() << '\n';

	while(!player.isDead() && !player.hasWon())
		fightMonster(player);
	
	winOrLose(player);

	return 0;
}