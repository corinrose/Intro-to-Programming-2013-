//
//  main.cpp
//  Yolo
//
//  Created by Corin Rose on 2/2/14.
//  Copyright (c) 2014 RCubed. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Animal.h"
#include "Dog.h"

using namespace std;

int main()
{
    vector<Animal*> animals;
    
    for (int i = 1; i < 11; i++)
    {
        if (i%2 == 0)
        {
            Animal* i = new Animal(5);
            animals.push_back(i);
        }
        else
        {
            Animal* i = new Dog(5, 5);
            animals.push_back(i);
        }
    }
    
    for (auto i : animals)
    {
        i->makeNoise();
        cout << endl;
    }
}

