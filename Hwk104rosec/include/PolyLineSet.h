#ifndef POLYLINESET_H
#define POLYLINESET_H

#include "PolyLine.h"

class PolyLineSet
{
        std::vector<PolyLine> lines;
    public:
        PolyLineSet(std::initializer_list<PolyLine> lines);
        void add(const PolyLine &poly) { lines.push_back(poly); }
        void draw();
        void draw(const Vec2d &offset, double scale = 1.0, double angle = 0);
        void addLine(std::initializer_list<Vec2d> pts, int col = 0xFFFFFF);
        void addRect(const Vec2d &corner, double width, double height, int color);
        void addEllipse(const Vec2d &center, double width, double height, int numpts, int color);
};

#endif // POLYLINESET_H
