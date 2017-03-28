#include "OpenGLStuff.h"

struct GameObject
{
    double x;
    double y;

    double Vx;
    double Vy;

    double Ax;
    double Ay;

    double scale;

    int shape;
};

void drawLine(double x1, double y1, double x2, double y2)
{
    glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    glEnd();
}

void drawCircle(GameObject obj)
{
    for (int i = 0; i < 1000; i++)
        drawLine(obj.x, obj.y, obj.scale*(cos(i)) + obj.x, obj.scale*(sin(i)) + obj.y);
}

void moveObject(GameObject &obj, int windowX, int windowY)
{
    obj.x += obj.Vx;
    obj.y += obj.Vy;

    obj.Vx += obj.Ax;
    obj.Vy += obj.Ay;

    if (obj.x - obj.scale <= 0 || obj.x + obj.scale >= windowX)
        obj.Vx = -obj.Vx;

    if (obj.y - obj.scale <= 0 || obj.y + obj.scale >= windowY)
        obj.Vy = -obj.Vy;
}

void drawObject(GameObject obj)
{
    // 1: circle
    // 2: square

    switch (obj.shape)
    {
    case 1:
        drawCircle(obj);
        break;
    case 2:
        glBegin(GL_QUADS);
            glVertex2d(obj.x - obj.scale, obj.y - obj.scale);
            glVertex2d(obj.x - obj.scale, obj.y + obj.scale);
            glVertex2d(obj.x + obj.scale, obj.y + obj.scale);
            glVertex2d(obj.x + obj.scale, obj.y - obj.scale);
        glEnd();
        break;
    }
}

GameObject initRandObj(int windowX, int windowY)
{
    GameObject obj;

    obj.x = rand() % windowX;
    obj.y = rand() % windowY;

    obj.Vx = rand() % 20;
    obj.Vy = rand() % 20;

    obj.Ax = 0;
    obj.Ay = 0;

    obj.shape = rand() % 2 + 1;

    obj.scale = rand() % 25 + 25;

    return obj;
}

void debugObj(GameObject obj)
{
    std::cout << "obj.x: " << obj.x << std::endl;
    std::cout << "obj.y: " << obj.y << std::endl;

    std::cout << "obj.Vx: " << obj.Vx << std::endl;
    std::cout << "obj.Vy: " << obj.Vy << std::endl;

    std::cout << "obj.shape: " << obj.shape << std::endl;
    std::cout << "obj.scale: " << obj.scale << std::endl;
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

void updateObject(GameObject &obj, int windowX, int windowY)
{
    drawObject(obj);
    moveObject(obj, windowX, windowY);
}

void drawQuad(int a, int b, int c, int d, int e, int f, int g, int h)
{
    glBegin(GL_QUADS);
        glVertex2d(a, b);
        glVertex2d(c, d);
        glVertex2d(e, f);
        glVertex2d(g, h);
    glEnd();
}

int main(void)
{
    srand(glfwGetTime());

    int windowX = 1200;
    int windowY = 700;

    std::vector<GameObject> objs(100);

    for (int i = 0; i < objs.size(); i++)
        objs[i] = initRandObj(windowX, windowY);

    GameObject randObj = initRandObj(windowX, windowY);
    randObj.Vx = .1;
    randObj.Vy = .1;
    randObj.x = 100;


	GLFWwindow* window;
	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
	{
    	exit(EXIT_FAILURE);
	}
	window = glfwCreateWindow(windowX, windowY, "Coll Uf Dooty 24", NULL, NULL);
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

        //press spacebar!!!!

    	if (glfwGetKey(window, 32))
        {
            drawQuad(0, 0, 0, windowY, windowX, windowY, windowX, 0);

            for (int i = 0; i < objs.size(); i++)
            {
                glColor3ub(rand(), rand(), rand());
                updateObject(objs[i], windowX, windowY);
                updateObject(randObj, windowX, windowY);
            }
            Sleep(10);
        }
        else
        {
            glColor3ub(255, 255, 255);
            updateObject(randObj, windowX, windowY);
        }

    	glfwSwapBuffers(window);
    	glfwPollEvents();

	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}
