#include <iostream>
#include <vector>

void printStackValues(const std::vector<int>& v)
{
    std::cout << "\t(Stack:";

    for (auto& element : v)
        std::cout << ' ' << element;
    if (v.size() == 0)
        std::cout << " empty";
    std::cout << ")\n";
}

void pushAndPrint(std::vector<int>& v, int value)
{
    v.push_back(value);
    std::cout << "Push " << value;
    printStackValues(v);
}

void popAndPrind(std::vector<int>& v)
{
    v.pop_back();
    std::cout << "Pop "; 
    printStackValues(v);
}

int main()
{
    std::vector<int> v {};

    printStackValues(v);

    pushAndPrint(v, 1);
    pushAndPrint(v, 2);
    pushAndPrint(v, 3);
    popAndPrind(v);
    pushAndPrint(v, 4);
    popAndPrind(v);
    popAndPrind(v);
    popAndPrind(v);


    return 0;
}