#include <iostream>
#include <string>
#include <array>
#include <algorithm>

struct Student
{
    std::string name{};
    int point{};
};

int main()
{
    std::array<Student, 8> arr{{
        { "Albert", 3 },
        { "Ben", 5 },
        { "Christine", 2 },
        { "Dan", 8 },
        { "Enchilada", 4 },
        { "Francis", 1 },
        { "Greg", 3 }, 
        { "Hagrid", 5 }
    }};

    const auto student { std::max_element(arr.begin(), arr.end(), 
                    [](const auto& a, const auto& b)
                    {
                        return a.point < b.point;
                    }) };

    std::cout << student -> name << " is the best student\n";

    return 0;
}