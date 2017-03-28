//
//  Animal.h
//  Yolo
//
//  Created by Corin Rose on 2/3/14.
//  Copyright (c) 2014 RCubed. All rights reserved.
//

#ifndef __Yolo__Animal__
#define __Yolo__Animal__

#include <iostream>

class Animal
{
  private:
    int size;    
  public:
    Animal(int s);
    int returnSize();
    virtual void makeNoise();
};

#endif /* defined(__Yolo__Animal__) */
