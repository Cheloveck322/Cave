#include <iostream>
#include <vector>

template<typename T>
int countNumber(std::vector<T>& arr)
{
    if (arr.size() <= 0)
        return 0;
    
    int count { 0 };
    arr.erase(arr.begin());
    return ++count + countNumber(arr);
}

int main()
{
    std::vector<int> arr { 1 };

    std::cout << countNumber(arr) << '\n';

    return 0;
}