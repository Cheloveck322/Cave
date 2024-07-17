#include <fstream>
#include <iostream>
#include <string>

int main()
{
    std::fstream iofile { "Sample.txt", std::ios::in | std::ios::out };

    if (!iofile)
    {
        std::cerr << "Uh oh, Sample.txt could not be opened!\n";
        return 1;
    }

    char chChar {};

    while (iofile.get(chChar))
    {

        switch (chChar)
        {
        case 'a':
        case 'i':
            iofile.seekg(-1, std::ios::cur);
            iofile << '#';
            iofile.seekg(iofile.tellg(), std::ios::beg);
        default:
            std::cout << chChar;
        }
        
    }
    
    return 0;
}