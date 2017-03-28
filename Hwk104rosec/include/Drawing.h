#ifndef DRAWING_H
#define DRAWING_H

#include <vector>
#include "shape.h"
#include "button.h"
#include "glHelper.h"

class Drawing
{
    private:
        int                  mode; // 0 line, 1 rect
        std::vector<Button*> buttons;
        std::vector<Shape*>  shapes;
        bool                 isPressed;
    public:
        Drawing();
        virtual ~Drawing();
        void initialize(int width, int height);
        void addButton(Button *button);
        void addShape(Shape *shape);
        void draw(int width, int height);
        void keyPress(int key, double mouseX, double mouseY);
        void keyRelease(int key, double mouseX, double mouseY);
        void mousePress(int button, double mouseX, double mouseY);
        void mouseRelease(int button, double mouseX, double mouseY);
        void mouseMove(double x, double y);
};

#endif // DRAWING_H
