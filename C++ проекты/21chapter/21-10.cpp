#include <iostream>
#include <string_view>
#include <string>
#include <cassert>

class MyString
{
private:
    std::string m_str{};

public:
    MyString(std::string_view str = {}):
        m_str { str }
    {}

    friend std::ostream& operator<<(std::ostream& out, const MyString& str);

    std::string_view operator()(int index, int count);
};

std::string_view MyString::operator()(int index, int count)
{
    assert(index >= 0);
    assert(index + count <= static_cast<int>(m_str.length()) && "MyString::operator(int, int): Substring is out of range");

    return std::string_view{m_str}.substr(static_cast<std::string::size_type>(index), static_cast<std::string::size_type>(count));
}

std::ostream& operator<<(std::ostream& out, const MyString& str)
{
    out << str.m_str;
    
    return out;
}

int main()
{
    MyString s { "Hello, world!" };
    std::cout << s(7, 5) << '\n'; // start at index 7 and return 5 characters

    return 0;
}