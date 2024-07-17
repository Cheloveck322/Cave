#include <iostream>
#include <algorithm>

unsigned int reverseInt(unsigned int n)
{
    unsigned int reversed{};

    while (n > 10)
    {
        unsigned int lastDigit { n % 10 };
        reversed = reversed * 10 + lastDigit;
        n /= 10;
    }
    return reversed;
}

bool isPolindromic(unsigned int n)
{
    unsigned int a { reverseInt(n) };
    return (a == n ? true : false);
}

int convertToBase(int n, int base)
{
    unsigned int converted{};
    if (n < base)
        return n;
    
    int lastDigit { n % base };
    converted = convertToBase(n / base, base) * 10 + lastDigit;
    return converted;
}

bool isStrictlyPolindromic(int n)
{
    bool flag { true };
    for (int base{ 2 }; base <= (n - 2); ++base)
    {
        if (isPolindromic(convertToBase(n, base)) == false)
        {
            flag = false;
            break;
        }
    }
    return flag;
}

int main()
{
    int a {};
    std::cout << "Enter number: ";
    std::cin >> a;

    std::cout << std::boolalpha << isStrictlyPolindromic(a);

    return 0;
}