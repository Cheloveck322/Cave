#include <iostream>
#include <vector>

int main()
{
    std::vector evenNumbers{ 2, 4, 6, 8, 10, 12};

    const std::vector d { 1.2, 3.4, 5.6, 7.8};

    using namespace std::literals::string_view_literals;
    const std::vector names{ "Alex"sv, "Brad"sv, "Charles"sv, "Dave"sv };

    std::vector single{ 12 };

    std::vector<int> twelve(12);

    return 0;
}