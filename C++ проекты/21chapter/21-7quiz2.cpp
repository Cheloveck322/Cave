#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>

class Car
{
private:
    std::string m_make;
    std::string m_model;

public:
    Car(std::string_view make, std::string_view model)
        : m_make{ make }, m_model{ model }
    {
    }

    friend bool operator== (const Car& c1, const Car& c2);
    friend bool operator!= (const Car& c1, const Car& c2);

    friend std::ostream& operator<<(std::ostream& out, const Car& car);
    friend bool operator<(const Car& car1, const Car& car2);
};

std::ostream& operator<<(std::ostream& out, const Car& car)
{
    out << '(' << car.m_make << ", " << car.m_model << ')#include <iostream>

// ...

int main()
{
	GradeMap grades{};

	grades["Joe"] = 'A';
	grades["Frank"] = 'B';

	std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
	std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

	return 0;
}';

    return out; 
}

bool operator<(const Car& car1, const Car& car2)
{
    return (car1.m_make < car2.m_make || car1.m_model < car2.m_model);
}

bool operator== (const Car& c1, const Car& c2)
{
    return (c1.m_make == c2.m_make &&
            c1.m_model == c2.m_model);
}

bool operator!= (const Car& c1, const Car& c2)
{
    return (c1.m_make != c2.m_make ||
            c1.m_model != c2.m_model);
}

int main()
{
    std::vector<Car> cars{
        { "Toyota", "Corolla" },
        { "Honda", "Accord" },
        { "Toyota", "Camry" },
        { "Honda", "Civic" }
    };

    std::sort(cars.begin(), cars.end()); // requires an overloaded operator<

    for (const auto& car : cars)
        std::cout << car << '\n'; // requires an overloaded operator<<

    return 0;
}