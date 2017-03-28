#ifndef VEC2D_H
#define VEC2D_H

class Vec2d
{
    public:
        double x;
        double y;
    public:
        Vec2d() : x{}, y{} {}
        Vec2d(double xval, double yval);
        Vec2d(const Vec2d &v) : x{v.x}, y{v.y} {}
        Vec2d &operator= (const Vec2d &v);
        Vec2d &operator+= (const Vec2d &v);
        Vec2d &operator-= (const Vec2d &v);
        Vec2d &operator*= (double s);
        double mag();
        Vec2d rotated(double angle); // returns a rotated version
};

Vec2d operator+(Vec2d v1, const Vec2d &v2);
Vec2d operator-(Vec2d v1, const Vec2d &v2);
Vec2d operator*(Vec2d v, double s);
Vec2d operator*(double s, Vec2d v);

void drawLine(const Vec2d &p1, const Vec2d &p2, int color);

#endif // VEC2D_H
