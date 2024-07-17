#include <iostream>
#include <string>
#include <string_view>


class Cond
{
public:
    Cond() = default;

    explicit Cond(int tempR, int tempC, std::string_view mode):
        m_tRoom { tempR }, m_tCond { tempC }, m_mode { mode }
    {
    }

    void setTRoom(int temp) { m_tRoom; };
    void setTCond(int temp) { m_tCond = temp; };
    void setMode(std::string_view mode) { m_mode = mode; }; 

    friend int getTemperature(const Cond& temp);

private:
    int m_tRoom { 0 };
    int m_tCond { 0 };
    std::string m_mode {};
};

int getTemperature(const Cond& temp)
{
    if (temp.m_mode == "freeze")
    {
        if (temp.m_tRoom > temp.m_tCond)
        {
            return temp.m_tCond;
        }
        else
        {
            return temp.m_tRoom;
        }
    }

    if (temp.m_mode == "heat")
    {
        if (temp.m_tRoom > temp.m_tCond)
        {
            return temp.m_tRoom;
        }
        else
        {
            return temp.m_tCond;
        }
    }

    if (temp.m_mode == "auto")
    {
        return temp.m_tCond;
    }   

    if (temp.m_mode == "fan")
    {
        return temp.m_tRoom;
    }

    return 0;
}


int main()
{
    int tRoom{}; 
    int tCond{};
    std::string mode{};
    std::cin >> tRoom >> tCond >> mode;


    Cond temp{tRoom, tCond, mode};

    std::cout << getTemperature(temp);
    
    return 0;
}