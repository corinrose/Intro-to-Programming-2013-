#ifndef GLHELPER_H_INCLUDED
#define GLHELPER_H_INCLUDED

#include <string>

void startOpenGl(int width, int height, const std::string &windowTitle);

// you implement this...
void initialize(int width, int height);
void displayLoop(int width, int height);
void keyCallback(int key, int action);
void mouseButtonCallback(int button, int action);
void mouseMoveCallback(double x, double y);

// drawing functions

inline unsigned int rgb(unsigned char red, unsigned char green, unsigned char blue)
{
    return (unsigned int)red << 16 | (unsigned int)green << 8 | (unsigned int)blue;
}

// 2d drawing functions

void drawLine(double x1, double y1, double x2, double y2, unsigned int color);

void drawRect(double x1, double y1, double width, double height, unsigned int color);
void fillRect(double x1, double y1, double width, double height, unsigned int color);

// 2d function declarations... not yet implemented

void drawTriangle(double x1, double y1, double x2, double y2, double x3, double y3, unsigned int color);
void fillTriangle(double x1, double y1, double x2, double y2, double x3, double y3, unsigned int color);

void drawQuad(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, unsigned int color);
void fillQuad(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, unsigned int color);

void drawEllipse(double cx, double cy, double width, double height, unsigned int color);
void fillEllipse(double cx, double cy, double width, double height, unsigned int color);

// 3d functions
void drawLine(double x1, double y1, double z1, double x2, double y2, double z2, unsigned int color);
void drawCube(double x1, double y1, double z1, double x2, double y2, double z2, unsigned int color);
void rotate3d(double angleInDegrees, double x, double y, double z);

// key actions
#define KEY_PRESS     1
#define KEY_RELEASE   0

// key codes
#define KEY_ENTER     257
#define KEY_BACKSPACE 259
#define KEY_DELETE    261
#define KEY_RIGHT     262
#define KEY_LEFT      263
#define KEY_DOWN      264
#define KEY_UP        265

// mouse buttons
#define MOUSE_BUTTON_LEFT   0
#define MOUSE_BUTTON_CENTER 2
#define MOUSE_BUTTON_RIGHT  1

#endif // GLHELPER_H_INCLUDED
