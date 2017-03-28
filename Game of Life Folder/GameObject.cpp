#include <iostream>
#include "GameObject.h"

GameObject::GameObject(int xVal, int yVal, char dispVal)
{
    x = xVal;
    y = yVal;

    disp = dispVal;
}

void GameObject::display(std::vector<std::vector<char> > &world)
{
    world[y - 1][x - 1] = disp;
}

void GameObject::moveObj(int mx, int my, std::vector<std::vector<char> > &world)
{
    world[y - 1][x - 1] = '-';

    x += mx;
    y += my;
}
