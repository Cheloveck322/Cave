#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

constexpr int size_table { 10 };

template<typename T>
void swap(T& a, T& b)
{
    T c { a };
    a = b;
    b = c;
}

int hashFunction(int x)
{
    return x % 10;
}

class Colomn
{
private:
    std::list<int> m_list{};
    int m_size { static_cast<int>(m_list.size()) };

public:
    Colomn() = default;

    Colomn(int size)
        : m_size{ size }, m_list {}
    {
    }

    Colomn(int size, int element)
        : m_size{ size }, m_list { element }
    {
    }

    void remove(int x)
    {
        for (auto e { m_list.begin() }; e != m_list.end(); ++e)
        {
            if (*e == x)
            {
                m_list.erase(e);
                return;
            }
        }
        std::cout << "There is no such number.\n";
    }

    void add(int x)
    {
        m_list.push_back(x);
    }

    bool find(int x) const
    {
        for (int a : m_list)
        {
            if ( a == x )
            {
                return true;
            }
        }
        return false;
    }

    void printColomn() const
    {
        for (auto e : m_list)
        {
            if (e != 0)
                std::cout << e << ' ';
        }
    }

    bool isNull() const
    {
        return (m_list.size() > 0 ? true : false);
    }
};

class Table
{
private:
    int m_size{};
    std::vector<Colomn> m_cell{};

public:
    Table(int size)
        : m_size { size }, m_cell(size)
    {
    }

    Colomn& getColomn(int index)
    {
        return m_cell[index];
    }

    bool find(int x) const
    {
        for (const auto& a : m_cell)
        {
            if (a.find(x))
            {
                return true;
            }
        }
        return false;
    }

    void add(int x)
    {
        m_cell[hashFunction(x)].add(x);
    }

    void remove(int x)
    {
        m_cell[hashFunction(x)].remove(x);
    }

    void print()
    {
        for (auto& a : m_cell)
        {
            a.printColomn();
            if (a.isNull())
            {
                std::cout << '\n';
            }
        }
    }
};

int main()
{
    Table table { size_table };

    table.add(89);
    table.add(100);
    table.add(32);
    table.add(19);
    table.add(1011);
    table.add(59);
    table.add(43);
    table.add(83);
    table.add(93);
    table.add(103);
    table.add(10);
    table.add(1000);

    table.remove(19);

    table.print();

    return 0;
}