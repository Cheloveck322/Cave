#include <iostream>
#include "Random.h"
#include <limits>
#include <algorithm>
#include <cmath>

using Numbers = std::vector<int>;

namespace config
{
    constexpr int multiplierMin { 2 };
    constexpr int multiplierMax { 4 };
    constexpr int maximumWrongAnswer { 4 };
}

int getRandomInt(int min, int max)
{
    return Random::get(min, max);
}

Numbers generateNumbers(int start, int count, int multiplier)
{
    Numbers numbers(static_cast<Numbers::size_type>(count));

    int i { start };

    for (auto& number: numbers)
    {
        number = ((i * i) * multiplier);
        ++i;
    }

    return numbers;
}

Numbers generateUserNumbers(int multiplier)
{
    int start{};
    int count{};

    std::cout << "Start where? ";
    std::cin >> start;

    std::cout << "How many? "; 
    std::cin >> count;

    return generateNumbers(start, count, multiplier);
}

int getUserGuess()
{
    int guess{};

    std::cout << "> ";
    std::cin >> guess;

    return guess;
}

bool findAndRemove(Numbers& numbers, int guess)
{
    auto found { std::find(numbers.begin(), numbers.end(), guess) };

    if (found == std::end(numbers))
    {
        return false;
    }
    else 
    {
        numbers.erase(found);
        return true;
    }
}

int findClosestNumber(const Numbers& numbers, int guess)
{
    return *std::min_element(numbers.begin(), numbers.end(), [=](const auto& a, const auto& b)
            {
                return std::abs(guess - a) < std::abs(guess - b);
            });
}

void printTask(Numbers::size_type count, int multiplier)
{
    std::cout << "I generated " << count << " square numbers. Do you know what each number is after multiplying it by " << multiplier << "?\n";
}

void printSucces(Numbers::size_type numbersLeft)
{
    std::cout << "Nice! ";

    if ( numbersLeft == 0)
    {
        std::cout << "You found all numbers, good job!\n";
    }
    else 
    {
        std::cout << numbersLeft << " number(s) left.\n";
    }
}

void printFailure(const Numbers& numbers, int guess)
{
    int closest { findClosestNumber(numbers, guess) };

    std::cout << guess << " is wrong!";

    if (std::abs(closest - guess) <= config::maximumWrongAnswer)
    {
        std::cout << "Try " << closest << " next time\n";
    }
    else 
    {
        std::cout << '\n';
    }
}

bool playRound(Numbers& numbers)
{
    int guess { getUserGuess() };

    if ( findAndRemove(numbers, guess) )
    {
        printSucces(std::size(numbers));

        return !numbers.empty();
    }
    else 
    {
        printFailure(numbers, guess);
        return false;
    }
}

int main()
{
    int multiplier { getRandomInt(config::multiplierMin, config::multiplierMax) };
    Numbers numbers { generateUserNumbers(multiplier) };

    printTask(std::size(numbers), multiplier);

    while (playRound(numbers));

    return 0;
}