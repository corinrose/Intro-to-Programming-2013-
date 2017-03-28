#ifndef POLYLINE_H
#define POLYLINE_H

#include <vector>
#include "Vec2d.h"

class PolyLine
{
    public:
        int                color;
        std::vector<Vec2d> points;
    public:
        PolyLine(int color = 0xFFFFFF);
        PolyLine(std::initializer_list<Vec2d> s, int color = 0xFFFFFF);
        PolyLine(const Vec2d &p1, const Vec2d &p2, int color = 0xFFFFFF);
        void add(const Vec2d &p) { points.push_back(p); }
        void draw();
        void draw(const Vec2d &offset, double scale = 1.0, double angle = 0);
        static PolyLine createRect(const Vec2d &corner, double width, double height, int color);
        static PolyLine createEllipse(const Vec2d &center, double width, double height, int numpts, int color);
};

#endif // POLYLINE_H
