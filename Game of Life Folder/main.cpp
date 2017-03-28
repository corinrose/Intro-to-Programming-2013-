#include <iostream>
#include <vector>
#include <iomanip>
#include "GameObject.h"

using namespace std;

int x = 30;
int y = 30;

int startPercent = 20;

vector<vector<bool> > world(x, vector<bool>(y, false));
vector<vector<bool> > tmpWorld(x, vector<bool>(y, false));

bool initCell()
{
    int randNum = rand() % 100;

    if (randNum > 100 - startPercent)
    {
        return true;
    }
    return false;
}

void initWorld(vector<vector<bool> > &world)
{
    for (int i = 0; i < world.size(); i++)
    {
        for (int n = 0; n < world[i].size(); n++)
        {
            world[i][n] = initCell();
        }
    }
}

void dispWorld(vector<vector<bool> > world)
{
    for (int i = 0; i < 100; i++)
        cout << "\n";

    for (int i = 0; i < world.size(); i++)
    {
        for (int n = 0; n < world[i].size(); n++)
        {
            cout << setw(2);
            if (world[i][n])
                cout << '.';
            else
                cout << ' ';
        }
        cout << endl;
    }
}

int mod(int x, int y)
{
    if (x >= 0)
    {
        while (x >= 0)
        {
            x -= y;
        }
    }
    if (x < 0)
    {
        while (x < 0)
        {
            x += y;
        }
    }

    return x;
}

int checkNeighbor(int x, int y, vector<vector<bool> > gworld)
{
    int numNeighbors = 0;

    int xSize = world.size();
    int ySize = world[x].size();

    if (gworld[mod(x + 1 , xSize)][mod(y, ySize)])
    {
        numNeighbors++;
    }
    if (gworld[mod(x - 1 , xSize)][mod(y - 1 , ySize)])
    {
        numNeighbors++;
    }
    if (world[mod(x - 1 , xSize)][mod(y     , ySize)])
    {
        numNeighbors++;
    }
    if (gworld[mod(x + 1 , xSize)][mod(y + 1 , ySize)])
    {
        numNeighbors++;
    }
    if (gworld[mod(x     , xSize)][mod(y - 1 , ySize)])
    {
        numNeighbors++;
    }
    if (gworld[mod(x     , xSize)][mod(y + 1 , ySize)])
    {
        numNeighbors++;
    }
    if (gworld[mod(x - 1 , xSize)][mod(y + 1 , ySize)])
    {
        numNeighbors++;
    }
    if (gworld[mod(x + 1 , xSize)][mod(y - 1 , ySize)])
    {
        numNeighbors++;
    }

    return numNeighbors;
}

void checkRules(vector<vector<bool> > GameWorld, vector<vector<bool> > &tmpWorld)
{
    int neighbors;

    for (int i = 1; i < GameWorld.size(); i++)
    {
        for (int n = 1; n < GameWorld[i].size(); n++)
        {
            neighbors = checkNeighbor(i, n, GameWorld);

            if (neighbors == 3)
            {
                tmpWorld[i][n] = true;
            }
            if (neighbors < 2 || neighbors > 3)
            {
                tmpWorld[i][n] = false;
            }
        }
    }
}

int main()
{
    system("printf '\e[8;31;60t'");

    initWorld(world);

    while(true)
    {
        tmpWorld = world;

        checkRules(world, tmpWorld);

        world = tmpWorld;

        dispWorld(world);
    }
}
