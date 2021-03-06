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
    face1.point_indexes.push_back(0);
    face1.point_indexes.push_back(4);
    face1.point_indexes.push_back(2);
    face1.point_indexes.push_back(6);
    Face face2;
    face2.point_indexes.push_back(4);
    face2.point_indexes.push_back(1);
    face2.point_indexes.push_back(7);
    face2.point_indexes.push_back(2);
    Face face3;
    face3.point_indexes.push_back(1);
    face3.point_indexes.push_back(5);
    face3.point_indexes.push_back(3);
    face3.point_indexes.push_back(7);
    Face face4;
    face4.point_indexes.push_back(5);
    face4.point_indexes.push_back(0);
    face4.point_indexes.push_back(6);
    face4.point_indexes.push_back(3);
    Face face5;
    face5.point_indexes.push_back(6);
    face5.point_indexes.push_back(2);
    face5.point_indexes.push_back(7);
    face5.point_indexes.push_back(3);
    Face face6;
    face6.point_indexes.push_back(0);
    face6.point_indexes.push_back(5);
    face6.point_indexes.push_back(1);
    face6.point_indexes.push_back(4);

    cube.faces.push_back(face1);
    cube.faces.push_back(face2);
    cube.faces.push_back(face3);
    cube.faces.push_back(face4);
    cube.faces.push_back(face5);
    cube.faces.push_back(face6);

    return cube;
}

Figure createTetrahedron(){
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
    face1.point_indexes.push_back(0);
    face1.point_indexes.push_back(1);
    face1.point_indexes.push_back(2);
    Face face2;
    face2.point_indexes.push_back(1);
    face2.point_indexes.push_back(3);
    face2.point_indexes.push_back(2);
    Face face3;
    face3.point_indexes.push_back(0);
    face3.point_indexes.push_back(3);
    face3.point_indexes.push_back(1);
    Face face4;
    face4.point_indexes.push_back(0);
    face4.point_indexes.push_back(2);
    face4.point_indexes.push_back(3);

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
    face1.point_indexes.push_back(0);
    face1.point_indexes.push_back(1);
    face1.point_indexes.push_back(5);
    Face face2;
    face2.point_indexes.push_back(1);
    face2.point_indexes.push_back(2);
    face2.point_indexes.push_back(5);
    Face face3;
    face3.point_indexes.push_back(2);
    face3.point_indexes.push_back(3);
    face3.point_indexes.push_back(5);
    Face face4;
    face4.point_indexes.push_back(3);
    face4.point_indexes.push_back(2);
    face4.point_indexes.push_back(5);
    Face face5;
    face5.point_indexes.push_back(1);
    face5.point_indexes.push_back(0);
    face5.point_indexes.push_back(4);
    Face face6;
    face6.point_indexes.push_back(2);
    face6.point_indexes.push_back(1);
    face6.point_indexes.push_back(4);
    Face face7;
    face7.point_indexes.push_back(3);
    face7.point_indexes.push_back(2);
    face7.point_indexes.push_back(4);
    Face face8;
    face8.point_indexes.push_back(0);
    face8.point_indexes.push_back(3);
    face8.point_indexes.push_back(4);

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
    icosahedron.points.push_back(Point1);
    for (int i = 0; i <5 ; ++i) {
        Vector3D point=Vector3D::point(cos((i-2)*2*M_PI/5),sin((i-2)*2*M_PI/5),0.5);
        icosahedron.points.push_back(point);
        
    }
    for (int i = 0; i <5 ; ++i) {
        Vector3D point=Vector3D::point(cos(M_PI/5+(i-7)*2*M_PI/5),sin(M_PI/5+(i-7)*2*M_PI/5),-0.5);
        icosahedron.points.push_back(point);
    }
    Vector3D Point12=Vector3D::point(0,0,-sqrt(5)/2);
    icosahedron.points.push_back(Point12);

    Face face1;
    face1.point_indexes.push_back(0);
    face1.point_indexes.push_back(1);
    face1.point_indexes.push_back(2);
    Face face2;
    face2.point_indexes.push_back(0);
    face2.point_indexes.push_back(2);
    face2.point_indexes.push_back(3);
    Face face3;
    face3.point_indexes.push_back(0);
    face3.point_indexes.push_back(3);
    face3.point_indexes.push_back(4);
    Face face4;
    face4.point_indexes.push_back(0);
    face4.point_indexes.push_back(4);
    face4.point_indexes.push_back(5);
    Face face5;
    face5.point_indexes.push_back(0);
    face5.point_indexes.push_back(5);
    face5.point_indexes.push_back(1);
    Face face6;
    face6.point_indexes.push_back(1);
    face6.point_indexes.push_back(6);
    face6.point_indexes.push_back(2);
    Face face7;
    face7.point_indexes.push_back(2);
    face7.point_indexes.push_back(6);
    face7.point_indexes.push_back(7);
    Face face8;
    face8.point_indexes.push_back(2);
    face8.point_indexes.push_back(7);
    face8.point_indexes.push_back(3);
    Face face9;
    face9.point_indexes.push_back(3);
    face9.point_indexes.push_back(7);
    face9.point_indexes.push_back(8);
    Face face10;
    face10.point_indexes.push_back(3);
    face10.point_indexes.push_back(8);
    face10.point_indexes.push_back(4);
    Face face11;
    face11.point_indexes.push_back(4);
    face11.point_indexes.push_back(8);
    face11.point_indexes.push_back(9);
    Face face12;
    face12.point_indexes.push_back(4);
    face12.point_indexes.push_back(9);
    face12.point_indexes.push_back(5);
    Face face13;
    face13.point_indexes.push_back(5);
    face13.point_indexes.push_back(9);
    face13.point_indexes.push_back(10);
    Face face14;
    face14.point_indexes.push_back(5);
    face14.point_indexes.push_back(10);
    face14.point_indexes.push_back(1);
    Face face15;
    face15.point_indexes.push_back(1);
    face15.point_indexes.push_back(10);
    face15.point_indexes.push_back(6);
    Face face16;
    face16.point_indexes.push_back(11);
    face16.point_indexes.push_back(7);
    face16.point_indexes.push_back(6);
    Face face17;
    face17.point_indexes.push_back(11);
    face17.point_indexes.push_back(8);
    face17.point_indexes.push_back(7);
    Face face18;
    face18.point_indexes.push_back(11);
    face18.point_indexes.push_back(9);
    face18.point_indexes.push_back(8);
    Face face19;
    face19.point_indexes.push_back(11);
    face19.point_indexes.push_back(10);
    face19.point_indexes.push_back(9);
    Face face20;
    face20.point_indexes.push_back(11);
    face20.point_indexes.push_back(6);
    face20.point_indexes.push_back(10);

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

Figure createDodecahedron(){
    Figure icosahedron = createIcosahedron();
    Figure dodecahedron;
    for(Face face: icosahedron.faces){
        Vector3D first = icosahedron.points[face.point_indexes[0]];
        Vector3D second = icosahedron.points[face.point_indexes[1]];
        Vector3D third = icosahedron.points[face.point_indexes[2]];
        Vector3D point = Vector3D::point((first.x+second.x+third.x)/3,(first.y+second.y+third.y)/3,(first.z+second.z+third.z)/3);
        dodecahedron.points.push_back(point);
    }
    Face face1;
    face1.point_indexes.push_back(0);
    face1.point_indexes.push_back(1);
    face1.point_indexes.push_back(2);
    face1.point_indexes.push_back(3);
    face1.point_indexes.push_back(4);
    Face face2;
    face2.point_indexes.push_back(0);
    face2.point_indexes.push_back(5);
    face2.point_indexes.push_back(6);
    face2.point_indexes.push_back(7);
    face2.point_indexes.push_back(1);
    Face face3;
    face3.point_indexes.push_back(1);
    face3.point_indexes.push_back(7);
    face3.point_indexes.push_back(8);
    face3.point_indexes.push_back(9);
    face3.point_indexes.push_back(2);
    Face face4;
    face4.point_indexes.push_back(2);
    face4.point_indexes.push_back(9);
    face4.point_indexes.push_back(10);
    face4.point_indexes.push_back(11);
    face4.point_indexes.push_back(3);
    Face face5;
    face5.point_indexes.push_back(3);
    face5.point_indexes.push_back(11);
    face5.point_indexes.push_back(12);
    face5.point_indexes.push_back(13);
    face5.point_indexes.push_back(4);
    Face face6;
    face6.point_indexes.push_back(4);
    face6.point_indexes.push_back(13);
    face6.point_indexes.push_back(14);
    face6.point_indexes.push_back(5);
    face6.point_indexes.push_back(0);
    Face face7;
    face7.point_indexes.push_back(19);
    face7.point_indexes.push_back(18);
    face7.point_indexes.push_back(17);
    face7.point_indexes.push_back(16);
    face7.point_indexes.push_back(15);
    Face face8;
    face8.point_indexes.push_back(19);
    face8.point_indexes.push_back(14);
    face8.point_indexes.push_back(13);
    face8.point_indexes.push_back(12);
    face8.point_indexes.push_back(11);
    Face face9;
    face9.point_indexes.push_back(18);
    face9.point_indexes.push_back(12);
    face9.point_indexes.push_back(11);
    face9.point_indexes.push_back(10);
    face9.point_indexes.push_back(17);
    Face face10;
    face10.point_indexes.push_back(17);
    face10.point_indexes.push_back(10);
    face10.point_indexes.push_back(9);
    face10.point_indexes.push_back(8);
    face10.point_indexes.push_back(16);
    Face face11;
    face11.point_indexes.push_back(16);
    face11.point_indexes.push_back(8);
    face11.point_indexes.push_back(7);
    face11.point_indexes.push_back(6);
    face11.point_indexes.push_back(15);
    Face face12;
    face12.point_indexes.push_back(15);
    face12.point_indexes.push_back(6);
    face12.point_indexes.push_back(5);
    face12.point_indexes.push_back(14);
    face12.point_indexes.push_back(19);

    dodecahedron.faces.push_back(face1);
    dodecahedron.faces.push_back(face2);
    dodecahedron.faces.push_back(face3);
    dodecahedron.faces.push_back(face4);
    dodecahedron.faces.push_back(face5);
    dodecahedron.faces.push_back(face6);
    dodecahedron.faces.push_back(face7);
    dodecahedron.faces.push_back(face8);
    dodecahedron.faces.push_back(face9);
    dodecahedron.faces.push_back(face10);
    dodecahedron.faces.push_back(face11);
    dodecahedron.faces.push_back(face12);

    return dodecahedron;
    
};
Figure createCilinder(const int n, const double h){
    Figure cilinder;
    for (int i = 0; i < n; ++i) {
        Vector3D pointGrond=Vector3D::point(cos((2*i*M_PI)/n),sin((2*i*M_PI)/n),0);
        Vector3D pointTop=Vector3D::point(cos((2*i*M_PI)/n),sin((2*i*M_PI)/n),h);
        cilinder.points.push_back(pointGrond);cilinder.points.push_back(pointTop);
    }
    Face grondvlak;
    Face bovenvlak;
    for (int j = 0; j <2*n ; j+=2) {
        Face face;
        face.point_indexes.push_back((j+2)%(2*n));
        face.point_indexes.push_back((j+3)%(2*n));
        face.point_indexes.push_back((j+1)%(2*n));
        face.point_indexes.push_back(j);


        cilinder.faces.push_back(face);
        grondvlak.point_indexes.push_back(j);
        bovenvlak.point_indexes.push_back((j+3)%(2*n));
    }
    cilinder.faces.push_back(grondvlak);
    cilinder.faces.push_back(bovenvlak);
    return cilinder;
};
Figure createKegel(const int n, const double h){
    Figure kegel;
    for (int i = 0; i < n; ++i) {
        Vector3D point=Vector3D::point(cos((2*i*M_PI)/n),sin((2*i*M_PI)/n),0);
        kegel.points.push_back(point);
    }
    Vector3D top=Vector3D::point(0,0,h);
    kegel.points.push_back(top);
    for (int j = 0; j <n ; ++j) {
        Face face;
        face.point_indexes.push_back(j);
        face.point_indexes.push_back((j+1)%n);
        face.point_indexes.push_back(n);
        kegel.faces.push_back(face);
    }
    Face grondvlak;
    for (int k = 0; k <n ; ++k) {
        grondvlak.point_indexes.push_back(k);
    }
    kegel.faces.push_back(grondvlak);
    return kegel;
};
Figure createBol(const double radius, const int n){
    Figure icosahedron=createIcosahedron();
    Figure bol;
    for (int i = 0; i < n; ++i) {
        Figure temp;
        int k=0;
        for (Face face: icosahedron.faces) {
            Vector3D first = icosahedron.points[face.point_indexes[0]];
            Vector3D second = icosahedron.points[face.point_indexes[1]];
            Vector3D third = icosahedron.points[face.point_indexes[2]];
            Vector3D D=Vector3D::point((first.x+second.x)/2,(first.y+second.y)/2,(first.z+second.z)/2);
            Vector3D E=Vector3D::point((first.x+third.x)/2,(first.y+third.y)/2,(first.z+third.z)/2);
            Vector3D F=Vector3D::point((third.x+second.x)/2,(third.y+second.y)/2,(third.z+second.z)/2);

            temp.points.push_back(first);temp.points.push_back(second);temp.points.push_back(third);
            temp.points.push_back(D);temp.points.push_back(E);temp.points.push_back(F);

            Face face1;
            face1.point_indexes.push_back(k+0);face1.point_indexes.push_back(k+3);face1.point_indexes.push_back(k+4);
            Face face2;
            face2.point_indexes.push_back(k+1);face2.point_indexes.push_back(k+5);face2.point_indexes.push_back(k+3);
            Face face3;
            face3.point_indexes.push_back(k+2);face3.point_indexes.push_back(k+4);face3.point_indexes.push_back(k+5);
            Face face4;
            face4.point_indexes.push_back(k+3);face4.point_indexes.push_back(k+5);face4.point_indexes.push_back(k+4);

            temp.faces.push_back(face1);temp.faces.push_back(face2);temp.faces.push_back(face3);temp.faces.push_back(face4);

            k+=6;
        }
        icosahedron=temp;
    }
    bol=icosahedron;
    for (Vector3D &point:bol.points){
        double r=point.length();
        point.x/=r*radius;
        point.y/=r*radius;
        point.z/=r*radius;
    }
    return bol;

};
Figure createTorus(const double r, const double R, const int n, const int m){
    Figure torus;
    for (int i = 0; i < n; ++i) {
        double u = 2*i*M_PI/n;
        for (int j = 0; j < m; ++j) {
            double v = 2*j*M_PI/m;
            double x = (R + r*cos(v))*cos(u);
            double y = (R + r*cos(v))*sin(u);
            double z = r*sin(v);

            Vector3D point = Vector3D::point(x,y,z);
            torus.points.push_back(point);
            Face face;

            face.point_indexes.push_back(i*m+j);
            face.point_indexes.push_back(((i+1)%n)*m+j);
            face.point_indexes.push_back(((i+1)%n)*m+(j+1)%m);
            face.point_indexes.push_back(i*m+(j+1)%m);
            torus.faces.push_back(face);
        }
    }

    return torus;
};