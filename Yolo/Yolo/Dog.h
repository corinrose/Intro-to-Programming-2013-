//
//  Dog.h
//  Yolo
//
//  Created by Corin Rose on 2/3/14.
//  Copyright (c) 2014 RCubed. All rights reserved.
//

#ifndef __Yolo__Dog__
#define __Yolo__Dog__

#include <iostream>
#include "Animal.h"

class Dog : public Animal
{
  private:
    unsigned int furColour;
  public:
    Dog(unsigned int f, int s);
    virtual void makeNoise() override;
};

#endif /* defined(__Yolo__Dog__) */
