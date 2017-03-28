#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <Windows.h>

#include "glHelper.h"

void errorCallback(int error, const char* description)
{
    fputs(description, stderr);
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int modifiers)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
    if (action < 2)
    {
        keyCallback(key, action);
    }
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int modifiers)
{
    mouseButtonCallback(button, action);
}

void mousePositionCallback(GLFWwindow* window, double x, double y)
{
    mouseMoveCallback(x, y);
}

void drawLine(double x1, double y1, double x2, double y2, unsigned int color)
{
    glBegin(GL_LINES);
        glColor3ub((color >> 16 & 0xFF), (color >> 8 & 0xFF), (color & 0xFF));
        glVertex2d(x1, y1);
        glVertex2d(x2, y2);
    glEnd();
}

void drawLine(double x1, double y1, double z1, double x2, double y2, double z2, unsigned int color)
{
    glBegin(GL_LINES);
        glColor3ub((color >> 16 & 0xFF), (color >> 8 & 0xFF), (color & 0xFF));
        glVertex3d(x1, y1, z1);
        glVertex3d(x2, y2, z2);
    glEnd();
}


void drawCube(double x1, double y1, double z1, double x2, double y2, double z2, unsigned int color)
{
    drawLine(x1, y1, z1, x2, y1, z1, color);
    drawLine(x1, y1, z1, x1, y2, z1, color);
    drawLine(x1, y1, z1, x1, y1, z2, color);

    drawLine(x2, y2, z2, x1, y2, z2, color);
    drawLine(x2, y2, z2, x2, y1, z2, color);
    drawLine(x2, y2, z2, x2, y2, z1, color);

    drawLine(x2, y1, z1, x2, y2, z1, color);
    drawLine(x2, y1, z1, x2, y1, z2, color);

    drawLine(x1, y2, z1, x2, y2, z1, color);
    drawLine(x1, y2, z1, x1, y2, z2, color);

    drawLine(x1, y1, z2, x2, y1, z2, color);
    drawLine(x1, y1, z2, x1, y2, z2, color);

}

void drawRect(double x1, double y1, double width, double height, unsigned int color)
{
    glBegin(GL_LINES);
        glColor3ub((color >> 16 & 0xFF), (color >> 8 & 0xFF), (color & 0xFF));
        glVertex2d(x1, y1);
        glVertex2d(x1+width-1, y1);
        glVertex2d(x1, y1);
        glVertex2d(x1, y1+height-1);
        glVertex2d(x1+width-1, y1);
        glVertex2d(x1+width-1, y1+height-1);
        glVertex2d(x1, y1+height-1);
        glVertex2d(x1+width-1, y1+height-1);
    glEnd();
}

void fillRect(double x1, double y1, double width, double height, unsigned int color)
{
    glBegin(GL_QUADS);
        glColor3ub((color >> 16 & 0xFF), (color >> 8 & 0xFF), (color & 0xFF));
        glVertex2d(x1, y1);
        glVertex2d(x1+width-1, y1);
        glVertex2d(x1+width-1, y1+height-1);
        glVertex2d(x1, y1+height-1);
    glEnd();
}

int internalWindowWidth;
int internalWindowHeight;

void rotate3d(double angle, double x, double y, double z)
{
    glTranslated(internalWindowWidth/2, internalWindowHeight/2, 0);
    glRotated(angle, x, y, z);
    glTranslated(-internalWindowWidth/2, -internalWindowHeight/2, 0);
}

void startOpenGl(int width, int height, const std::string &windowTitle)
{
    GLFWwindow* window;
    glfwSetErrorCallback(errorCallback);
    if (!glfwInit())
    {
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    window = glfwCreateWindow(width, height, windowTitle.c_str(), NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, keyCallback);
    glfwSetCursorPosCallback(window, mousePositionCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);

//    GLuint texture_id;
//    int img_width, img_height;
//    unsigned char* img = SOIL_load_image("img_cheryl.jpg", &img_width, &img_height, NULL, 0);
//    glGenTextures(1, &texture_id);
//    glBindTexture(GL_TEXTURE_2D, texture_id);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img_width, img_height, 0, GL_RGB, GL_UNSIGNED_BYTE, img);

    double lastTime = 0.0;

    while (!glfwWindowShouldClose(window))
    {
        glfwGetFramebufferSize(window, &width, &height);

        internalWindowHeight = height;
        internalWindowWidth  = width;

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        //glFrustrum()
        glFrustum(-2*width/6, 2*width/6, 2*height/6, -2*height/6, width*2, width*4);
        glTranslated(-width/2, -height/2, -width*3);
//        glOrtho(0, width, height, 0, 0 , 1);
        glDisable(GL_DEPTH_TEST);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.375, 0.375, 0);
        glClear(GL_COLOR_BUFFER_BIT);

        displayLoop(width, height);

        double currentTime = glfwGetTime();
        double elapsedMs = (currentTime - lastTime) * 1000;

        if (elapsedMs < 20)
        {
            Sleep(20-elapsedMs);
        }

        glfwSwapInterval(1);
        glfwSwapBuffers(window);
        glfwPollEvents();

        lastTime = currentTime;
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    exit(EXIT_SUCCESS);
}
