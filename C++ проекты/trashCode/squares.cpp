#include <iostream>
#include <limits>
#include <random>
#include <vector>
#include <algorithm>
#include <cmath>



void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


int getValue()
{
    while(true)
    {
        int value{};
        std::cin >> value;
        if (!std::cin)
        {
            std::cout << "You entered invalid value, try again\n";
            std::cin.clear();
            ignoreLine();
        }
        else
        {
            ignoreLine();
            return value;
        }
    }
}


void game(std::vector<int>& squares, int& count)
{
    for(int i{}; i < count;)
    {
        int search{getValue()};
        auto found{ std::find(squares.begin(), squares.end(), search)};

        auto closest{ std::min_element(squares.begin(), squares.end(), 
                                    [](int a, int b){
                                        return (a > b);
                                    })};
        
        if(found == squares.end())
        {
            if( std::abs(search - *closest) <= 4)
            {
            std::cout << search << " is wrong! Try " << *closest << " next time.\n";
            }
            else
            {
                std::cout << search << " is wrong!";
            }
            return; 
        }
        else
        {
            squares.erase(found);
            if (--count > 0)
            {
                std::cout << "Nice! " << count << " numbers left.\n";
            }
            else
            {
                std::cout << "Nice! You found all numbers, good job!\n";
            }
        }
    }
}


int main(int argc, char* argv[])
{   
    std::cout << "Start where? ";
    int startPoint{getValue()};

    std::cout << "How many? ";
    int count{getValue()};

    std::mt19937 mt{std::random_device{}()};   
    std::uniform_int_distribution val{2, 4};
    static int randomNumber{val(mt)};

    std::vector<int> squares{};
    
    auto fullFillVector{[&, number{startPoint}]() mutable
    {
        for(int i{1}; i <= count; ++i)
    {
        int square{number * number * randomNumber};
        squares.push_back(square);
        ++number;
    }
    }};
    fullFillVector();

    std::cout << "I generated " << count << " square numbers. Do you know each number is after multiplying it by " << randomNumber << "? \n";
    
    game(squares, count);

    return 0;
}
