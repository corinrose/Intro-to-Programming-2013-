#include <iostream>
#include "American.h"

American::American(std::string nm) : Animal(nm){ }

void American::attack()
{
    std::cout << "AAAAMMMEEERRRIIICCCAAAAA!!!!!!" << std::endl;
}
