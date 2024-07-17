#include <iostream>
#include <cmath>


int main()
{
    int k1 {}; // этаж искомой квартиры 
    double k2 {}; // этаж заданной квартиры
    int p1 { 1 }; // подъезд искомой квартиры
    int p2 {}; // подъезд заданной квартиры
    int n1 { 1 }; // этаж искомой квартиры
    int n2 {}; // этаж заданной квартиры
    int m {}; // количество этажей в доме
    int count {}; // количество квартир на одном этаже
    

    std::cin >> k1 >> m >> k2 >> p2 >> n2;

    count = ceil(k2 / n2);

    if (p2 > 1)
    {
        if (p2 * m + count * n2 < k2 || p2 * m + count * (n2 - 1) > k2)
        {
            std::cout << -1 << ' ' << -1;
            return 0;
        }
    }
    else 
    {
        if (count * n2 < k2 || k1 == 0 || m == 0 || k2 == 0 || p2 == 0 || n2 == 0)
        {
            std::cout << -1 << ' ' << -1;
            return 0;
        }
    }

    if (k1 == k2)
    {
        p1 = p2;
        n1 = n2;
        std::cout << p1 << ' ' << n1;
        return 0;
    }

    while (k1 > 0)
    {
        if (m * count < k1)
        {
            p1 += 1;
            n1 = 1;
            k1 -= (m * count);
        }
        else if (count <= 1)
        {
            p1 = 0;
            break;
        }
        else 
            break;
    }

    while (k1 > 0)
    {
        if (k1 > count)
        {
            n1 += 1;
            k1 -= count;
        }
        else 
        {
            break;
        }
    }
    
    std::cout << p1 << ' ' << n1 << ' ';

    return 0;
}