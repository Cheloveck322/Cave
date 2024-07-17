#include <iostream>
#include <stdexcept>
#include <exception>

class Fraction
{
private:
    int m_numerator{ 0 };
    int m_denominator{ 1 };

public:
    Fraction(int numerator=0, int denominator=1)
        : m_numerator { numerator }, m_denominator { denominator } 
    {
        if (denominator == 0)
            throw std::runtime_error("Invalid denominator");
    }
    
    friend std::ostream& operator<<(std::ostream& out, const Fraction& fr)
    {
        out << fr.m_numerator << '/' << fr.m_denominator;
        return out;
    }
};

int main()
{
    int numerator{ 0 };
    std::cout << "Enter the numerator: ";
    std::cin >> numerator;

    int denominator{ 1 };
    std::cout << "Enter the denominator: ";
    std::cin >> denominator; 

    try 
    {
        Fraction f{ numerator, denominator };
        std::cout << "Your fraction is: " << f << '\n';
    }
    catch(std::runtime_error err)
    {
        std::cerr << err.what();
        return 0;
    }

    return 0;
}