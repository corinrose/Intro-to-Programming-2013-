#ifndef LINE_H
#define LINE_H

#include "Shape.h"
#include "Vec2d.h"

class Line : public Shape
{
    public:
       Vec2d p1;
       Vec2d p2;
    public:
        Line(double x, double y, double x2, double y2);

        void draw();
};

#endif // LINE_H
