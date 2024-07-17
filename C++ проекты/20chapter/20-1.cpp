#include <iostream>
#include <limits>
#include <functional>

using ArithmeticFunction = std::function<int(int, int)>;

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getInt()
{
    while(true)
    {
        std::cout << "Enter an int number: ";
        int number{};

        std::cin >> number;

        if (!std::cin)
        {
            std::cin.clear();
            ignoreLine();

            std::cout << "That's invalid input.\n";
        }
        else 
        {
            ignoreLine();
            return number;
        }
    }
}

char getOperation()
{
    while (true)
    {
        std::cout << "Enter an operation (+, -, *, /): ";
        char operation{};
        std::cin >> operation;

        if (!std::cin)
        {
            std::cin.clear();
        }

        ignoreLine();

        switch (operation)
        {
        case '+':
        case '-':
        case '*':
        case '/':
            return operation;    
        default:
            std::cout << "That's invalid input.\n";
        }
    }
}

int add(int x, int y)
{
    return x + y;
}

int subtract(int x, int y)
{
    return x - y;
}

int multiply(int x, int y)
{
    return x * y;
}

int divide(int x, int y)
{
    return x / y;
}

ArithmeticFunction getArithmeticFunction(char operation)
{
    switch (operation)
    {
    case '+':   return &add;
    case '-':   return &subtract;
    case '*':   return &multiply;
    case '/':   return &divide;
    }

    return nullptr;
}

int main()
{
    int x { getInt() };
    char operation { getOperation() };
    int y { getInt() };

    auto result { getArithmeticFunction(operation) };

    if (result)
    {
        std::cout << x << ' ' << operation << ' ' << y << " = " << result(x, y) << '\n';
    }

    return 0;
}