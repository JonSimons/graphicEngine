//
// Created by jondalar on 21/05/19.
//

#ifndef GRAPHICENGINE_FIGURE3D_H
#define GRAPHICENGINE_FIGURE3D_H

#include "Line_drawings_3D.h"

using namespace std;

Figure createCube();
Figure createTetrahedron();
Figure createTetrahedron();
Figure createOctahedron();
Figure createIcosahedron();
Figure Dodecahedron();
Figure createCilinder(const int n, const double h);
Figure createKegel(const int n, const double h);
Figure createBol(const double radius, const int n);
Figure createTorus(const double r, const double R, const int n, const int m);


#endif //GRAPHICENGINE_FIGURE3D_H
