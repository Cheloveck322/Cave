#include <iostream>
#include <algorithm>

class ParkingSystem {
private:
    int m_countBig{};
    int m_countMedium{};
    int m_countSmall{};

public:
    ParkingSystem(int big, int medium, int small)
        : m_countBig{ big }, m_countMedium{ medium }, m_countSmall{ small }
    {
    }
    
    bool addCar(int carType) {
        switch(carType)
        {
            case 3:
                if (m_countSmall > 0)
                {
                    --m_countSmall;
                    return true;
                }
            case 2:
                if (m_countMedium > 0)
                {
                    --m_countMedium;
                    return true;
                }
            case 1:
                if (m_countBig > 0)
                {
                    --m_countBig;
                    return true;
                } 
        }
        return false;
    }

    int getCountBiggest() const
    {
        return std::max(m_countBig, std::max(m_countMedium, m_countSmall));
    }
};

int main()
{
    ParkingSystem p{ 321, 224, 74 };

    int countBig { 321 };
    int countMedium { 224 };
    int countSmall { 74 };

    for (int index {}; index < p.getCountBiggest(); ++index)
    {
        std::cout << std::boolalpha;
    }

    return 0;
}