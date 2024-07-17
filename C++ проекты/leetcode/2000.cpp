#include <iostream>
#include <algorithm>
#include <string>

std::string reversePrefix(std::string word, char ch) 
{
    for (int i{}; i < word.size(); ++i)
    {
        if (word[i] == ch)
        {
            std::reverse(word.begin(), word.begin() + i + 1); //the last one not inclusive
            break;
        }
    }
    return word;
}

int main()
{
    std::string str{ "abcdefd" };
    std::cout << "before reverse: " << str << '\n';
    std::cout << "after reverse: " << reversePrefix(str, 'd') << '\n';


    return 0;
}