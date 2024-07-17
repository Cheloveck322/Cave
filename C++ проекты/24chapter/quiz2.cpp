#include <iostream>
#include <string>
#include <string_view>

class Fruit
{
public:
    Fruit(std::string_view name, std::string_view color)
        : m_name { name }, m_color { color }
    {
    }

    const std::string& getName() const { return m_name; }
    const std::string& getColor() const { return m_color; }

private:
    std::string m_name{};
    std::string m_color{};
};

class Apple: public Fruit
{
protected:  
    Apple(std::string_view name, std::string_view color)
        :   Fruit{ name, color }
    {
    }

public:
    Apple(std::string_view color="red")
        : Fruit{ "apple", color }
    {
    }
};

class Banana: public Fruit
{
public: 
    Banana()
        : Fruit{ "banana", "yellow" }
    {
    }
};

class GrannySmith: public Apple
{
public: 
    GrannySmith(std::string_view name="granny smith apple", std::string_view color="green")
        : Apple{ name, color }
    {
    }
};

int main()
{
	Apple a{ "red" };
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

	return 0;
}