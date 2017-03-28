#include "glHelper.h"
#include <iostream>
#include <string>
#include "PolyLine.h"
#include "Font.h"
#include "drawing.h"

using namespace std;

Drawing drawing;

int main(void)
{
    startOpenGl(600,600, "Drawing Thing");
}

double mouseX;
double mouseY;

void keyCallback(int key, int action)
{
    if (action == KEY_PRESS)
    {
        drawing.keyPress(key, mouseX, mouseY);
    }
    else
    {
        drawing.keyRelease(key, mouseX, mouseY);
    }
}

void mouseButtonCallback(int button, int action)
{
    if (action == KEY_PRESS)
    {
        drawing.mousePress(button, mouseX, mouseY);
    }
    else
    {
        drawing.mouseRelease(button, mouseX, mouseY);
    }
}

void mouseMoveCallback(double x, double y)
{
    mouseX = x;
    mouseY = y;
    drawing.mouseMove(x,y);
}

void initialize(int width, int height)
{
    drawing.initialize(width, height);
}

void displayLoop(int width, int height)
{
    drawing.draw(width, height);
}

