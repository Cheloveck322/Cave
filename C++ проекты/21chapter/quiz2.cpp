#include <iostream>

class Average
{
private:
    std::int32_t m_sum{};
    std::int8_t m_count{};

public:
    Average()
    {}

    friend std::ostream& operator<<(std::ostream& out, Average& num);

    Average& operator+=(int num)
    {
        m_sum += num;
        ++m_count;

        return *this;
    }
};

std::ostream& operator<<(std::ostream& out, Average& num)
{
    out << static_cast<double>(num.m_sum) / num.m_count;
    return out;
}

int main()
{
	Average avg{};

	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4

	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy{ avg };
	std::cout << copy << '\n';

	return 0;
}