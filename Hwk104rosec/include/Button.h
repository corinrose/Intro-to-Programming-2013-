#ifndef BUTTON_H
#define BUTTON_H

#include "Rect2d.h"

class Button
{
  public:
    int    mode;
    Rect2d location;
  public:
    Button(double x, double y, double w, double h, int mode);
    virtual ~Button();
    virtual void draw(int currentMode);
    bool isHit(double x, double y);
};

#endif // BUTTON_H
