#include <string>
#include <iostream>



bool isValid(std::string s) {
    bool flag{ false };

    for (int index{ 0 }; index < s.length() - 1; ++index)
    {
        char par{s.at(index)};
        for (int sign{ index + 1 }; sign < s.length(); ++sign)
        {
            switch (par)
            {
                case '(':
                {
                    if (s.at(sign) == ')')
                        flag = true;
                    break;
                }
                case '[':
                {
                    if (s.at(sign) == ']')
                        flag = true;
                    break;
                }
                case '{':
                {
                    if (s.at(sign) == '}')
                        flag = true;
                    break;
                }
                
                default:
                {
                    break;
                }
            }
        }
    }
    return flag;
}

int main()
{
	std::cout << isValid("([{}])");

	return 0;
}