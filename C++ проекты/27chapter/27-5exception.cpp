#include <cstddef>
#include <exception>
#include <limits>
#include <string>
#include <iostream>

int main()
{
    try
    {
        std::string s;
        s.resize(std::numeric_limits<std::size_t>::max());
    }
    catch(const std::exception& e)
    {
        std::cerr << "Standart exception: "<< e.what() << '\n';
    }
    

    return 0;
}