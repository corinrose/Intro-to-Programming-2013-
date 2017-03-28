#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>

struct vertex
{
    int x;
    int y;
};

struct line
{
    vertex pt1;
    vertex pt2;
};


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

void drawLine(double x1, double y1, double x2, double y2)
{
    glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    glEnd();
}

void drawLine(line x)
{
    glBegin(GL_LINES);
        glVertex2d(x.pt1.x, x.pt1.y);
        glVertex2d(x.pt2.x, x.pt2.y);
    glEnd();
}

void drawDigit(int x, int y, int scale, int digit)
{
    int hscl = scale/2;
    int sclAndHalf = scale + hscl;

    switch (digit)
    {
    case 0:
        y = y + hscl;
        drawLine(x-(scale/2), y-(scale), x+(scale/2), y-(scale));
        drawLine(x+(scale/2), y-(scale), x+(scale/2), y+(scale));
        drawLine(x+(scale/2), y+(scale), x-(scale/2), y+(scale));
        drawLine(x-(scale/2), y+(scale), x-(scale/2), y-(scale));
        break;
    case 1:
        drawLine(x, y + sclAndHalf, x, y - hscl);
        break;
    case 2:
        y = y + hscl;
        glBegin(GL_LINES);
            glVertex2f(x-scale/2,y-scale);
            glVertex2f(x+scale/2,y-scale);
            glVertex2f(x+scale/2,y-scale);
            glVertex2f(x+scale/2,y);
            glVertex2f(x+scale/2,y);
            glVertex2f(x-scale/2,y);
            glVertex2f(x-scale/2,y);
            glVertex2f(x-scale/2,y+scale);
            glVertex2f(x-scale/2,y+scale);
            glVertex2f(x+scale/2,y+scale);
        glEnd();
        break;
    case 3:
        y = y + hscl;
        drawLine(x-(scale/2), y, x+(scale/2), y);
        drawLine(x-(scale/2), y+scale,x+(scale/2), y+scale);
        drawLine(x-(scale/2), y-scale, x+(scale/2), y-scale);
        drawLine(x+(scale/2), y+scale, x+(scale/2), y-scale);
        break;
    case 4:
        drawLine(x - hscl, y - scale + hscl, x - hscl, y + hscl);
        drawLine(x + hscl, y + hscl        , x - hscl, y + hscl);
        drawLine(x + hscl, y + sclAndHalf  , x + hscl, y - scale + hscl);
        break;
    case 5:
        y = y + hscl;
        drawLine(x+(scale/2),y+scale, x-(scale/2), y+scale); //top
        drawLine(x+scale/2,y,x-scale/2,y); //mid
        drawLine(x+(scale/2),y-scale, x-(scale/2), y-scale); //bottom
        drawLine(x-(scale/2),y-scale, x-(scale/2), y); //vertical top
        drawLine(x+(scale/2),y+scale, x+(scale/2), y); //vertical bottom
        break;
    case 6:
        drawLine(x - hscl, y - scale + hscl, x + hscl, y - scale + hscl); //(0,0,50,0 )
        drawLine(x - hscl, y - scale + hscl, x - hscl, y + hscl);
        drawLine(x - hscl, y + hscl        , x + hscl, y + hscl); //middle of six is at (25,50)
        drawLine(x - hscl, y + hscl        , x - hscl, y + scale + hscl);
        drawLine(x + hscl, y + hscl        , x + hscl, y + scale + hscl);
        drawLine(x - hscl, y + scale + hscl, x + hscl, y + scale + hscl);
        break;
    case 7:
        x = x - hscl;
        y = y - hscl;

        drawLine(x, y, x + scale, y);
        drawLine(x + scale, y, x + hscl, y + 2*scale);
        break;
    case 8:
        x = x - hscl;
        y = y - hscl;
        drawLine(x        , y          , x + scale, y);
        drawLine(x        , y          , x        , y + 2*scale);
        drawLine(x        , y + scale  , x + scale, y + scale);
        drawLine(x        , y + 2*scale, x + scale, y + 2*scale);
        drawLine(x + scale, y          , x + scale, y + scale*2);
        break;
    case 9:
        x = x - hscl;
        y = y - hscl;

        drawLine(x, y, x + scale, y);
        drawLine(x, y + scale, x, y);
        drawLine(x + scale, y + scale, x + scale, y);
        drawLine(x, y + scale, x + scale, y + scale);
        drawLine(x + scale, y + scale, x + scale, y + 2*scale);
        break;
    }
}

void drawNum(int x, int y, int num, int scale)
{
    int numLength = log10(num) + 1;

    int digit;

    for (int i = 1; i <= numLength; i++)
    {
    int tmp = ceil(pow(10, i));
    digit = num % tmp;
    digit = digit / pow(10, i - 1);
    drawDigit(x - scale*(1.5*i), y, scale, digit);
    }
}

int main(void)
{
    int number;

    std::cout << "Enter Number: ";
    std::cin >> number;

    int windowX = 1000;
    int windowY = 500;

    int keyPosX = 1000;
    int keyPosY = 250;

    line thing;
    thing.pt1.x = 0;
    thing.pt1.y = 0;
    thing.pt2.x = 1000;
    thing.pt2.y = 500;

	GLFWwindow* window;
	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
	{
    	exit(EXIT_FAILURE);
	}
	window = glfwCreateWindow(windowX, windowY, "Halo 5", NULL, NULL);
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

        glColor3ub(150, 0, 150);

        int scale = 50;

        drawNum(keyPosX, keyPosY, number, scale);

        //drawLine(thing);

        if (glfwGetKey(window, 'A'))
            keyPosX -= 1;
        if (glfwGetKey(window, 'D'))
            keyPosX += 1;
        if (glfwGetKey(window, 'W'))
            keyPosY -= 1;
        if (glfwGetKey(window, 'S'))
            keyPosY += 1;


    	glfwSwapBuffers(window);
    	glfwPollEvents();

	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}
