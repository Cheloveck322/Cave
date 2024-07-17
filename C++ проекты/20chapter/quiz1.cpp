#include <iostream>

int main()
{
    int length{};
    std::cout << "Enter the length of an array: ";
    std::cin >> length;

    int* array { new int[length]{} };

    for (std::size_t i{}; i < 5; ++i)
    {
        array[i] = i;
        std::cout << array[i] << ' ';
    }
    std::cout << '\n';

    const auto max { [](const auto& a, const auto& b)
    {
        return (a > b ? a : b);
    }};
    
    int a { 2 };
    int b { 5 };

    const auto swap{ [](auto& a, auto& b)
    {
        auto c { b };
        b = a;
        a = c;
    }};

    auto getLargestElement{ [&](int* array, int length)
    {
        int largestElement{};
        int largestIndex{};
        for (std::size_t i{}; i < length; ++i)
        {
            if (largestElement < array[i])
            {
                largestElement = array[i];
                largestIndex = i;
            }
        }  
        return &array[largestIndex];
    }};

    std::cout << "2.5 is less then " << max(2.5, 51.3) << '\n';
    
    swap(a, b);

    std::cout << "Now a is " << a << " and b is " << b << '\n';

    std::cout << "Largest element in the array is " << *getLargestElement(array, length) << '\n';
    
    *getLargestElement(array, length) = 8;

    std::cout << "Now the largest element of the array is " << *getLargestElement(array, length) << '\n';

    delete[] array;

    return 0;
}