#include <iostream>
#include <algorithm>
#include <map>

class Laptop
{
private:
    int m_a{};
    int m_b{};

public:
    Laptop() = default;

    Laptop(int a, int b)
        : m_a { a }, m_b { b }
    {
    }

    friend std::ostream& operator<<(std::ostream& out, const Laptop& l);
    friend std::istream& operator>>(std::istream& in, Laptop& l);

    int getSquare() const { return m_a * m_b; }
    int getLength() const { return m_a; }
    int getWidth() const { return m_b; }
};

class Table : public Laptop
{

};

std::ostream& operator<<(std::ostream& out, const Laptop& l)
{
    out << l.m_a << ' ' << l.m_b;
    return out;
}

std::istream& operator>>(std::istream& in, Laptop& l)
{
    in >> l.m_a;
    in >> l.m_b;
    return in;
}

int min(const std::map<int, int>& list)
{
    int min {};
    for (const auto element : list)
    {  
        min = std::min(min, element.first);
    }
    return min;
}

int main()
{
    Laptop l1{};
    Laptop l2{};

    std::cin >> l1;
    std::cin >> l2;

    std::map<int, int> list{};
    list[std::max(l1.getLength(), l2.getLength()) * (l1.getWidth() + l2.getWidth())] = 0;
    list[std::max(l1.getLength(), l2.getWidth()) * (l1.getWidth() + l2.getLength())] = 1;
    list[std::max(l1.getWidth(), l2.getLength()) * (l1.getLength() + l2.getWidth())] = 2;
    list[std::max(l1.getWidth(), l2.getWidth()) * (l1.getLength() + l2.getLength())] = 3;

    std::cout << min(list) << '\n';

    if (min(list) == list[0])
    {
        std::cout << std::max(l1.getLength(), l2.getLength()) * (l1.getWidth() + l2.getWidth()) << '\n';
    }
    else if (min(list) == list[1])
    {
        std::cout << std::max(l1.getLength(), l2.getWidth()) * (l1.getWidth() + l2.getLength()) << '\n';
    }
    else if (min(list) == list[2])
    {
        std::cout << std::max(l1.getWidth(), l2.getLength()) * (l1.getLength() + l2.getWidth()) << '\n';
    }
    else 
    {
        std::cout << std::max(l1.getWidth(), l2.getWidth()) * (l1.getLength() + l2.getLength()) << '\n';
    }

    return 0;
}