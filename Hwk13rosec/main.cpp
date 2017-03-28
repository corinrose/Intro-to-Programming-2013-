#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>

int keyPosX = 250;
int keyPosY = 500;

// yeah i know global variables are bad but i was just messing around
// and didn't feel like putting actual effort into it. also it's not
// technically part of the homework, so you can't take points off :P
// well you can but that wouldn't be cool.

void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int modifiers)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
    	glfwSetWindowShouldClose(window, GL_TRUE);
	}
}


void mouseButtonCallback(GLFWwindow* window, int button, int action, int modifiers)
{

}

double mouseX;
double mouseY;

void mousePositionCallback(GLFWwindow* window, double x, double y)
{
	mouseX = x;
	mouseY = y;
   // std::cout << x << " " << y << std::endl;
}

typedef void (* GLFWmousebuttonfun)(GLFWwindow*,int,int,int);

void drawLine(double x1, double y1, double x2, double y2, double red, double green, double blue)
{
    glBegin(GL_LINES);
        glColor3ub(red, green, blue);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    glEnd();
}

void drawCircle(int h, int k, int radius, double red, double green, double blue)
{
    for (int i = 0; i < 10000; i++)
        drawLine(h, k, radius * cos(i) + h, radius * sin(i) + k, red, green, blue);
}

void drawThang(double density, double red, double green, double blue)
{
    int y1 = 0;
    int x2 = 0;

    for (int i = density; i < density * 75; i += density)
    {
        drawLine(0, y1, x2, 500, red, green, blue);
        x2 = i;
        y1 = i;
    }
}

void haloThirteen(int x, int y, double red, double green, double blue)
{
    int bloop = 40;

    int changeX = 30;

    glBegin(GL_QUADS);
        glColor3ub(red + 50, green - 200, blue);
        glVertex2d(0, 0);
        glVertex2d(x - bloop - changeX, y - bloop);
        glVertex2d(x + bloop + changeX, y - bloop);
        glVertex2d(1000, 0);
    glEnd();


    glBegin(GL_QUADS);
        glColor3ub(red - 150, green, blue + 200);
        glVertex2d(0, 500);
        glVertex2d(x - bloop - changeX, y + bloop);
        glVertex2d(x + bloop + changeX, y + bloop);
        glVertex2d(1000, 500);
    glEnd();

    glBegin(GL_QUADS);
        glColor3ub(green - 100, blue, red + 60);
        glVertex2d(0, 0);
        glVertex2d(x - bloop - changeX, y - bloop);
        glVertex2d(x - bloop - changeX, y + bloop);
        glVertex2d(0, 500);
    glEnd();

    glBegin(GL_QUADS);
        glColor3ub(green, blue, red);
        glVertex2d(1000, 0);
        glVertex2d(x + bloop + changeX, y - bloop);
        glVertex2d(x + bloop + changeX, y + bloop);
        glVertex2d(1000, 500);
    glEnd();
}

void seizures(GLFWwindow* window, int density, int windowX, int windowY)
{
        int x = windowX / 2;
        int y = windowY / 2;


        int red = rand();
        int green = rand();
        int blue = rand();

        for (int i = 0; i < windowX; i += density)
            drawLine(i, 0, x, y, red, green, blue);

        for (int i = 0; i < windowY; i += density)
            drawLine(windowX, i, x, y, red + 50, green, blue - 150);

        for (int i = windowX; i > 0; i -= density)
            drawLine(i, windowY, x, y, red - 120, green + 60 , blue);

        for (int i = windowY; i > 0; i -= density)
            drawLine(0, i, x, y, red, green + 150 , blue - 60);

}

int main(void)
{
    int windowX = 1000;
    int windowY = 500;

    // windowX and Y are the x and y lengths of the window

    srand(glfwGetTime());

	GLFWwindow* window;
	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
	{
    	exit(EXIT_FAILURE);
	}
	window = glfwCreateWindow(windowX, windowY, "Halo 13", NULL, NULL);
	if (!window)
	{
    	glfwTerminate();
    	exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);

	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, mousePositionCallback);

	while (!glfwWindowShouldClose(window))
	{
    	int width, height;
    	glfwGetFramebufferSize(window, &width, &height);
    	glMatrixMode(GL_PROJECTION);
    	glLoadIdentity();
    	glOrtho(0, width, height, 0, 0 , 1);
    	glDisable(GL_DEPTH_TEST);
    	glMatrixMode(GL_MODELVIEW);
    	glLoadIdentity();
    	glTranslatef(0.375, 0.375, 0);
    	glClear(GL_COLOR_BUFFER_BIT);

    	// GL_LINE_LOOP
    	// GL_TRIANGLE_FAN
    	// GL_POINTS

        //seizures(window, 10, windowX, windowY); // warning, may cause siezures


        //drawCircle(windowX / 2, windowY / 2, 60, 150, 0, 150); // draws a circle in the center of the screen

        //haloThirteen(x, y, 150, 0, 150); // Halo 13!!!!!

        drawThang(10, 150, 0, 150);

        // Actual homework is only "drawThang()" function. the rest is
        // me messing around. arguments affect density of lines, and
        // colour. red, green, then blue.

        if (glfwGetKey(window, 'A')) // horizontal movement to the right
            keyPosX -= 1;
        if (glfwGetKey(window, 'D')) // horizontal movement to the left
            keyPosX += 1;
        if (glfwGetKey(window, 'W')) // upward movement
            keyPosY -= 1;
        if (glfwGetKey(window, 'S')) // downward movement
            keyPosY += 1;

        circleSize += circleSize/2000;


    	glfwSwapBuffers(window);
    	glfwPollEvents();

	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}
