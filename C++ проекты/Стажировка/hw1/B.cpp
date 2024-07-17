#include <iostream> 



class Treangle
{
public:
    Treangle() = default;

    explicit Treangle(int a, int b, int c):
        m_a { a }, m_b { b }, m_c { c }
    {
    } 

    friend void isTrngl(const Treangle& abc);

private:
    int m_a { 0 };
    int m_b { 0 };
    int m_c { 0 };
};


void isTrngl(const Treangle& abc)
{
    if (abc.m_a + abc.m_b > abc.m_c && abc.m_a + abc.m_c > abc.m_b && abc.m_b + abc.m_c > abc.m_a)
        std::cout << "YES";
    else 
        std::cout << "NO";
}


int main()
{
    int a{};
    int b{};
    int c{};
    std::cin >> a >> b >> c;

    Treangle abc { a, b, c };
    

    isTrngl(abc);

    return 0;
}