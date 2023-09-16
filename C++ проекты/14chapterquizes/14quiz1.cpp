#include <iostream>



class Fraction 
{
public:
    Fraction(int numerator = 0, int denominator = 0):
            m_numerator{numerator}, m_denominator{denominator}
    {}

    void getFraction()
    {
        std::cout << "Enter a value for numerator: "; 
        std::cin >> m_numerator;
        std::cout << "Enter a value for denominator: "; 
        std::cin >> m_denominator;
    }

    void printFraction()
    {
        std::cout << m_numerator << '/' << m_denominator << '\n';
    }

    Fraction multiply(Fraction& fraction)
    {
        return { m_numerator * fraction.m_numerator, m_denominator * fraction.m_denominator};
    }
private:
    int m_numerator { 0 };
    int m_denominator { 0 };
};



int main()
{
    Fraction f1{};
    f1.getFraction();

    Fraction f2{};
    f2.getFraction();

    std::cout << "Your fractions multiplied together: ";

    f1.multiply(f2).printFraction();

    return 0;
}