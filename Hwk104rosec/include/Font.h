#ifndef FONTS_H_INCLUDED
#define FONTS_H_INCLUDED

#include <string>
#include "Vec2d.h"
#include "PolyLine.h"

Vec2d    DrawString(const std::string &str, Vec2d position, int color, double scale = 1.0, double angle = 0.0);
//PolyLine StringToPolyLine(const std::string &str, double scale = 1.0);

#endif // GLHELPER_H_INCLUDED
