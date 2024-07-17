#include <iostream>
#include <vector>
#include <algorithm>

int maxArea(std::vector<int>& height) 
{
    auto first { std::max_element(height.begin(), height.begin() + height.size() / 4) };
    auto second { std::max_element(height.begin() + height.size() / 4 * 3, height.end()) };
    int firstIndex { static_cast<int>(std::distance(height.begin(), first)) };
    int secondIndex { static_cast<int>(std::distance(height.begin(), second)) };
    int length { secondIndex - firstIndex };
    int area {};
    while (second != height.end())
    {
        area = std::max(area, length * std::min(*first, *second));
        second = std::next(second);
        secondIndex = static_cast<int>(std::distance(height.begin(), second));
        length = secondIndex - firstIndex;
    }
    return area;
}

int main()
{
    std::vector<int> height { 1,8,6,2,5,4,8,3,7 };
    
    std::cout << maxArea(height) << '\n';

    return 0;
}