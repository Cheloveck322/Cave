#include <iostream>


class Laptop
{
private:    
    int m_a{};
    int m_b{};

public:
    Laptop(int a = 0, int b = 0):
        m_a { a }, m_b { b }
    {
    }

    friend std::istream& operator>>(std::istream& in, Laptop& l1);
    friend std::ostream& operator<<(std::ostream& out, const Laptop& l1);

    void setData(int a, int b) { m_a = a; m_b = b; };

    Laptop getSize() const { return Laptop{m_a, m_b}; };

    int getMax() const { return (m_a > m_b ? m_a : m_b); }; 
    int getMin() const { return (m_b > m_a ? m_a : m_b); }; 
};

std::ostream& operator<<(std::ostream& out, const Laptop& l1)
{
    out << l1.m_a << ' ' << l1.m_b;

    return out;
}


std::istream& operator>>(std::istream& in, Laptop& l1)
{
    in >> l1.m_a;
    in >> l1.m_b;

    return in;
}

Laptop takeTable(const Laptop& l1, const Laptop& l2)
{
    Laptop table{};
    

    if (l1.getMax() > l2.getMax() && l1.getMin() > l2.getMin()) //если первый ноутбук больше по всем показателям второго
    {
        if (l2.getMax() < l1.getMin())
            table = { l1.getMax() + l2.getMin(), l1.getMin() };
        else 
            table = { l1.getMax(), l1.getMin() + l2.getMin() };
    }
    else if (l1.getMax() < l2.getMax() && l1.getMin() < l2.getMin()) // если второй ноутбук больше по всем показателям первого
    {
        if (l1.getMax() < l2.getMin())
            table = { l2.getMax() + l1.getMin(), l2.getMin() };
        else 
            table = { l2.getMax(), l1.getMin() + l2.getMin() };
    }
    /*
    else if (l1.getMax() > l2.getMax() && l1.getMin() < l2.getMin()) // если длина первого ноутбука больше чем второго, но ширина меньше 
    {
        if ((l1.getMax() + l2.getMax()) * std::max(l1.getMin(), l2.getMin()) < std::max(l1.getMax(), l2.getMax()) * (l1.getMin() + l2.getMin()))
            table = { l1.getMax() + l2.getMax(), std::max(l1.getMin(), l2.getMin()) };
        else 
            table = { std::max(l1.getMax(), l2.getMax()), (l1.getMin() + l2.getMin()) };
    }
    else if (l1.getMax() < l2.getMax() && l1.getMin() > l2.getMin())
    {
        if ((l1.getMax() + l2.getMax()) * std::max(l1.getMin(), l2.getMin()) < std::max(l1.getMax(), l2.getMax()) * (l1.getMin() + l2.getMin()))
            table = { l1.getMax() + l2.getMax(), std::max(l1.getMin(), l2.getMin()) };
        else 
            table = { std::max(l1.getMax(), l2.getMax()), (l1.getMin() + l2.getMin()) };
    }
    */
    else 
    {
        if ((l1.getMax() + l2.getMax()) * std::max(l1.getMin(), l2.getMin()) < std::max(l1.getMax(), l2.getMax()) * (l1.getMin() + l2.getMin()))
        {
            table = { l1.getMax() + l2.getMax(), std::max(l1.getMin(), l2.getMin()) };
        }
        else 
        {
            table = { std::max(l1.getMax(), l2.getMax()), (l1.getMin() + l2.getMin()) };
        }
    }

    return table;
}


int main()
{
    Laptop l1{};
    Laptop l2{};

    std::cin >> l1 >> l2;

    Laptop table{ takeTable(l1, l2) };

    std::cout << table;

    return 0;
}