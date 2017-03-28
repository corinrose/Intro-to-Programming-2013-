#ifndef AMERICAN_H
#define AMERICAN_H

#include "Animal.h"

class American : public Animal
{
    public:
        American(std::string nm);
        void attack();
};

#endif // AMERICAN_H
