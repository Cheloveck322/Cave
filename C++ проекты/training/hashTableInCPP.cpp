#include <iostream>
#include <unordered_map>
#include <string>

int main()
{
    std::unordered_map<std::string, int> mymap;

    mymap["qwer"] = 4;
    mymap.insert(std::unordered_map<std::string, int>::value_type("rewq", 123));
    mymap["ba"] = 18;

    std::unordered_map<std::string, int>::const_iterator it{ mymap.begin() };
    for (; it != mymap.end(); ++it)
    {
        std::cout << it->first << ' ' << it->second << '\n';
    }
    auto bs { mymap.bucket("qwer") };
    std::cout << bs << '\n';
    bs = mymap.bucket("rewq");
    std::cout << bs << '\n';
    auto ba { mymap.bucket("ba") };
    std::cout << ba << '\n';
    std::cout << "at is equals to " << mymap.at("ba") << '\n';

    return 0;
}