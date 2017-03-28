#ifndef RECT2D_H
#define RECT2D_H

#include "Vec2d.h"

class Rect2d
{
    public:
        Vec2d  pos;
        double width;
        double height;
    public:
        Rect2d() : width{0}, height{0} {}
        Rect2d(double x, double y, double w, double h) : pos{x,y}, width{w}, height{h} {}
        bool contains(double x, double y);
};

#endif // RECT2D_H
