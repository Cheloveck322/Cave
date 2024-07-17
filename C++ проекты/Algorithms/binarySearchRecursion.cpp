#include <iostream>
#include <vector>
#include <cstddef>
#include <iterator>

template <typename T> 
T binarySearch(const std::vector<T>& arr, int min, int max, T find)
{    
    while (min <= max)
    {
        T middle { (min + max) / 2 };

        if (arr[middle] == find)
        {
            return middle;
        }

        if (arr[middle] < find)
        {
            return binarySearch(arr, middle + 1, max, find);
        }
        else 
        {
            return binarySearch(arr, min, middle - 1, find);
        }
    }
    
    return -1;
}

int main()
{
    std::vector<int> arr { 0, 89, -12, 5, 43, 1, -1, 3 };
    int finding { 8 };
    int begin { arr[0] };
    int end { static_cast<int>(arr.size() - 1) };

    std::cout << "Finding is located on index " << binarySearch(arr, begin, end, finding) << '\n';

    return 0;
}