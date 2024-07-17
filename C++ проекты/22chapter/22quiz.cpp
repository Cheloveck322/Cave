#include <iostream>
#include <memory>
#include <utility>

class Fraction
{
private:
    int m_numerator{ 0 };
    int m_denominator{ 1 };

public: 
    Fraction(int numerator = 0, int denominator = 1):
        m_numerator { numerator }, m_denominator { denominator }
    {
        std::cout << "Fraction created\n";
    }

    ~Fraction()
    {
        std::cout << "Fraction destroyed\n";
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f)
    {
        out << f.m_numerator << '/' << f.m_denominator;
        return out;
    }

    
};

/*void printFraction(std::unique_ptr<Fraction> ptr)
{
    if (ptr)
        std::cout << *ptr << '\n';
    else 
        std::cout << "No fraction\n";
}*/

void printFraction(const Fraction* ptr)
{
	if (ptr)
		std::cout << *ptr << '\n';
	else
		std::cout << "No fraction\n";
}

int main()
{
    auto ptr { std::make_unique<Fraction>() };

    printFraction(ptr.get());

    return 0;
}