#include <iostream>
#include <string>
#include <string_view>

class Animal
{
protected:
    std::string m_name{};

public:
    Animal(std::string_view name)
        : m_name{ name }
    {
    }

    const std::string& getName() const { return m_name; }
    virtual std::string_view speak() const = 0;

    virtual ~Animal() = default;
};

std::string_view Animal::speak() const
{
    return "buzz";
} 

class Dragonfly: public Animal
{
public: 
    Dragonfly(std::string_view name)
        : Animal(name)
    {
    }

    std::string_view speak() const override
    {
        return Animal::speak();
    }
};

int main()
{
    Dragonfly dfly { "Sally" };
    std::cout << dfly.getName() << " says " << dfly.speak() << '\n';

    return 0;
}