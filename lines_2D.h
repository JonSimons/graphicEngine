//
// Created by jondalar on 28/02/19.
//

#ifndef ENGINE_LINES_2D_H
#define ENGINE_LINES_2D_H

class Color{
public:
    double red;
    double green;
    double blue;
};

class Point2D {
public:
    double x;
    double y;
};



class lines_2D {
public:
    Point2D p1;
    Point2D p2;
    Color color;
    double z1;
    double z2;
};


#endif //ENGINE_LINES_2D_H
