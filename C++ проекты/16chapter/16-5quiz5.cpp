#include <iostream>
#include <cassert>
#include <vector>
#include <string_view>


using Index = std::size_t;

void fizzBuzz(int count)
{
    const std::vector numbers {3, 5, 7, 11, 13, 17, 19};
    const std::vector<std::string_view> strings { "fizz", "buzz", "pop", "bang", "jazz", "pow", "boom" };
    
    assert(numbers.size() == strings.size() && "Arrays length are not equals");

    for (int index{ 1 }; index <= count; ++index)
    {
        bool printed{ false };
        for (Index numb{}; numb < numbers.size(); ++numb)
        {
            if (index % numbers[numb] == 0)
            {
                std::cout << strings[numb];
                printed = true;
            }
        }

        if (!printed)
        {
           std::cout << index;
        }
        std::cout << '\n';
    }
}


int main()
{    
    fizzBuzz(150);

    return 0;
}