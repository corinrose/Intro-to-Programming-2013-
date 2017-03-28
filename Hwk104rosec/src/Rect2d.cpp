#include "Rect2d.h"

bool Rect2d::contains(double x, double y)
{
    return x >= pos.x && y >= pos.y && x <= (pos.x + width) && y <= (pos.y + height);
}
