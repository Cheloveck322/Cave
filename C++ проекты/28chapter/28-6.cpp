#include <algorithm>
#include <cctype>
#include <map>
#include <iostream>
#include <string_view>
#include <string>

bool inputMathces(std::string_view input, std::string_view pattern)
{
    if (input.length() != pattern.length())
    {
        return false;
    }

    static const std::map<char, int (*)(int)> validators{
        { '#', &std::isdigit },
        { '_', &std::isspace },
        { '@', &std::isalpha },
        { '?', [](int) { return 1; } }
    };

    return std::equal(input.begin(), input.end(), pattern.begin(), [](char ch, char mask) -> bool {
        auto found { validators.find(mask) };

        if (found != validators.end())
        {
            return (*found->second)(ch);
        }

        return ch == mask;
    });
}

int main()
{
    std::string phoneNumber{};

    do
    {
        std::cout << "Enter a phone number (###) ###-####: ";
        std::getline(std::cin, phoneNumber);
    } while(!inputMathces(phoneNumber, "(###) ###-####"));

    std::cout << "You entered " << phoneNumber << '\n';

    return 0;
}