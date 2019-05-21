//
// Created by jondalar on 21/05/19.
//

#include "Figure3D.h"


Figure createCube(){
    Figure cube;
    Vector3D Point1=Vector3D::point(1,-1,-1);
    Vector3D Point2=Vector3D::point(-1,1,-1);
    Vector3D Point3=Vector3D::point(1,1,1);
    Vector3D Point4=Vector3D::point(-1,-1,1);
    Vector3D Point5=Vector3D::point(1,1,-1);
    Vector3D Point6=Vector3D::point(-1,-1,-1);
    Vector3D Point7=Vector3D::point(1,-1,1);
    Vector3D Point8=Vector3D::point(-1,1,1);

    cube.points.push_back(Point1);
    cube.points.push_back(Point2);
    cube.points.push_back(Point3);
    cube.points.push_back(Point4);
    cube.points.push_back(Point5);
    cube.points.push_back(Point6);
    cube.points.push_back(Point7);
    cube.points.push_back(Point8);

    Face face1;
    face1.point_indexes.push_back(1);
    face1.point_indexes.push_back(5);
    face1.point_indexes.push_back(3);
    face1.point_indexes.push_back(7);
    Face face2;
    face2.point_indexes.push_back(5);
    face2.point_indexes.push_back(2);
    face2.point_indexes.push_back(8);
    face2.point_indexes.push_back(3);
    Face face3;
    face3.point_indexes.push_back(2);
    face3.point_indexes.push_back(6);
    face3.point_indexes.push_back(4);
    face3.point_indexes.push_back(8);
    Face face4;
    face4.point_indexes.push_back(6);
    face4.point_indexes.push_back(1);
    face4.point_indexes.push_back(7);
    face4.point_indexes.push_back(4);
    Face face5;
    face5.point_indexes.push_back(7);
    face5.point_indexes.push_back(3);
    face5.point_indexes.push_back(8);
    face5.point_indexes.push_back(4);
    Face face6;
    face6.point_indexes.push_back(1);
    face6.point_indexes.push_back(6);
    face6.point_indexes.push_back(2);
    face6.point_indexes.push_back(5);

    cube.faces.push_back(face1);
    cube.faces.push_back(face2);
    cube.faces.push_back(face3);
    cube.faces.push_back(face4);
    cube.faces.push_back(face5);
    cube.faces.push_back(face6);
    cube.faces.push_back(face7);
    cube.faces.push_back(face8);

    return cube;
}

Figure createTetrahedron();{
    Figure tetrahedron;
    Vector3D Point1=Vector3D::point(1,-1,-1);
    Vector3D Point2=Vector3D::point(-1,1,-1);
    Vector3D Point3=Vector3D::point(1,1,1);
    Vector3D Point4=Vector3D::point(-1,-1,1);

    tetrahedron.points.push_back(Point1);
    tetrahedron.points.push_back(Point2);
    tetrahedron.points.push_back(Point3);
    tetrahedron.points.push_back(Point4);

    Face face1;
    face1.point_indexes.push_back(1);
    face1.point_indexes.push_back(2);
    face1.point_indexes.push_back(3);
    Face face2;
    face2.point_indexes.push_back(2);
    face2.point_indexes.push_back(4);
    face2.point_indexes.push_back(3);
    Face face3;
    face3.point_indexes.push_back(1);
    face3.point_indexes.push_back(4);
    face3.point_indexes.push_back(2);
    Face face4;
    face4.point_indexes.push_back(1);
    face4.point_indexes.push_back(3);
    face4.point_indexes.push_back(4);

    tetrahedron.faces.push_back(face1);
    tetrahedron.faces.push_back(face2);
    tetrahedron.faces.push_back(face3);
    tetrahedron.faces.push_back(face4);

    return tetrahedron;

}


Figure createOctahedron(){
    Figure octahedron;
    Vector3D Point1=Vector3D::point(1,0,0);
    Vector3D Point2=Vector3D::point(0,1,0);
    Vector3D Point3=Vector3D::point(-1,0,0);
    Vector3D Point4=Vector3D::point(0,-1,0);
    Vector3D Point5=Vector3D::point(0,0,-1);
    Vector3D Point6=Vector3D::point(0,0,1);

    octahedron.points.push_back(Point1);
    octahedron.points.push_back(Point2);
    octahedron.points.push_back(Point3);
    octahedron.points.push_back(Point4);
    octahedron.points.push_back(Point5);
    octahedron.points.push_back(Point6);

    Face face1;
    face1.point_indexes.push_back(1);
    face1.point_indexes.push_back(2);
    face1.point_indexes.push_back(6);
    Face face2;
    face2.point_indexes.push_back(2);
    face2.point_indexes.push_back(3);
    face2.point_indexes.push_back(6);
    Face face3;
    face3.point_indexes.push_back(3);
    face3.point_indexes.push_back(4);
    face3.point_indexes.push_back(6);
    Face face4;
    face4.point_indexes.push_back(4);
    face4.point_indexes.push_back(1);
    face4.point_indexes.push_back(6);
    Face face5;
    face5.point_indexes.push_back(2);
    face5.point_indexes.push_back(1);
    face5.point_indexes.push_back(5);
    Face face6;
    face6.point_indexes.push_back(3);
    face6.point_indexes.push_back(2);
    face6.point_indexes.push_back(5);
    Face face7;
    face7.point_indexes.push_back(4);
    face7.point_indexes.push_back(3);
    face7.point_indexes.push_back(5);
    Face face8;
    face8.point_indexes.push_back(1);
    face8.point_indexes.push_back(4);
    face8.point_indexes.push_back(5);

    octahedron.faces.push_back(face1);
    octahedron.faces.push_back(face2);
    octahedron.faces.push_back(face3);
    octahedron.faces.push_back(face4);
    octahedron.faces.push_back(face5);
    octahedron.faces.push_back(face6);
    octahedron.faces.push_back(face7);
    octahedron.faces.push_back(face8);

    return octahedron;
};

Figure createIcosahedron(){
    Figure icosahedron;

    Vector3D Point1=Vector3D::point(0,0,sqrt(5)/2);
    icosahedron.points.push_back(Point1)
    for (int i = 0; i <6 ; ++i) {
        Vector3D point=Vector3D::point(cos((i-2)*2*M_PI/5),sin((i-2)*2*M_PI/5),0.5);
        icosahedron.points.push_back(point);
        
    }
    for (int i = 0; i <6 ; ++i) {
        Vector3D point=Vector3D::point(cos(M_PI/5+(i-7)*2*M_PI/5),sin(M_PI/5+(i-7)*2*M_PI/5),-0.5);
        icosahedron.points.push_back(point);
    }
    Vector3D Point12=Vector3D::point(0,0,-sqrt(5)/2);
    icosahedron.points.push_back(Point12);

    Face face1;
    face1.point_indexes.push_back(1);
    face1.point_indexes.push_back(2);
    face1.point_indexes.push_back(3);
    Face face2;
    face2.point_indexes.push_back(1);
    face2.point_indexes.push_back(3);
    face2.point_indexes.push_back(4);
    Face face3;
    face3.point_indexes.push_back(1);
    face3.point_indexes.push_back(4);
    face3.point_indexes.push_back(5);
    Face face4;
    face4.point_indexes.push_back(1);
    face4.point_indexes.push_back(5);
    face4.point_indexes.push_back(6);
    Face face5;
    face5.point_indexes.push_back(1);
    face5.point_indexes.push_back(6);
    face5.point_indexes.push_back(2);
    Face face6;
    face6.point_indexes.push_back(2);
    face6.point_indexes.push_back(7);
    face6.point_indexes.push_back(3);
    Face face7;
    face7.point_indexes.push_back(3);
    face7.point_indexes.push_back(7);
    face7.point_indexes.push_back(8);
    Face face8;
    face8.point_indexes.push_back(3);
    face8.point_indexes.push_back(8);
    face8.point_indexes.push_back(4);
    Face face9;
    face9.point_indexes.push_back(4);
    face9.point_indexes.push_back(8);
    face9.point_indexes.push_back(9);
    Face face10;
    face10.point_indexes.push_back(4);
    face10.point_indexes.push_back(9);
    face10.point_indexes.push_back(5);
    Face face11;
    face11.point_indexes.push_back(5);
    face11.point_indexes.push_back(9);
    face11.point_indexes.push_back(10);
    Face face12;
    face12.point_indexes.push_back(5);
    face12.point_indexes.push_back(10);
    face12.point_indexes.push_back(6);
    Face face13;
    face13.point_indexes.push_back(6);
    face13.point_indexes.push_back(10);
    face13.point_indexes.push_back(11);
    Face face14;
    face14.point_indexes.push_back(6);
    face14.point_indexes.push_back(11);
    face14.point_indexes.push_back(2);
    Face face15;
    face15.point_indexes.push_back(2);
    face15.point_indexes.push_back(11);
    face15.point_indexes.push_back(7);
    Face face16;
    face16.point_indexes.push_back(12);
    face16.point_indexes.push_back(8);
    face16.point_indexes.push_back(7);
    Face face17;
    face17.point_indexes.push_back(12);
    face17.point_indexes.push_back(9);
    face17.point_indexes.push_back(8);
    Face face18;
    face18.point_indexes.push_back(12);
    face18.point_indexes.push_back(10);
    face18.point_indexes.push_back(9);
    Face face19;
    face19.point_indexes.push_back(12);
    face19.point_indexes.push_back(11);
    face19.point_indexes.push_back(10);
    Face face20;
    face20.point_indexes.push_back(12);
    face20point_indexes.push_back(7);
    face20.point_indexes.push_back(11);

    icosahedron.faces.push_back(face1);
    icosahedron.faces.push_back(face2);
    icosahedron.faces.push_back(face3);
    icosahedron.faces.push_back(face4);
    icosahedron.faces.push_back(face5);
    icosahedron.faces.push_back(face6);
    icosahedron.faces.push_back(face7);
    icosahedron.faces.push_back(face8);
    icosahedron.faces.push_back(face9);
    icosahedron.faces.push_back(face10);
    icosahedron.faces.push_back(face11);
    icosahedron.faces.push_back(face12);
    icosahedron.faces.push_back(face13);
    icosahedron.faces.push_back(face14);
    icosahedron.faces.push_back(face15);
    icosahedron.faces.push_back(face16);
    icosahedron.faces.push_back(face17);
    icosahedron.faces.push_back(face18);
    icosahedron.faces.push_back(face19);
    icosahedron.faces.push_back(face20);

    return icosahedron;
};
Figure Dodecahedron();
Figure createCilinder();
Figure createKegel();
Figure createBol();
Figure createTorus();