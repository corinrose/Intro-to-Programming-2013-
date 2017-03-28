#ifndef RECTSHAPE_H
#define RECTSHAPE_H

#include "shape.h"

class RectShape : public Shape
{
    public:
        double x1;
        double y1;
        double x2;
        double y2;
    public:
        RectShape();
        virtual ~RectShape();
        void draw();
};

#endif // RECTSHAPE_H
