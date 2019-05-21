//
// Created by jondalar on 17/05/19.
//

#ifndef ENGINE_LINE_DRAWINGS_3D_H
#define ENGINE_LINE_DRAWINGS_3D_H
#include <vector>
#include "vector3d.h"
#include <cmath>
#include "L2D_systemen.h"
#include "Figure.h"
#include "ini_configuration.h"

using namespace std;



class Line_drawings_3D {
public:
    Matrix scaleFigure(const double scale);
    Matrix rotateX(const double angle);
    Matrix rotateY(const double angle);
    Matrix rotateZ(const double angle);
    Matrix translate(const Vector3D &vector);
    void applyTransformation(Figure &, const Matrix &);
    Matrix eyePointTrans(const Vector3D &eyepoint);
    void toPolar(const Vector3D &point,double &theta,double &phi,double &r);
    Lines2D doProjection(const Figures3D &figures3D);
    Point2D doProjection(const Vector3D &point, const double d);
    void fixFigure(Figures3D &figures3D,Figure& part,const ini::Configuration& configuration, int figureNr,const Vector3D eyePoint);


};


#endif //ENGINE_LINE_DRAWINGS_3D_H
