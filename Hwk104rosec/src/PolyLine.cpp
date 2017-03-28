#include "PolyLine.h"
#include <cmath>

PolyLine::PolyLine(int col) : color{col}
{
}

PolyLine::PolyLine(std::initializer_list<Vec2d> pts, int col)
 : color{col}
{
    for (auto p : pts)
    {
        points.push_back(p);
    }
}

PolyLine::PolyLine(const Vec2d &p1, const Vec2d &p2, int col)
  : color{col}
{
    points.push_back(p1);
    points.push_back(p2);
}


void PolyLine::draw()
{
    Vec2d prev;
    bool gotPrev = false;
    for (auto p : points)
    {
        if (!gotPrev)
        {
            gotPrev = true;
        }
        else
        {
            drawLine(prev, p, color);
        }
        prev = p;
    }
}

void PolyLine::draw(const Vec2d &offset, double scale, double angle)
{
    Vec2d prev;
    bool gotPrev = false;
    for (auto p : points)
    {
        if (scale != 1.0)
        {
            p *= scale;
        }

        if (angle != 0)
        {
            p = p.rotated(angle);
        }

        p += offset;

        if (!gotPrev)
        {
            gotPrev = true;
        }
        else
        {
            drawLine(prev, p, color);
        }

        prev = p;
    }
}

PolyLine PolyLine::createRect(const Vec2d &corner, double width, double height, int color)
{
    PolyLine p(color);

    p.add(corner);
    p.add(corner + Vec2d{width, 0});
    p.add(corner + Vec2d{width, height});
    p.add(corner + Vec2d{0,height});

    return p;
}

PolyLine PolyLine::createEllipse(const Vec2d &center, double width, double height, int numpts, int color)
{
    PolyLine p(color);

    for (int i=0;i<=numpts;++i)
    {
        double angle = i*3.1415927*2.0/numpts;
        Vec2d offset{sin(angle)*width/2, cos(angle)*height/2};
        p.add(center + offset);
    }

    return p;
}
