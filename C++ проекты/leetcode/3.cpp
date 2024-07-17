#include <iostream>
#include <string>
#include <string_view>

int lengthOfLongestSubstring(std::string_view s) {
        int length{};
        std::string subString{ };
        length = subString.size();
        if (s.size() < 1)
            return 0;
        if (s.size() == 1)
            return 1;
        bool flag { false };
        for (int index{}; index < s.size() - 1; ++index)
        {
            subString += s[index];
            for (int j{}; j < subString.size(); ++j)
            {
                if (subString[j] == s[index + 1])
                {
                    length = std::max(length, static_cast<int>(subString.size()));
                    subString = "";
                    flag = true;
                    break;
                }
            }   
            std::cout << subString << '\n';
        }
        if (!flag)
        {
            length = s.size();
        }
        return length;
    }

int main()
{
    std::cout << lengthOfLongestSubstring("abcalbcbb") << '\n';

    return 0;
}