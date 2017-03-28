#include "Button.h"
#include "glHelper.h"

Button::Button(double x, double y, double w, double h, int m)
  : location(x, y, w, h)
{
    mode = m;
}

Button::~Button()
{
    //dtor
}

void Button::draw(int currentMode)
{
    if (mode == currentMode)
    {
        fillRect(location.pos.x, location.pos.y, location.width, location.height, 0xFF00FF);
    }
    else
    {
        drawRect(location.pos.x, location.pos.y, location.width, location.height, 0xFF00FF);
    }
}

bool Button::isHit(double x, double y)
{
    return location.contains(x,y);
}
