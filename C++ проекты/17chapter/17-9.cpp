#include <iostream>

template<typename T>
void printString(const T arr[])
{
    while ( *arr != '\0' )
    {
        std::cout << *arr;
        ++arr;
    }
    
    std::cout << '\n';
    return;
}

template<typename T>
void printStringBackward(const T arr[])
{
    const T* save { arr };
    while ( *arr != '\0' )
    {
        ++arr;
    }

    while ( arr-- != save)
    {
        std::cout << *arr;
    }

    std::cout << '\n';
    return;
}

int main()
{
    constexpr char arr[] { "Hello world!" };

    printString(arr);
    printStringBackward(arr);

    return 0;
}