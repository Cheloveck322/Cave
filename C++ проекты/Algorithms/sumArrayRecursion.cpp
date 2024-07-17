#include <iostream>
#include <cstddef>
#include <vector>

template <typename T>
T sumArray(std::vector<T>& arr)
{
    if (arr.size() <= 0)
        return 0;

    int result { arr[0] };
    arr.erase(arr.begin());
    return { result + sumArray(arr) };
}

int main()
{
    std::vector<int> arr{ 5, 5, 5, 5, 5, 5 };
    std::cout << sumArray(arr) << '\n';

    return 0;
}