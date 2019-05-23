//
// Created by jondalar on 23/05/19.
//

#include "Lsystemen_3D.h"
Figure lsysteem3D(const LParser::LSystem3D &l_system,string figName){
    Figure figure;
    string initiator = l_system.get_initiator();
    set<char> alphabet = l_system.get_alphabet();
    double angle=l_system.get_angle()/180.0*M_PI;
    unsigned int iterations = l_system.get_nr_iterations();

    for (int i = 0; i < iterations; ++i) {
        string replaced = "";
        for(char a: initiator){
            if(a=='('||a==')'||a=='+' ||a=='-' || a=='^' || a=='&'|| a=='\\'|| a=='/'||a=='| '){
                replaced.push_back(a);
            }
            for(char character:alphabet ){
                if(character==a){
                    replaced+=l_system.get_replacement(a);
                }
            }
        }
        initiator=replaced;
    }
    Vector3D point=Vector3D::point(0,0,0);
    Vector3D H=Vector3D::vector(1,0,0);
    Vector3D L=Vector3D::vector(0,1,0);
    Vector3D U=Vector3D::vector(0,0,1);
    figure.points.push_back(point);
    int indexprev=0;
    addlines3D(H,L,U,figure,angle,initiator,l_system,indexprev);
    return figure;
};
void addlines3D(Vector3D H,Vector3D L,Vector3D U,Figure& figure, double angle, string iterator,const LParser::LSystem3D &l_system,int indexprev){
    Vector3D current=figure.points[indexprev];
    for(int i=0; i<iterator.size();i++){
        char a=iterator[i];
        if(a=='+'){
            Vector3D Hnew=Vector3D::vector(H.x*cos(angle)+L.x*sin(angle),H.y*cos(angle)+L.y*sin(angle) ,H.z*cos(angle)+L.z*sin(angle));
            Vector3D Lnew=Vector3D::vector(-H.x*sin(angle)+L.x*cos(angle),-H.y*sin(angle)+L.y*cos(angle) ,-H.z*sin(angle)+L.z*cos(angle));
            H=Hnew;
            L=Lnew;
        }
        else if(a=='-'){
            Vector3D Hnew=Vector3D::vector(H.x*cos(-angle)+L.x*sin(-angle),H.y*cos(-angle)+L.y*sin(-angle) ,H.z*cos(-angle)+L.z*sin(-angle));
            Vector3D Lnew=Vector3D::vector(-H.x*sin(-angle)+L.x*cos(-angle),-H.y*sin(-angle)+L.y*cos(-angle) ,-H.z*sin(-angle)+L.z*cos(-angle));
            H=Hnew;
            L=Lnew;
        }
        else if(a=='^'){
            Vector3D Hnew=Vector3D::vector(H.x*cos(angle)+U.x*sin(angle),H.y*cos(angle)+U.y*sin(angle) ,H.z*cos(angle)+U.z*sin(angle));
            Vector3D Unew=Vector3D::vector(-H.x*sin(angle)+U.x*cos(angle),-H.y*sin(angle)+U.y*cos(angle) ,-H.z*sin(angle)+U.z*cos(angle));
            H=Hnew;
            U=Unew;
        }
        else if(a=='&'){
            Vector3D Hnew=Vector3D::vector(H.x*cos(-angle)+U.x*sin(-angle),H.y*cos(-angle)+U.y*sin(-angle) ,H.z*cos(-angle)+U.z*sin(-angle));
            Vector3D Unew=Vector3D::vector(-H.x*sin(-angle)+U.x*cos(-angle),-H.y*sin(-angle)+U.y*cos(-angle) ,-H.z*sin(-angle)+U.z*cos(-angle));
            H=Hnew;
            U=Unew;
        }
        else if(a=='\\'){
            Vector3D Lnew=Vector3D::vector(L.x*cos(angle)-U.x*sin(angle),L.y*cos(angle)-U.y*sin(angle) ,L.z*cos(angle)-U.z*sin(angle));
            Vector3D Unew=Vector3D::vector(L.x*sin(angle)+U.x*cos(angle),L.y*sin(angle)+U.y*cos(angle) ,L.z*sin(angle)+U.z*cos(angle));
            L=Lnew;
            U=Unew;
        }
        else if(a=='/'){
            Vector3D Lnew=Vector3D::vector(L.x*cos(-angle)-U.x*sin(-angle),L.y*cos(-angle)-U.y*sin(-angle) ,L.z*cos(-angle)-U.z*sin(-angle));
            Vector3D Unew=Vector3D::vector(L.x*sin(-angle)+U.x*cos(-angle),L.y*sin(-angle)+U.y*cos(-angle) ,L.z*sin(-angle)+U.z*cos(-angle));
            L=Lnew;
            U=Unew;
        }
        else if(a=='|'){
            H*=-1;
            L*=-1;
        }
        else if(a=='('){
            int counter = 0;
            for (int j = i+1; j < iterator.size() ; ++j) {
                char b = iterator[j];
                if(b == '('){counter++;}
                if(b == ')'){
                    if(counter == 0){
                        string tussenhaken = iterator.substr(i+1,j-i-1);
                        string resterend = iterator.substr(j+1);
                        addlines3D(H,L,U,figure,angle,tussenhaken,l_system,indexprev);
                        addlines3D(H,L,U,figure,angle,resterend,l_system,indexprev);
                        return;
                    } else{
                        counter --;
                    }
                }

            }
        }
        else{
            Vector3D next=Vector3D::point(current.x+H.x,current.y+H.y,current.z+H.z);
            if(l_system.draw(a)) {
                figure.points.push_back(next);
                Face face;
                face.point_indexes.push_back(indexprev);
                face.point_indexes.push_back(figure.points.size() - 1);
                figure.faces.push_back(face);
                indexprev=figure.points.size() - 1;
                current = next;
            }
        }
    }
};