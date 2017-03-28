#include "glHelper.h"
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

struct Vertex
{
    double x;
    double y;
};

struct Segment
{
    Vertex v1;
    Vertex v2;
};

Segment personDrawing[] =
{
    { { 0, -3 }, { 1, -2 } },
    { { 0, -3 }, {-1, -2 } },
    { {-1, -2 }, { 0, -1 } },
    { { 1, -2 }, { 0, -1 } },
    { { 0, -1 }, { 0,  1 } },
    { { 0,  0 }, {-1, -1 } },
    { { 0,  0 }, { 1, -1 } },
    { { 0,  1 }, {-1,  2 } },
    { { 0,  1 }, { 1,  2 } },
};

Segment shipDrawing[] =
{
    { { 0, 0 }, {-1, 2 } },
    { { 0, 0 }, { 1, 2 } },
    { { 0, 1 }, {-1, 3 } },
    { { 0, 1 }, { 1, 3 } },
    { { 1, 3 }, { 1, 2 } },
    { {-1, 3 }, {-1, 2 } },
};

Segment bulletDrawing[] =
{
    { { 0, 0 }, {-1,  2 } },
    { { 0, 0 }, { 1,  2 } },
    { { 0, 4 }, {-1,  2 } },
    { { 0, 4 }, { 1,  2 } },
};

Segment particles[] =
{
    { {-1, -1 },  {-3, -3 } },
    { { 1, -1 },  { 3, -3 } },
    { {-1,  1 },  {-3,  3 } },
    { { 1,  1 },  { 3,  3 } },
};

struct GameObject
{
    double x;
    double y;
    double vx;
    double vy;
};

GameObject createObject(double x, double y, double vx, double vy)
{
    GameObject obj;
    obj.x = x;
    obj.y = y;
    obj.vx = vx;
    obj.vy = vy;
    return obj;
}

void moveObject(GameObject &obj)
{
    obj.x += obj.vx;
    obj.y += obj.vy;
}

void moveShip(GameObject &obj, int width, int height)
{
    obj.x += obj.vx;
    obj.y += obj.vy;

    if (obj.x >= width)
    {
        obj.x -= width;
    }
    else if (obj.x < 0)
    {
        obj.x += width;
    }
}


void drawLine(double x, double y, double z, double scalex, double scaley, const Segment &segment, int color)
{
    double x1 = segment.v1.x * scalex + x;
    double y1 = segment.v1.y * scaley + y;
    double x2 = segment.v2.x * scalex + x;
    double y2 = segment.v2.y * scaley + y;

    drawLine(x1, y1, z, x2, y2, z, color);
}

void drawLines(double x, double y, double z, double scalex, double scaley, int numSegments, Segment *segments, int color)
{
    for (int i = 0; i < numSegments; i++)
    {
        drawLine(x, y, z, scalex, scaley, segments[i], color);
    }
}

void drawPerson(double x, double y, double z, double scalex, double scaley, int color)
{
    drawLines(x, y, z, scalex, scaley, 9, personDrawing, color);
}

void drawParticles(double x, double y, double z, double scalex, double scaley, int color)
{
    drawLines(x, y, z, scalex, scaley, 4, particles, color);
}

void drawShip(double x, double y, double z, double scalex, double scaley, int color)
{
    drawLines(x, y, z, scalex, scaley, 6, shipDrawing, color);
}

void drawBullet(double x, double y, double z, double scalex, double scaley, int color)
{
    drawLines(x, y, z, scalex, scaley, 4, bulletDrawing, color);
}

GameObject         ship;
vector<GameObject> enemies;
vector<GameObject> flowers; // (wink, wink)
vector<GameObject> particle;
int numEnemies;

int main(void)
{

    ship = createObject(300, 550, 0, 0);

    for (int i=0;i<11;i++)
    {
        enemies.push_back(createObject(i*30+40, 50, 1, 0));
    }

    numEnemies = enemies.size();

    startOpenGl(600,600, "Blarg");
}

void drawGuy(double x, double y)
{
    //drawLine(x + p1x, y + p1y, x + p2x, y + p2y, rgb(255,0,0));
    //drawLine(x + p3x, y + p3y, x + p4x, y + p4y, rgb(255,0,0));
}

int firing = 0;

void keyCallback(int key, int action)
{
    switch (key)
    {
    case ' ':
        if (action == KEY_PRESS)
            {
                flowers.push_back(createObject(ship.x, ship.y - 30, 0, -3));
            }
        break;
    case KEY_LEFT:
        if (action == KEY_PRESS)
        {
            ship.vx = -3;
        }
        else
        {
            ship.vx = 0;
        }
        break;
    case KEY_RIGHT:
        if (action == KEY_PRESS)
        {
            ship.vx = 3;
        }
        else
        {
            ship.vx = 0;
        }
        break;
    }
}

// button  which button was pressed or released
// action  whether this is a press or a release
void mouseButtonCallback(int button, int action)
{
    if (button == MOUSE_BUTTON_LEFT && action == KEY_PRESS)
    {
//        cout << "Left button was pressed down" << endl;
    }
    if (button == MOUSE_BUTTON_LEFT && action == KEY_RELEASE)
    {
 //       cout << "Left button was released" << endl;

    }
}

void mouseMoveCallback(double x, double y)
{
    //std::cout << x << " " << y << endl;
}

void moveEnemy(GameObject &obj, int width, int height)
{
    obj.x += obj.vx;

    if (obj.x == width - 10 || obj.x == 0)
    {
        obj.y += 50;
        obj.vx = -obj.vx;
    }
}

void displayLoop(int width, int height)
{
    for (int i=0;i<enemies.size();i++)
    {
        drawPerson(enemies[i].x, enemies[i].y, 0, 10, 10, 0xFF8080);
        moveEnemy(enemies[i], width, height);
        for (int n = 0; n < flowers.size(); n++)
        {
            if ((abs(flowers[n].x - enemies[i].x) < 10) && abs(flowers[n].y - enemies[i].y) < 20)
            {
                flowers[n].x = 9000000000;

                particle.push_back(enemies[i]);

                enemies[i].x = 9000000000;

                numEnemies--;
            }
        }
    }

    for (int i = 0; i < particle.size(); i++)
    {
        drawParticles(particle[i].x, enemies[i].y, 0, 5, 5, 0xFF0000);
        moveEnemy(particle[i], width, height);
    }

    for (int i=0;i<flowers.size();i++)
    {
        drawBullet(flowers[i].x, flowers[i].y, 0, 5, 10, 0x8080FF);
        moveObject(flowers[i]);
    }

    drawShip(ship.x, ship.y, 0, 20, 10,  0x00FF00);
    drawShip(ship.x + width, ship.y, 0, 20, 10,  0x00FF00);
    drawShip(ship.x - width, ship.y, 0, 20, 10,  0x00FF00);
    moveShip(ship, width, height);
}
