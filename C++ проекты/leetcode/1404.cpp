#include <iostream>
#include <string>
#include <cmath>
#include <memory>

unsigned long long int pow(int x, int y)
{
    unsigned long long int answer { 1 };
    while (y > 0)
    {
        answer *= x;
        --y;
    }
    return answer;
}

void convertStringToInt(std::string& s, std::unique_ptr<unsigned long long int>& num)
{
    while(s.size() > 0)
    {
        if (*s.begin() == '1')
        {
            *num += pow(2, s.length() - 1);
        }
        s.erase(s.begin());
    }
}

int numSteps(std::string& s)
{
    auto num { std::make_unique<unsigned long long int>() };
    convertStringToInt(s, num);
    int count {};
    while (*num > 1)
    {
        if (*num % 2 == 0)
        {
            *num /= 2;
            ++count;
        }
        else 
        {
            ++*(num);
            ++count;
        }
    }
    return count;
}

int main()
{
    std::string str { "100100001010010101101000111100100111101111000111111010010001100001000100011001" };
    auto ptrNum { std::make_unique<unsigned long long int>() };
    convertStringToInt(str, ptrNum);

    std::cout << "Converted binary string to int " << *ptrNum << '\n';
    std::cout << "Number of steps is " << numSteps(str) << '\n';

    return 0;
}