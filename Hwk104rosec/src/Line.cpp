#include "Line.h"
#include "glHelper.h"

Line::Line(double x, double y, double x2, double y2)
{
    p1.x = x;
    p1.y = y;
    p2.x = x2;
    p2.y = y2;
}

void Line::draw()
{
    drawLine(p1.x, p1.y, p2.x, p2.y, 0xffffff);
}
