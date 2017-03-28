#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>

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

void drawCircle(int h, int k, int radius)
{
    for (int i = 0; i < 5000; i++)
        drawLine(h, k, radius * cos(i) + h, radius * sin(i) + k, 0, 0, 255);
}

void drawThang(double red, double green, double blue)
{
    int y1 = 0;
    int x2 = 0;

    for (int i = 10; i < 1000; i += 10)
    {
        drawLine(0, y1, x2, 500, red, green, blue);
        x2 = i;
        y1 = i;
    }
}

int main(void)
{
	GLFWwindow* window;
	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
	{
    	exit(EXIT_FAILURE);
	}
	window = glfwCreateWindow(1000, 500, "Simple example", NULL, NULL);
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

        drawCircle(150, 0, 150);

    	glfwSwapBuffers(window);
    	glfwPollEvents();

	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}
