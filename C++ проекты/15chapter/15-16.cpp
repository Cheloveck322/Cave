#include <iostream>


template <typename T, typename C, typename A>
class Triad
{
private:
    T m_first{};
    C m_second{};
    A m_third{};

public:
    Triad(const T& first, const C& second, const A& third):
        m_first{first}, m_second{second}, m_third{third}
    {
    }

    T getFirst() { return m_first; };
    C getSecond() { return m_second; };
    A getThird() { return m_third; };

    void print();
};

template <typename T, typename C, typename A>
void Triad<T, C, A>::print()
{
    std::cout << '[' << m_first << ", " << m_second << ", " << m_third << ']';
}

#include <string>

int main()
{
	Triad<int, int, int> t1{ 1, 2, 3 };
	t1.print();

	using namespace std::literals::string_literals;
	Triad t2{ 1, 2.3, "Hello"s };
	t2.print();

	return 0;
}