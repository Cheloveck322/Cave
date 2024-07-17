#include <iostream>
#include <array>

template <typename T, std::size_t N>
void printArray(const std::array<T, N> &arr)
{
    bool first { true };

    std::cout << "The array (";

    for (auto& ch : arr)
    {
        std::cout << (first ? "" : ", ");
        std::cout << ch;
        first = false;
    }

    std::cout << ") has length " << N << '\n';
}

int main()
{
    constexpr std::array arr1 { 1, 4, 9, 16 };
    printArray(arr1);

    constexpr std::array arr2 { 'h', 'e', 'l', 'l', 'o' };
    printArray(arr2);

    return 0;
}