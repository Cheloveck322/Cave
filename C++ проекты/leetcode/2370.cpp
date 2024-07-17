#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>


int longestIdealString(std::string s, int k) 
{
    if (s.size() <= 0)
        return 0;

    std::string sCopy{ s };
    int save{ 1 };
    std::string t{ s[0] };

    for (int i{}; i < t.size(); ++i)
    {
        for (int j{ save }; j < sCopy.size(); ++j)
        {
            if (std::abs(t[i] - sCopy[j]) <= k)
            {
                t += s[j];
                sCopy.erase(s.begin() + j);
                save = j;
                break;
            }
        }
    }
    s.erase(s.begin());
    return std::max(static_cast<int>(t.size()), longestIdealString(s, k));
}

int main()
{
    std::cout << longestIdealString("eduktdb", 15) << '\n';
    std::cout << 't' - 'k' << '\n';

    return 0;
}