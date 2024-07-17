#include <iostream>


class PhoneNumber
{
public:
    explicit PhoneNumber(std::string_view cod = "495", std::string_view number):
        m_cod { cod }, m_number { number }
    {
    }

    void setCod(std::string_view cod) { m_cod = cod; };
    void setNumber(std::string_view number) { m_number = number; };

private:
    
    std::string m_cod { "495" };
    std::string m_number { };
};

int main()
{
    std::string phoneNumber{};
    std::string cod{};
    std::string number{};

    std::cin >> phoneNumber;



    return 0;
}