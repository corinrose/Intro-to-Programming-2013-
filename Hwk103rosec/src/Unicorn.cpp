#include <iostream>
#include "Unicorn.h"

Unicorn::Unicorn(std::string nm) : Animal(nm) { };

void Unicorn::attack()
{
    std::cout << "FWOOOOSH!" << std::endl;
}
