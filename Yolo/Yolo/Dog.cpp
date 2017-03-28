//
//  Dog.cpp
//  Yolo
//
//  Created by Corin Rose on 2/3/14.
//  Copyright (c) 2014 RCubed. All rights reserved.
//

#include "Dog.h"

Dog::Dog(unsigned int f, int s) : Animal(s)
{
    furColour = f;
}

void Dog::makeNoise()
{
    std::cout << "BARK";
}