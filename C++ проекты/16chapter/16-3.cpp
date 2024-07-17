#include <vector>
#include <iostream>

int main()
{
    std::vector string{ 'h', 'e', 'l', 'l', 'o' };

    std::cout << "The array has " << std::size(string) << " elements." << '\n';

    std::cout << string[1] << string.at(1);


    return 0;
}