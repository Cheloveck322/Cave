#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
int findMax(std::vector<T>& arr)
{
    if (arr.size() <= 0)
        return 0;
    
    int max { arr[0] };
    arr.erase(arr.begin());
    return std::max(max, findMax(arr));
}

int main()
{
    std::vector<int> arr { 1, 2, 9, 1989, 4, 1, 0, -123, 98, 3 };
    
    std::cout << findMax(arr) << '\n';

    return 0;
}