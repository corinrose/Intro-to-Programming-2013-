#ifndef PIXELS_H_INCLUDED
#define PIXELS_H_INCLUDED

struct Pixel
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

Pixel *PixelRow(int y);

void setupPixels(int width, int height);  // do this once (in initialize)
void clearPixels();  // do this to clear the pixels to black (optional)
void updatePixels(); // do this after changing pixels (no need to do this if you don't change the pixels)
void drawPixels();   // do this in displayLoop every time (if you want pixels to be displayed)

extern Pixel *pixels;
extern int pixelWidth;

inline Pixel &PixelAt(int x, int y)
{
    return pixels[y*pixelWidth+x];
}

#endif // PIXELS_H_INCLUDED
