//
//  main.cpp
//  Cellular Automaton
//
//  Created by Corin Rose on 2/4/14.
//  Copyright (c) 2014 RCubed Enterprises. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

char liveCell = '.';
char deadCell = ' ';

int mod(int n, int m)
{
    n = n % m;
    if (n < 0)
        n += m;
    return n;
}

vector<vector<char> > initWorld(int x, int y)
{
    vector<vector<char> > world(y, vector<char>(x, deadCell));
    return world;
}

void addPixel(vector<vector<char> > &world, int x, int y)
{
    world[x][y] = liveCell;
}

void remPixel(vector<vector<char> > &world, int x, int y)
{
    world[x][y] = deadCell;
}

void dispWorld(vector<vector<char> > world)
{
    for (int i = 0; i < world.size(); i++)
    {
        for (int n = 0; n < world[i].size(); n++)
        {
            cout << world[i][n];
        }
        cout << endl;
    }
}

void randWorld(vector<vector<char> > &world, int prob)
{
    for (int i = 0; i < world.size(); i++)
    {
        for (int n = 0; n < world[i].size(); n++)
        {
            if (rand()%100 < prob)
            {
                world[i][n] = liveCell;
            }
        }
    }
}

int checkNeighbors(vector<vector<char> > world, int x, int y)
{
    int sizeX = int(world.size());
    
    int sizeY = int(world[x].size());
    
    int neighbors = 0;
    
    if (world[mod((x - 1) , sizeX)][y] == liveCell)
        neighbors++;
    if (world[mod((x + 1) , sizeX)][y] == liveCell)
        neighbors++;
    if (world[x][mod((y - 1) , sizeY)] == liveCell)
        neighbors++;
    if (world[x][mod((y + 1) , sizeY)] == liveCell)
        neighbors++;
    if (world[mod((x - 1) , sizeX)][mod((y - 1) , sizeX)] == liveCell)
        neighbors++;
    if (world[mod((x + 1) , sizeX)][mod((y - 1) , sizeX)] == liveCell)
        neighbors++;
    if (world[mod((x - 1) , sizeX)][mod((y + 1) , sizeX)] == liveCell)
        neighbors++;
    if (world[mod((x + 1) , sizeX)][mod((y + 1) , sizeX)] == liveCell)
        neighbors++;
    return neighbors;
}

void checkRules(vector<vector<char> > &world)
{
    vector<vector<char> > tmpWorld = world;
    
    for (int i = 0; i < world.size(); i++)
    {
        for (int n = 0; n < world[i].size(); n++)
        {
            if (checkNeighbors(world, i, n) < 2)
            {
                tmpWorld[i][n] = deadCell;
            }
            if (checkNeighbors(world, i, n) > 3)
            {
                tmpWorld[i][n] = deadCell;
            }
            if (checkNeighbors(world, i, n) == 3)
            {
                tmpWorld[i][n] = '.';
            }
        }
        cout << endl;
    }
    world = tmpWorld;
}

int main()
{
    vector<vector<char> > world = initWorld(60, 20);
    
    randWorld(world, 20);
    
    while(true)
    {
        checkRules(world);
        
        system("clear");
        
        dispWorld(world);
        
        for (int i = 0; i < 100000; i++)
        {
            
        }
    }
}