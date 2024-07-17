#include <iostream>
#include <algorithm>

template <typename T>
void quickSort(T* array, int low, int high)
{
    int i { low };
    int j { high };
    T pivot { array[(i + j) / 2] };

    while(i <= j)
    {
        while(array[i] < pivot)
            ++i;
        while(array[j] > pivot)
            --j;
        if (i <= j)
        {
            std::swap(array[i], array[j]);
            ++i;
            --j;
        }
    }   

    if (j > low)
        quickSort(array, low, j);
    if (i < high)
        quickSort(array, i, high);
}

int main()
{
    int array[] { 3, 98, 123, -1, 4, 0, 541, -12, 4, -54, 12 };
    int low { 0 };
    int high { sizeof(array)/sizeof(array[0]) };

    std::cout << "Before sort: ";
    for (int element: array)
        std::cout << element << ' ';
    std::cout << '\n';

    quickSort(array, low, high);

    std::cout << "After sort: ";
    for (int element: array)
        std::cout << element << ' ';
    std::cout << '\n';

    return 0;
}