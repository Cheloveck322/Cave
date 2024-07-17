#include <iostream>
#include <string>
#include <string_view>

class Animal
{
protected:
    std::string m_name{};

public:
    Animal(std::string_view name)
        : m_name { name }
    {
    }

    const std::string& getName() const { return m_name; }
    virtual std::string_view speak() const = 0;

    virtual ~Animal() = default;
};

class Cow: public Animal
{
public:
    Cow(std::string_view name)
        : Animal(name)
    {
    }

    std::string_view speak() const override { return "Moo"; }
};

int main()
{
    Cow cow { "Betsy" };
    std::cout << cow.getName() << " says " << cow.speak() << '\n';

    return 0;
}