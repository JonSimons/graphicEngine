//
// Created by jondalar on 17/05/19.
//

#include "Line_drawings_3D.h"

Matrix Line_drawings_3D::scaleFigure(const double scale){
    Matrix scaleMatrix;
    scaleMatrix(1,1)=scale;
    scaleMatrix(2,2)=scale;
    scaleMatrix(3,3)=scale;
    scaleMatrix(4,4)=1;
    return scaleMatrix;
}
Matrix Line_drawings_3D::rotateX(const double angle){
    Matrix rotationMatrix;
    rotationMatrix(1,1)=1;
    rotationMatrix(2,2)=cos(angle);
    rotationMatrix(2,3)=sin(angle);
    rotationMatrix(3,2)=-sin(angle);
    rotationMatrix(3,3)=cos(angle);
    rotationMatrix(4,4)=1;
    return rotationMatrix;
}
Matrix Line_drawings_3D::rotateY(const double angle) {
    Matrix rotationMatrix;
    rotationMatrix(1,1)=cos(angle);
    rotationMatrix(2,2)=1;
    rotationMatrix(1,3)=-sin(angle);
    rotationMatrix(3,1)=sin(angle);
    rotationMatrix(3,3)=cos(angle);
    rotationMatrix(4,4)=1;
    return rotationMatrix;
}
Matrix Line_drawings_3D::rotateZ(const double angle) {
    Matrix rotationMatrix;
    rotationMatrix(1,1)=cos(angle);
    rotationMatrix(1,2)=sin(angle);
    rotationMatrix(2,1)=-sin(angle);
    rotationMatrix(2,2)=cos(angle);
    rotationMatrix(3,3)=1;
    rotationMatrix(4,4)=1;
    return rotationMatrix;
}
Matrix Line_drawings_3D::translate(const Vector3D &vector) {
    Matrix translateMatrix;
    translateMatrix(1,1)=1;
    translateMatrix(2,2)=1;
    translateMatrix(3,3)=1;
    translateMatrix(4,4)=1;
    translateMatrix(4,1)=vector.x;
    translateMatrix(4,2)=vector.y;
    translateMatrix(4,3)=vector.z;
    return translateMatrix;
}
void Line_drawings_3D::applyTransformation(Figure &figure, const Matrix &matrix) {
    for(Vector3D &point:figure.points){
        point*=matrix;
    }
}
Matrix Line_drawings_3D::eyePointTrans(const Vector3D &eyepoint) {
    double r,theta,phi;
    toPolar(eyepoint,theta,phi,r);
    Matrix eyePointTrans;
    eyePointTrans=rotateZ(-M_PI/(2)-theta)*rotateX(-phi)*translate(Vector3D::vector(0,0,-r));
    return eyePointTrans;

}

void Line_drawings_3D::toPolar(const Vector3D &point, double &theta, double &phi, double &r) {
    r=sqrt(pow(point.x,2)+pow(point.y,2)+pow(point.z,2));
    theta=atan2(point.y,point.x);
    phi=acos(point.z/r);
}
Lines2D Line_drawings_3D::doProjection(const Figures3D& figures3D) {
    Lines2D lines2D;
    for (const Figure& figure:figures3D){
        for(const Face& face:figure.faces){
            for (int i = 0; i <face.point_indexes.size()-1 ; ++i) {
                lines_2D line2D;
                line2D.p1=doProjection(figure.points[face.point_indexes[i]],1.0);
                line2D.p2=doProjection(figure.points[face.point_indexes[i+1]],1.0);
                line2D.color=figure.color;
                lines2D.push_back(line2D);
            }
            if(face.point_indexes.size()>2){
                lines_2D line2D;
                line2D.p1=doProjection(figure.points[face.point_indexes[face.point_indexes.size()]],1.0);
                line2D.p2=doProjection(figure.points[face.point_indexes[0]],1.0);
                line2D.color=figure.color;
                lines2D.push_back(line2D);
            }
        }
    }
    return lines2D;
}
Point2D Line_drawings_3D::doProjection(const Vector3D &point, const double d) {
    Point2D point2D;
    point2D.x=d*point.x/-point.z;
    point2D.y=d*point.y/-point.z;
    return point2D;
}
void Line_drawings_3D::fixFigure(Figures3D &figures3D, Figure &figuur, const ini::Configuration &configuration, int figureNr,const Vector3D eyePoint) {
    vector<double> center=configuration["Figure"+to_string(figureNr)]["center"].as_double_tuple_or_die();
    Vector3D toTranslate=Vector3D::point(center[0],center[1],center[2]);
    Matrix translatieMatrix=scaleFigure(configuration["Figure"+to_string(figureNr)]["scale"].as_double_or_die());
    translatieMatrix*=rotateX(configuration["Figure"+to_string(figureNr)]["rotateX"].as_int_or_die());
    translatieMatrix*=rotateY(configuration["Figure"+to_string(figureNr)]["rotateY"].as_int_or_die());
    translatieMatrix*=rotateZ(configuration["Figure"+to_string(figureNr)]["rotateZ"].as_int_or_die());
    translatieMatrix*=eyePointTrans(eyePoint);
    translatieMatrix*=translate(toTranslate);
    applyTransformation(figuur,translatieMatrix);
    figures3D.push_back(figuur);

}
