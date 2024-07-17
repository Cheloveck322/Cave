#include <iostream>
#include <vector>
#include <cassert>


namespace Animal
{
    enum Name
    {
        chicken,
        dog,
        cat, 
        elephant,
        duck,
        snake,
        max_animals,
    };

    std::vector legs{2, 4, 4, 4, 2, 0};
}

int main()
{
    assert(Animal::legs.size() == Animal::max_animals);

    std::cout << "An elephant has "<< Animal::legs[Animal::elephant] << " legs.\n";

    return 0;
}