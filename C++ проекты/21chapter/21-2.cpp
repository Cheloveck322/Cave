#include <iostream>
#include <numeric>
#include <limits>

class Fraction 
{
private:
    int m_numerator{ 0 };
    int m_denominator{ 1 };

public:
    Fraction() = default;

    Fraction(int numerator, int denominator):
        m_numerator { numerator }, m_denominator { denominator }
    {
        reduce();
    }

    void reduce()
    {
        int gcd{ std::gcd(m_numerator, m_denominator) };
        if (gcd)
        {
            m_numerator /= gcd;
            m_denominator /= gcd;
        }
    }

    void print()
    {
        std::cout << m_numerator << '/' << m_denominator << '\n';
    }

    friend Fraction operator*(const Fraction& a, const Fraction& b);
    friend Fraction operator*(const Fraction& a, int value);
    friend Fraction operator*(int value, const Fraction& a);

    friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);
    friend std::istream& operator>>(std::istream& in, Fraction& fraction);
};

Fraction operator*(const Fraction& a, const Fraction& b)
{
    return { a.m_numerator * b.m_numerator, a.m_denominator * b.m_denominator };
}

Fraction operator*(const Fraction& a, int value)
{
    return { a.m_numerator * value, a.m_denominator };
}

Fraction operator*(int value, const Fraction& a)
{
    return a * value;
}

std::ostream& operator<<(std::ostream& out, const Fraction& fraction)
{
    out << fraction.m_numerator << '/' << fraction.m_denominator;
    
    return out;
}

std::istream& operator>>(std::istream& in, Fraction& fraction)
{
    char ignore{};

    in >> fraction.m_numerator >> ignore >> fraction.m_denominator;
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    fraction.reduce();

    return in;
}

int main()
{
	Fraction f1;
	std::cout << "Enter fraction 1: ";
	std::cin >> f1;

	Fraction f2;
	std::cout << "Enter fraction 2: ";
	std::cin >> f2;

	std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n'; // note: The result of f1 * f2 is an r-value

	return 0;
}