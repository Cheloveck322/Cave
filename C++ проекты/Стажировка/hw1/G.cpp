#include <iostream>


int main()
{
    int n { }; // металлический сплав
    int k { }; // заготовки 
    int m { }; // деталь 

    int countDet { };

    std::cin >> n >> k >> m;

    if (n < k || k < m)
    {
        std::cout << countDet;
        return 0;
    }

    while (n >= k)
    {
        n -= k;
        countDet += k / m;
        n += k % m;
    }
    
    std::cout << countDet;

    return 0;
}