#include <iostream>
#include <vector>


using Index = std::size_t;

template <typename T>
bool simmetric(const std::vector<T>& arr)
{
    bool flag{ false };
    for (int index{}; index < arr.size(); ++index)
    {
        for (int innerIndex{static_cast<int>(arr.size()) - 1}; innerIndex >= 0; --innerIndex)
        {
            if (arr[index] == arr[innerIndex])
                flag = true;
            else 
                flag = false;
        }
    }
    return flag;
}

template <typename T>
void numberAndWhich(std::vector<T>& arr)
{
    int marker{};
    int count{};
    if (!simmetric(arr))
    {
        for (int index {static_cast<int>(arr.size()) - 1}; index >= 0; --index)
        {
            for (int innerIndex{ marker }; innerIndex < index; ++innerIndex)
            {
                if (count >= static_cast<int>(arr.size()) - 1)
                    marker = innerIndex;
                else if (arr[index] != arr[innerIndex])
                {
                    std::cout << arr[innerIndex] << ' ';
                    ++count;
                }
                else 
                {
                    marker = innerIndex + 1;
                    break;
                }
            }
        }
        std::cout << '\n' << count;
    }
}

int main()
{
    std::vector array {53, 2, 34, 53, 53, 3, 1, 3, 53};

    numberAndWhich(array);

    return 0;
}