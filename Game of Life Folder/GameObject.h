#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>

class GameObject
{
    public:
        GameObject(int xVal, int yVal, char dispVal);

        void display(std::vector<std::vector<char> > &world);
        void moveObj(int mx, int my, std::vector<std::vector<char> > &world);
    protected:
        int x;
        int y;
        char disp;
};

#endif // GAMEOBJECT_H
