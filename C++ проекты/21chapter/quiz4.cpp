#include <iostream>
#include <cassert>
#include <cmath>

class FixedPoint2
{
private:
    std::int16_t m_number{};
    std::int8_t m_fractional{};

public:
    FixedPoint2(std::int16_t number, std::int8_t fractional)
        : m_number { number }, m_fractional { fractional }
    {
        if (m_number < 0 || m_fractional < 0)
        {
            if (m_number > 0)
                m_number = -m_number;

            if (m_fractional > 0)
                m_fractional = -m_fractional;        
        }

        m_number += m_fractional / 100;
        m_fractional = m_fractional % 100;
    }

    FixedPoint2(double fraction):
        FixedPoint2( 
            static_cast<int16_t>(std::trunc(fraction)), 
            static_cast<int8_t>(std::round(fraction * 100) - std::trunc(fraction) * 100) )
    {
    }

    friend std::ostream& operator<<(std::ostream& out, const FixedPoint2& fraction)
    {
        out << static_cast<double>(fraction);
        return out;
    }

    friend std::istream& operator>>(std::istream& in, FixedPoint2& fraction)
    {
        double a{};
        in >> a;
        fraction = FixedPoint2(a);
        return in;
    }

    explicit operator double() const 
    {
        return (m_number + (static_cast<double>(m_fractional) / 100));
    }

    FixedPoint2 operator-() const
    {
        return FixedPoint2
        {
            static_cast<int16_t>(-m_number),
            static_cast<int8_t>(-m_fractional)
        };
    }

    friend bool operator==(const FixedPoint2& a, const FixedPoint2& b)
    {
        return (static_cast<double>(a) == static_cast<double>(b));
    }

};

FixedPoint2 operator+(const FixedPoint2& a, const FixedPoint2& b)
{
    return static_cast<double>(a) + static_cast<double>(b);
}

int main()
{
	assert(FixedPoint2{ 0.75 } == FixedPoint2{ 0.75 });    // Test equality true
	assert(!(FixedPoint2{ 0.75 } == FixedPoint2{ 0.76 })); // Test equality false

	// Test additional cases -- h/t to reader Sharjeel Safdar for these test cases
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 1.98 });    // both positive, no decimal overflow
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 2.25 });    // both positive, with decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -1.98 }); // both negative, no decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -2.25 }); // both negative, with decimal overflow
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -0.48 });  // second negative, no decimal overflow
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -0.75 });  // second negative, possible decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 0.48 });   // first negative, no decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 0.75 });   // first negative, possible decimal overflow

	FixedPoint2 a{ -0.48 };
	assert(static_cast<double>(a) == -0.48);
	assert(static_cast<double>(-a) == 0.48);

	std::cout << "Enter a number: "; // enter 5.678
	std::cin >> a;
	std::cout << "You entered: " << a << '\n';
	assert(static_cast<double>(a) == 5.68);

	return 0;
}   