#include <iostream>
#include "Animal.h"

Animal::Animal(std::string nm)
{
    name = nm;
}

void Animal::attack()
{
    std::cout << "RAAWWWRRR" << std::endl;
}
