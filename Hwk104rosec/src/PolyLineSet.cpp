#include "PolyLineSet.h"

PolyLineSet::PolyLineSet(std::initializer_list<PolyLine> lns)
{
    for (auto l : lns)
    {
        lines.push_back(l);
    }
}

void PolyLineSet::draw()
{
    for (auto pl : lines)
    {
        pl.draw();
    }
}


void PolyLineSet::draw(const Vec2d &offset, double scale, double angle)
{
    for (auto pl : lines)
    {
        pl.draw(offset, scale, angle);
    }
}

void PolyLineSet::addLine(std::initializer_list<Vec2d> pts, int col)
{
    lines.push_back(PolyLine{pts, col});
}

void PolyLineSet::addRect(const Vec2d &corner, double width, double height, int color)
{
    lines.push_back(PolyLine::createRect(corner, width, height, color));
}

void PolyLineSet::addEllipse(const Vec2d &center, double width, double height, int numpts, int color)
{
    lines.push_back(PolyLine::createEllipse(center, width, height, numpts, color));
}

