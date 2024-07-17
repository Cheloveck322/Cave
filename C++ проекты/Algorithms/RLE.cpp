#include <iostream>
#include <string>

void pack(std::string& str, char lastSymbol, int count)
{
    str.push_back(lastSymbol);
    if (count > 1)
    {
        str.append(std::to_string(count));
    }
}

std::string RLE(std::string& str)
{
    std::string ans{};
    auto lastSymbol { str[0] };
    int lastPos{};

    for (int i { 0 }; i < str.size(); ++i)
    { 
        if (str[i] != lastSymbol)
        {
            pack(ans, lastSymbol, i - lastPos);
            lastSymbol = str[i];
            lastPos = i;
        }
    }

    pack(ans, lastSymbol, str.size() - lastPos);
    
    return ans;
}

int main()
{
    std::string str { "AAAABBBCCXYZDDDDEEEEFFFAAAAAABBBBBBBBBBBBBBBBBBBBBCC" };

    auto newStr { RLE(str) };

    for (auto ch : newStr)
    {
        std::cout << ch;
    }
    std::cout << '\n';

    return 0;
}