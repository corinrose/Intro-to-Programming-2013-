#ifndef SEGMENT_H
#define SEGMENT_H

#include "Vec2d.h"
#include "Shape.h"

class Segment
{
  public:
    Vec2d p1;
    Vec2d p2;
  public:
    Segment() {};
    Segment(const Vec2d &a, const Vec2d &b) : p1{a}, p2{b} {}
    Segment(double x1, double y1, double x2, double y2) : p1{x1, y1}, p2{x2, y2} {}
    void draw(int color);
    void draw(const Vec2d &offset, int color, double scale = 1.0, double angle = 0);
};

#endif // SEGMENT_H
