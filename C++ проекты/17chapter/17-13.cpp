#include <iostream>
#include <array>

template<typename T, std::size_t Row, std::size_t Col>
using Array2d = std::array<std::array<T, Col>, Row>;

// When using Array2d as a function parameter, we need to respecify the template parameters
template<typename T, std::size_t Row, std::size_t Col>
void printArray(Array2d<T, Col, Row> array)
{
    for (const auto& aRow : array)
    {
        for (const auto& aCol : aRow)
        {
            std::cout << aCol << ' ';
        }
        std::cout << '\n';
    }
}

int main()
{
    Array2d<int, 3, 4> arr {{
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 }}};
    
    printArray(arr);

    std::cout << "Rows: " << arr.size() << '\n';
    std::cout << "Cols: " << arr[0].size() << '\n';

    return 0;
}