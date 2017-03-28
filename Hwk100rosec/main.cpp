#include "glHelper.h"
#include <iostream>
#include <string>
#include "pixels.h"
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

const int worldSize = 600;
int cellScale = 1;
int windowSize = cellScale*worldSize;
int startPercent = 5;


bool    world[worldSize][worldSize];
bool tmpWorld[worldSize][worldSize];

void initCell(int i, int n)
{
    int randNum = rand() % 100;
    if (randNum > 100 - startPercent)
    {
        world[i][n] = true;
    }
}

int main(void)
{
    srand(64634);

    for (int i = 0; i < worldSize; i++)
    {
        for (int n = 0; n < worldSize; n++)
        {
            initCell(i, n);
        }
    }

    startOpenGl(windowSize,windowSize, "The Game of Life");
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

void drawGrid(int colour)
{
    for (int i = 0; i < windowSize; i += cellScale)
    {
            drawLine(i, 0, i, windowSize, colour);
            drawLine(0, i, windowSize, i, colour);
    }
}

void drawWorld()
{
    for (int i = 0; i < worldSize; i++)
    {
        for (int n = 0; n < worldSize; n++)
        {
            if (world[i][n])
            {
                //fillRect(i*cellScale, n*cellScale, cellScale, cellScale, rgb(255, 255, 255));
                // ^^ looks better, but doesn't use pixels which i assume you wanted us too.

                for (int j = 0; j < cellScale; j++)
                {
                    for (int k = 0; k < cellScale; k++)
                    {
                        PixelAt(i*cellScale + j, n*cellScale + k) = {255, 255, 255};
                    }
                }

            }
        }
    }
}

int checkNeighbor(int i, int n)
{
    int numNeighbors = 0;
    if (tmpWorld[i + 1 % worldSize][n])
    {
        numNeighbors++;
    }
    if (tmpWorld[i - 1 % worldSize][n])
    {
        numNeighbors++;
    }
    if (tmpWorld[i][n + 1 % worldSize])
    {
        numNeighbors++;
    }
    if (tmpWorld[i][n - 1 % worldSize])
    {
        numNeighbors++;
    }
    if (tmpWorld[i - 1 % worldSize][n - 1 % worldSize])
    {
        numNeighbors++;
    }
    if (tmpWorld[i - 1 % worldSize][n + 1 % worldSize])
    {
        numNeighbors++;
    }
    if (tmpWorld[i + 1 % worldSize][n - 1 % worldSize])
    {
        numNeighbors++;
    }
    if (tmpWorld[i + 1 % worldSize][n + 1 % worldSize])
    {
        numNeighbors++;
    }
    return numNeighbors;
}

void checkRules()
{
    int neighbors;

    for (int i = 0; i < worldSize; i++)
    {
        for (int n = 0; n < worldSize; n++)
        {
            neighbors = checkNeighbor(i, n);

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

void copyWorld()
{
    for (int i = 0; i < worldSize; i++)
    {
        for (int n = 0; n < worldSize; n++)
        {
            tmpWorld[i][n] = world[i][n];
        }
    }
}

void copyTmpWorld()
{
    for (int i = 0; i < worldSize; i++)
    {
        for (int n = 0; n < worldSize; n++)
        {
            world[i][n] = tmpWorld[i][n];
        }
    }
}

void displayLoop(int width, int height)
{
    clearPixels();

    copyWorld();

    checkRules();

    copyTmpWorld();

    drawWorld();

    drawGrid(rgb(150, 0, 150));

    updatePixels();

    drawPixels();

    //Sleep(50);
}

