#include "Segment.h"

void Segment::draw(int color)
{
    drawLine(p1, p2, color);
}

void Segment::draw(const Vec2d &offset, int color, double scale, double angle)
{
    Vec2d ps1 = p1;
    Vec2d ps2 = p2;

    if (scale != 1.0)
    {
        ps1 *= scale;
        ps2 *= scale;
    }

    if (angle != 0)
    {
        ps1 = ps1.rotated(angle);
        ps2 = ps2.rotated(angle);
    }

    ps1 += offset;
    ps2 += offset;

    drawLine(ps1, ps2, color);
}
