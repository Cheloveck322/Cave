#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>

template <typename T>
void print(const T& array)
{
    for (const auto& element : array)
    {
        std::cout << element << ' ';
    }
    std::cout << '\n';
}

std::list<std::string> shortWords(const std::vector<std::string>& words)
{
    int minLen { static_cast<int>(words[0].size()) };
    std::list<std::string> answer{};

    for (int i{}; i < words.size(); ++i) // finding shortest length of words
    {
        minLen = std::min(minLen, static_cast<int>(words[i].size()));
    }

    for (const auto& element : words) // finding shortest words
    {
        if (element.size() == minLen)
        {
            answer.emplace_back(element);
        }
    }
    return answer;
}

int leftWater(const std::vector<int>& height)
{
    int answer{};
    int maxPoint{};
    
    for (int i{}; i < height.size(); ++i) // finding peak
    {
        maxPoint = std::max(height[maxPoint], height[i]);
    }

    int currentMax{};
    for (int i{}; i < maxPoint; ++i)
    {
        currentMax = std::max(currentMax, height[i]);
        answer += currentMax - height[i];
    }

    currentMax = 0;
    for (int i { height.size() - 1 }; i > maxPoint; --i)
    {
        currentMax = std::max(currentMax, height[i]);
        answer += currentMax - height[i];
    }
    
    return answer;
}

int main()
{
    std::vector<std::string> words { "asdf", "sd", "43r", "angelika", "fruit", "cucumber", "choir", "colonel", "32", "bf" };

    auto wordsWithShortLen { shortWords(words) };

    print(wordsWithShortLen);

    return 0;
}