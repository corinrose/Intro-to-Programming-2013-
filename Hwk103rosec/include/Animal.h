#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal
{
    protected:
        std::string name;
    public:
        Animal(std::string nm);
        virtual void attack();
};

#endif // ANIMAL_H
