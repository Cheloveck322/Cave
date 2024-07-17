#include <iostream>
#include <vector>

template <typename T>
T findMax(const std::vector<T>& v)
{
    T max{};
    for (int index{}; index < static_cast<int>(v.size()); ++index)
    {
        if (max < v[static_cast<int>(index)])
            max = v[static_cast<int>(index)];
    }
    return max;
}


int main()
{
    std::vector testScore { 84, 92, 76, 81, 56 };
    std::cout << "The max score is: " << findMax(testScore) << '\n'; // prints 92

    return 0;
}