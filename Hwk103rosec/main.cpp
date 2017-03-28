#include <vector>
#include <iostream>
#include "Animal.h"
#include "Unicorn.h"
#include "American.h"

using namespace std;

void func(int sz)
{
    vector<Animal*> things;

    for (int i = 0; i < sz; i += 3)
    {

        things.push_back(new Animal  ("Francis"   )); //animal says rawr
        things.push_back(new Unicorn ("Deborah"   )); //unicorn says fwoosh
        things.push_back(new American("GeorgeBush")); //american says AMERICA!
    }

    for (int i = 0; i < things.size(); i++)
    {
        things[i]->attack();
        delete things[i];
    }
}

int main()
{
    func(10);
}
