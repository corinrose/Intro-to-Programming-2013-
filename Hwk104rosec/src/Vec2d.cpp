#include <cmath>
#include "Vec2d.h"
#include "glHelper.h"

Vec2d::Vec2d(double xval, double yval)
: x{xval}, y{yval}
{
}

Vec2d &Vec2d::operator= (const Vec2d &v)
{
    x = v.x;
    y = v.y;
    return *this;
}


Vec2d &Vec2d::operator+= (const Vec2d &v)
{
    x += v.x;
    y += v.y;
    return *this;
}

Vec2d &Vec2d::operator-= (const Vec2d &v)
{
    x -= v.x;
    y -= v.y;
    return *this;
}

Vec2d &Vec2d::operator*= (double s)
{
    x *= s;
    y *= s;
    return *this;
}

double Vec2d::mag()
{
    return sqrt(x*x + y*y);
}

Vec2d operator+(Vec2d v1, const Vec2d &v2)
{
    return v1 += v2;
}

Vec2d operator-(Vec2d v1, const Vec2d &v2)
{
    return v1 -= v2;
}

Vec2d operator*(Vec2d v, double s)
{
    return v *= s;
}

Vec2d operator*(double s, Vec2d v)
{
    return v *= s;
}

Vec2d Vec2d::rotated(double angle) // returns a rotated version
{
    return Vec2d{x*cos(angle)-y*sin(angle), x*sin(angle)+y*cos(angle)};
}

void drawLine(const Vec2d &p1, const Vec2d &p2, int color)
{
    drawLine(p1.x, p1.y, p2.x, p2.y, color);
}
