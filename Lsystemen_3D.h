//
// Created by jondalar on 23/05/19.
//

#ifndef GRAPHICENGINE_LSYSTEMEN_3D_H
#define GRAPHICENGINE_LSYSTEMEN_3D_H

#include "Line_drawings_3D.h"

Figure lsysteem3D(const LParser::LSystem3D &l_system,string figName);
void addlines3D(Vector3D H,Vector3D L,Vector3D U,Figure& figure, double angle, string replacement,const LParser::LSystem3D &l_system,int indexprev);

#endif //GRAPHICENGINE_LSYSTEMEN_3D_H
