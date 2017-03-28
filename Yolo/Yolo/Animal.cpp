//
//  Animal.cpp
//  Yolo
//
//  Created by Corin Rose on 2/3/14.
//  Copyright (c) 2014 RCubed. All rights reserved.
//

#include "Animal.h"

Animal::Animal(int s)
{
    size = s;
}

int Animal::returnSize()
{
    return size;
}

void Animal::makeNoise()
{
    std::cout << "noise!";
}