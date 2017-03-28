#include "Drawing.h"
#include "RectShape.h"
#include "Line.h"
#include <iostream>

using namespace std;

Drawing::Drawing()
{
    mode = 0;
}

Drawing::~Drawing()
{
    for (auto d : shapes)
    {
        delete d;
    }

    for (auto b : buttons)
    {
        delete b;
    }
}

void Drawing::initialize(int width, int height)
{
    for (int i=0;i<19;i++)
    {
        addButton(new Button(20,20+30*i,40,20, i));
    }
}

void Drawing::addButton(Button *button)
{
    buttons.push_back(button);
}

void Drawing::addShape(Shape *shape)
{
    shapes.push_back(shape);
}

void Drawing::draw(int width, int height)
{
    for (auto d : shapes)
    {
        d->draw();
    }

    for (auto b : buttons)
    {
        b->draw(mode);
    }
}

void Drawing::keyPress(int key, double mouseX, double mouseY)
{

}

void Drawing::keyRelease(int key, double mouseX, double mouseY)
{

}

void Drawing::mousePress(int button, double mouseX, double mouseY)
{
    // check to see if we hit a button

    bool hitButton = false;

    for (auto b : buttons)
    {
        if (b->isHit(mouseX, mouseY))
        {
            hitButton = true;
            this->mode = b->mode;
        }
    }

    if (!hitButton)
    {
        isPressed = true;
        switch (mode)
        {
        case 0:
            {
                Line *t = new Line(mouseX, mouseY, mouseX, mouseY);
                addShape(t);
            }
            break;
        case 1:
            {
               // get the first point
                RectShape *r = new RectShape();
                r->x1 = mouseX;
                r->y1 = mouseY;
                r->x2 = mouseX;
                r->y2 = mouseY;
                addShape(r);
            }
            break;
        default:
            break;
        }
    }
}

void Drawing::mouseRelease(int button, double mouseX, double mouseY)
{

    if (isPressed)
    {
        switch (mode)
        {
        case 0:
            {
                Line *line  = (Line*)shapes.back();
                line->p2.x = mouseX;
                line->p2.y = mouseY;
                isPressed = false;
            }
            break;
        case 1:
            {
                // get the last point
                RectShape *r = static_cast<RectShape*>(shapes.back());
                r->x2 = mouseX;
                r->y2 = mouseY;
                isPressed = false;
            }
            break;
        default:
            break;
        }
    }
}

void Drawing::mouseMove(double mouseX, double mouseY)
{
    if (isPressed)
    {
        switch (mode)
        {
        case 0:
            {
                Line *line  = (Line*)shapes.back();
                line->p2.x = mouseX;
                line->p2.y = mouseY;
            }
            break;
        case 1:
            {
                RectShape *r = static_cast<RectShape*>(shapes.back());
                r->x2 = mouseX;
                r->y2 = mouseY;
            }
            break;
        default:
            break;
        }
    }
}
