#include <iostream>

class Hole;

class Brick
{
public:
    Brick(int a = 1, int b = 1, int c = 1):
        m_a { a }, m_b { b }, m_c { c }
    {
    }

    friend std::istream& operator>>(std::istream& in, Brick& brick);

    Hole getLowerSide() const;

    int getMax() const { return std::max(std::max(m_a, m_b), m_c); }
    int getMin() const { return std::min(std::min(m_a, m_b), m_c); }

private:
    int m_a {};
    int m_b {};
    int m_c {};
};

std::istream& operator>>(std::istream& in, Brick& brick)
{
    in >> brick.m_a;
    in >> brick.m_b;
    in >> brick.m_c;

    return in;
}

class Hole
{
public:
    Hole(int d = 1, int e = 1):
        m_d { d }, m_e { e }
    {
    }

    friend std::istream& operator>>(std::istream& in, Hole& hole);

    friend bool operator==(const Hole& hole1, const Hole& hole2) { return hole1.m_d == hole2.m_d && hole1.m_e == hole2.m_e; };
    friend bool operator!=(const Hole& hole1, const Hole& hole2) { return !(operator==(hole1, hole2)); };

    friend bool operator<(const Hole& hole1, const Hole& hole2) { return hole1.m_d < hole2.m_d && hole1.m_e < hole2.m_e; };
    friend bool operator>(const Hole& hole1, const Hole& hole2) { return operator<(hole2, hole1); };

    friend bool operator<=(const Hole& hole1, const Hole& hole2) { return !(operator>(hole1, hole2)); };
    friend bool operator>=(const Hole& hole1, const Hole& hole2) { return !(operator<(hole1, hole2)); };

    int getMax() const { return std::max(m_d, m_e); }
    int getMin() const { return std::min(m_d, m_e); }

private:
    int m_d {};
    int m_e {};
};

Hole Brick::getLowerSide() const // возвращает минимальную грань
{
    int AB{ m_a * m_b };
    int AC{ m_a * m_c };
    int BC{ m_b * m_c };

    Hole min{};
    
    if (std::min(BC, std::min(AB, AC)) == AB)
        min = { m_a, m_b };
    else if (std::min(BC, std::min(AB, AC)) == AC) 
        min = { m_a, m_c };
    else
        min = { m_b, m_c };

    return min;
}

std::istream& operator>>(std::istream& in, Hole& hole)
{
    in >> hole.m_d;
    in >> hole.m_e;

    return in;
}

bool throwBrick(const Brick& brick, const Hole& hole)
{
    if (brick.getLowerSide() <= hole)
    {
        if (brick.getLowerSide().getMax() <= hole.getMax() && brick.getLowerSide().getMin() <= hole.getMin())
        {
            return true;
        }
    }
    return false;
}


int main()
{
    Brick brick{};
    Hole hole{};

    std::cin >> brick >> hole;

    if (throwBrick(brick, hole))
        std::cout << "YES";
    else 
        std::cout << "NO";

    return 0;
}