#include "RectShape.h"
#include "Drawing.h"

RectShape::RectShape()
{
}

RectShape::~RectShape()
{
}

void RectShape::draw()
{
    drawRect(x1, y1, x2-x1, y2-y1, 0xFFFFFF);
}
