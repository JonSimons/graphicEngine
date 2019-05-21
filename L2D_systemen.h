//
// Created by jondalar on 28/02/19.
//

#ifndef ENGINE_L2D_SYSTEMEN_H
#define ENGINE_L2D_SYSTEMEN_H

#include <list>
#include "lines_2D.h"
#include "easy_image.h"
#include "l_parser.h"
#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;

typedef std::list<lines_2D> Lines2D;
img::EasyImage draw2DLines(const Lines2D& lines,const int size, img::Color backgroundColor);
Lines2D drawLSystem(const LParser::LSystem2D &l_system,Color kleur);
void addLines(const LParser::LSystem2D &l_system, Lines2D &lines, Point2D location,double angle, double startingAngle, string &iterator, Color color);

#endif //ENGINE_L2D_SYSTEMEN_H
