#include <iostream>
#include <vector>
#include <algorithm>

int findMaxK(std::vector<int>& nums)
{
    auto max { std::max_element(nums.begin(), nums.end()) };
    if (*max < 1 || nums.size() < 2)
        return -1;

    auto thereIsNegative { std::find_if(nums.begin(), nums.end(), [max](int a)
                            {
                                return (-(*max) == a);
                            }) };

    if (thereIsNegative == nums.end())
    {
        nums.erase(max);
        return findMaxK(nums);
    }
    return *max;
}

int main()
{
    std::vector<int> nums { 1, 2, 3, 4, 5, 6, 4, 1 };

    std::cout << findMaxK(nums);

    return 0;
}