#include <iostream>
#include <vector>
#include <limits>

template<typename T>
void printArray(const std::vector<T>& v)
{
    bool comma { false };
    std::cout << "With array ( ";

    for (const auto& element : v)
    {
        if (comma)
        {
            std::cout << ", ";
            comma = false;
        }

        std::cout << element;
        comma = true;
    }
    
    std::cout << " ):\n";
}

template <typename T>
void findAndPrintMax(const std::vector<T>& v)
{
    std::pair<std::size_t, T> foundMax{ 0, v[0] };

    for (std::size_t index{ 0 }; index < v.size(); ++index)
    {
        if (v[index] > foundMax.second)
        {
            foundMax = std::make_pair(index, v[index]);
        }
    }

    std::cout << "The max element has index " << foundMax.first << " and value " << foundMax.second << '\n';
}

template <typename T>
void findAndPrintMin(const std::vector<T>& v)
{
    std::pair<std::size_t, T> foundMin{ 0, v[0] };

    for (std::size_t index{ 0 }; index < v.size(); ++index)
    {
        if (v[index] < foundMin.second)
        {
            foundMin = std::make_pair(index, v[index]);
        }
    }
    
    std::cout << "The min element has index " << foundMin.first << " and value " << foundMin.second << '\n';
}

int main()
{
    std::vector<int> arr{};

    std::cout << "Enter numbers to add (use -1 to stop): ";
    while (true)
    {
        int input{};
        
        std::cin >> input;
        if (input == -1)
            break;
        
        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        arr.push_back(input);
    }

    printArray(arr);
    findAndPrintMin(arr);
    findAndPrintMax(arr);

    return 0;
}