#ifndef UNICORN_H
#define UNICORN_H

#include "Animal.h"

class Unicorn : public Animal
{
    private:

    public:
        Unicorn(std::string nm);
        void attack();
};

#endif // UNICORN_H
