
#include "L2D_systemen.h"
#include "ZBuffer.h"


img::EasyImage draw2DLines(const Lines2D& lines,const int size, img::Color backgroundColor, bool zbuff){
    double xmin=lines.front().p1.x;
    double xmax=lines.front().p1.x;
    double ymin=lines.front().p1.y;
    double ymax=lines.front().p1.y;
    for (lines_2D line:lines) {
        if(line.p1.y<ymin){
            ymin=line.p1.y;}
        if(line.p1.y>ymax){
            ymax=line.p1.y;}
        if(line.p1.x<xmin){
            xmin=line.p1.x;}
        if(line.p2.x>xmax){
            xmax=line.p2.x;}
        if(line.p2.y<ymin){
            ymin=line.p2.y;}
        if(line.p1.x>xmax){
            xmax=line.p1.x;}
        if(line.p2.x<xmin){
            xmin=line.p2.x;}
        if(line.p2.y>ymax){
            ymax=line.p2.y;}
    }
    double xrange = xmax-xmin;
    double yrange = ymax-ymin;
    double maxrange = yrange;
    if(xrange > yrange){
        maxrange = xrange;
    }
    double imagex = size*xrange/maxrange;
    double imagey = size*yrange/maxrange;
    double d = 0.95*imagex/xrange;

    double dcx = d*(xmin+xmax)/2.0;
    double dcy = d*(ymin+ymax)/2.0;
    double dx = imagex/2.0-dcx;
    double dy = imagey/2.0-dcy;

    int width=static_cast<int>(round(imagex));
    int height=static_cast<int>(round(imagey));

    img::EasyImage result(width,height,backgroundColor);
    ZBuffer zbuffer= ZBuffer(width,height);


    for(lines_2D line: lines){
        line.p1.x*=d;
        line.p1.y*=d;
        line.p2.x*=d;
        line.p2.y*=d;

        line.p1.x+=dx;
        line.p1.y+=dy;
        line.p2.x+=dx;
        line.p2.y+=dy;

        int x0=static_cast<int>(round(line.p1.x));
        int y0=static_cast<int>(round(line.p1.y));
        int x1=static_cast<int>(round(line.p2.x));
        int y1=static_cast<int>(round(line.p2.y));


        img::Color color(static_cast<int>(round(line.color.red*255)),static_cast<int>(round(line.color.green*255)),static_cast<int>(round(line.color.blue*255)));
        if(zbuff){
            zbuffer.draw_zbuf_line(zbuffer,result,x0,y0,line.z1,x1,y1,line.z2,color);
        }
        else{
            result.draw_line(static_cast<int>(round(line.p1.x)),static_cast<int>(round(line.p1.y)),static_cast<int>(round(line.p2.x)),static_cast<int>(round(line.p2.y)),color);
        }
    }
    return result;
}
Lines2D drawLSystem(const LParser::LSystem2D &l_system, Color kleur){
    Lines2D lines= {};
    string initiator = l_system.get_initiator();
    set<char> alphabet = l_system.get_alphabet();
    double angle=l_system.get_angle()/180.0*M_PI;
    double startingAngle=l_system.get_starting_angle()/180.0*M_PI;
    unsigned int iterations = l_system.get_nr_iterations();

    for (int i = 0; i < iterations; ++i) {
        string replaced = "";
        for(char a: initiator){
            if(a=='('||a==')'||a=='+' ||a=='-'){
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
    Point2D punt;punt.x=0;punt.y=0;
    addLines(l_system,lines,punt,angle,startingAngle,initiator,kleur);
    return lines;
}

void addLines(const LParser::LSystem2D &l_system, Lines2D &lines, Point2D location,double angle, double startingAngle, string &iterator, Color color){
    for(int i=0; i<iterator.size();i++){
        char a=iterator[i];
        if(a=='+'){
            startingAngle+=angle;
        }
        else if(a=='-'){
            startingAngle-=angle;
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
                        addLines(l_system,lines,location,angle,startingAngle, tussenhaken, color);
                        addLines(l_system,lines,location,angle,startingAngle, resterend, color);
                        return;
                    } else{
                        counter --;
                    }
                }

            }
        }
        else{
            Point2D destination;
            destination.x=location.x+cos(startingAngle);
            destination.y=location.y+sin(startingAngle);
            if(l_system.draw(a)){
                lines_2D line; line.p1=location; line.p2 = destination; line.color = color;
                lines.push_back(line);
            }
            location = destination;
        }
    }
}