//
// Created by jondalar on 17/05/19.
//

#ifndef ENGINE_FIGURE_H
#define ENGINE_FIGURE_H

#include "Face.h"
#include <vector>
#include "vector3d.h"
#include <cmath>
#include "L2D_systemen.h"

using namespace std;

class Figure {
public:
    std::vector<Vector3D> points;
    std::vector<Face> faces;
    Color color;
};
typedef std::list<Figure> Figures3D;


#endif //ENGINE_FIGURE_H
