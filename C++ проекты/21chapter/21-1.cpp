#include <iostream>
#include <numeric>

class Fraction 
{
private:
    int m_numerator{ 0 };
    int m_denominator{ 1 };

public:
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

int main()
{
    Fraction f1{2, 5};
    f1.print();

    Fraction f2{3, 8};
    f2.print();

    Fraction f3{ f1 * f2 };
    f3.print();

    Fraction f4{ f1 * 2 };
    f4.print();

    Fraction f5{ 2 * f2 };
    f5.print();

    Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
    f6.print();

    Fraction f7{0, 6};
    f7.print();

    return 0;
}