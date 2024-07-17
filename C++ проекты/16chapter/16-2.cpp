#include <vector>
#include <iostream>

int main()
{
    std::vector<int> number(3);
    int sum{ 0 };
    int product{ 1 };

    std::cout << "Enter 3 integers: ";

    for (int index{}; index < number.size(); ++index)
    {
        std::cin >> number[index];
        sum += number[index];
        product *= number[index];
    }

    std::cout << "The sum is: " << sum << '\n';
    std::cout << "The product is: " << product << '\n';


    return 0;
}