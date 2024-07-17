#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>

std::unordered_set<int> wordInDictionary(const std::unordered_set<std::string>& dictionary, const std::string& text)
{
    std::unordered_set<std::string> goodWords { dictionary };
    for (auto word : dictionary)
    {
        for (int index {}; index < word.size(); ++index)
        {
            goodWords.insert(word.erase(0, index) + word.erase(index, word.size()));
        }
    }
}

int main()
{
    return 0;
}