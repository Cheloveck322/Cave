#include <iostream>

int sumDigits(int number)
{
    if (number < 10)
        return number;
    
    return sumDigits(number / 10) + number % 10;
}

int main()
{
    std::cout << "Sum of digit of 93427 is " << sumDigits(93427) << '\n';

    return 0;
}