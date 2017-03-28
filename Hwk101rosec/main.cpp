#include "glHelper.h"
#include <iostream>
#include <string>
#include "pixels.h"

using namespace std;

struct Vertex
{
    double x;
    double y;
};

int width = 1000;
int height = 700;

Vertex a;
Vertex b;
Vertex c;

int main(void)
{
    a.x = width/2;
    a.y = 50;

    b.x = 50;
    b.y = height - 50;

    c.x = width - 50;
    c.y = height - 50;

    startOpenGl(width,height, "Blarg With Pixels");
}

void keyCallback(int key, int action)
{
    //std::cout << key << " " << action << endl;
}

void mouseButtonCallback(int button, int action)
{
    //std::cout << button << " " << action << endl;
}

void mouseMoveCallback(double x, double y)
{
    //std::cout << x << " " << y << endl;
}

void initialize(int width, int height)
{
   setupPixels(width,height);
}

void drawTriangle(Vertex a, Vertex b, Vertex c, int colour)
{
     drawLine(a.x, a.y, b.x, b.y, colour);
     drawLine(b.x, b.y, c.x, c.y, colour);
     drawLine(c.x, c.y, a.x, a.y, colour);
}

int avgPtsX(Vertex a, Vertex b)
{
    return (a.x + b.x)/2;
}

int avgPtsY(Vertex a, Vertex b)
{
    return (a.y + b.y)/2;
}

void drawSerp(Vertex a, Vertex b, Vertex c, int colour, int iterations)
{

    drawTriangle(a, b, c, colour);

    Vertex midAB;
    midAB.x = avgPtsX(a,b);
    midAB.y = avgPtsY(a,b);

    Vertex midBC;
    midBC.x = avgPtsX(b,c);
    midBC.y = avgPtsY(b,c);

    Vertex midAC;
    midAC.x = avgPtsX(a,c);
    midAC.y = avgPtsY(a,c);

    iterations--;

    if (iterations <= 0)
    {
        return;
    }

    drawSerp(midAB, b, midBC, colour, iterations);

    drawSerp(a, midAB, midAC, colour, iterations);

    drawSerp(midAC, midBC, c, colour, iterations);

}

void zoomTriangle(Vertex &a, Vertex &b, Vertex &c, int speed)
{
    a.x;
    a.y -= speed;

    b.x -= speed*1.5;
    b.y += speed;

    c.x += speed*1.5;
    c.y += speed;
}

void displayLoop(int width, int height)
{
    int detail = 11;

    //zoomTriangle(a, b, c, 10);

    drawSerp(a, b, c, rgb(150,0,150), detail);
}

