#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <cstring>
#include "pixels.h"

Pixel* pixels   = 0;
int pixelWidth  = 0;
static int pixelHeight = 0;
static GLuint pixelTextureId = 0;
static int numPixels   = 0;

Pixel *PixelRow(int y)
{
    return pixels + y*pixelWidth;
}

void setupPixels(int width, int height)
{
    pixels = new Pixel[width*height];

    pixelWidth  = width;
    pixelHeight = height;
    numPixels = width*height;

    clearPixels();

    glGenTextures(1, &pixelTextureId);
    glBindTexture(GL_TEXTURE_2D, pixelTextureId);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, (void *)pixels);
}


void clearPixels()
{
    if (pixels)
    {
        memset(pixels, 0, numPixels*sizeof(Pixel));
    }
}


void updatePixels()
{
    if (pixels)
    {
        glBindTexture(GL_TEXTURE_2D, pixelTextureId);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, pixelWidth, pixelHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, pixels);
    }
}

void drawPixels()
{
    if (pixels)
    {
        glBindTexture(GL_TEXTURE_2D, pixelTextureId);
        glEnable(GL_TEXTURE_2D);
        glBegin (GL_QUADS);
            glColor3ub(255,255,255);
            glTexCoord2f (0.0, 0.0);
            glVertex3f (0.0, 0.0, 0.0);
            glTexCoord2f (1, 0.0);
            glVertex3f (pixelWidth, 0.0, 0.0);
            glTexCoord2f (1.0, 1.0);
            glVertex3f (pixelWidth, pixelHeight, 0.0);
            glTexCoord2f (0.0, 1.0);
            glVertex3f (0.0, pixelHeight, 0.0);
        glEnd ();
        glDisable(GL_TEXTURE_2D);
    }
}


