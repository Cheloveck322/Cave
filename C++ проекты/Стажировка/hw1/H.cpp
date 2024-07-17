#include <iostream>



int main()
{
    int a { }; // интервал на пути 1
    int b { }; // интервал на пути 2
    int n { }; // количество поездов на пути 1
    int m { }; // количество поездов на пути 2
    int stop { 1 }; // время ожидания поезда на станции

    int min { };
    int max { };

    int countN { }; // счетчик поездов для пути 1
    int countM { }; // счетчик поездов для пути 2
    
    std::cin >> a >> b >> n >> m;

    for (int minute{ 1 }; ; ++minute) // начинаем со второй минуты, потому что в первой минуте уже поезд есть 
    {
        if (minute >= (a + stop))
        {
            if ((minute - stop) % (a + stop) == 0)
            {
                ++countN;   
            }

            if ((minute - stop) % (b + stop) == 0)
            {
                ++countM;
            }
        }
        
        else
        {
            if ((minute - stop) / (a + stop) == 0)
            {
                ++countN;   
            }
            if ((minute - stop) / (b + stop) == 0)
            {
                ++countM;   
            }
        }

        if (countN == n && countM == m)
        {
            if (min > 0)
                continue;
            else 
                min = minute;
        }

        if (countN > n || countM > m)
        {
            max = minute;
            break;
        }

        if (countN < n && countM >= m || countN >= n && countM < m)
        {
            std::cout << -1;
            return 0;
        } 
    }

    std::cout << min << ' ' << max;

    return 0;
}