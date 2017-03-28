#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <windows.h>
#include <vector>

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
