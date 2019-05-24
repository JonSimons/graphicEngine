

#include "ZBuffer.h"
#include <cmath>



ZBuffer::ZBuffer(const int width, const int height){
    double posInf=std::numeric_limits<double>::infinity();
    for(int x=0;x<width;x++){
        std::vector<double> row;
        for(int y=0;y<height;y++){
            row.push_back(posInf);
        }
        this->push_back(row);
    }
}

void ZBuffer::draw_zbuf_line(ZBuffer & zbuffer,img::EasyImage & image, unsigned int x0, unsigned int y0, double z0, unsigned int x1, unsigned int y1, double z1,const img::Color &color){
    if(x0==x1) {
        int a = max(y0, y1) - min(y0, y1);
        if (y1 < y0) {
            double save = z0;
            z0 = z1;
            z1 = save;
        }
        for (int j = min(y0,y1); j <= max(y0,y1); j++) {
            int i = max(y0,y1) - j;
            double z = (i / a) / z0 + (1 - (i / a)) / z1;
            if (z < zbuffer[x0][j]) {
                zbuffer[x0][j] = z;
                (image)(x0, j) = color;
            }
        }
    }
    if(y0==y1){
        int a=max(x0,x1)-min(x0,x1);
        if(x1<x0){
            int save= z0;
            z0=z1;
            z1=save;
        }
        for (int j =min(x0,x1) ; j <=max(y0,y1) ; ++j) {
            int i=max(x0,x1)-j;
            double z=(i/a)/z0+(1-(i/a))/z1;
            if(z<zbuffer[j][y0]){
                zbuffer[i][y0]=z;
                (image)(j,y0)=color;
            }
        }
    }
    if(x0>x1){
        int save=x0;
        x0=x1;
        x1=save;
        save=y0;
        y0=y1;
        y1=save;
        double save2=z0;
        z0=z1;
        z1=save2;
    }
    double rico=((y1-y0)/(x1-x0));
    if(-1.0 <=rico && rico<=1.0){
        int a=x1-x0;
        for (int j = 0; j <=(x1-x0) ; ++j) {
            int i=a-j;
            double z=((i/a)/z0+(1-(i/a)/z1));
            if(z<zbuffer[x0+j][round(y0+rico*j)]){
                zbuffer[x0+j][round(y0+rico*j)]=z;
                (image)(x0+j,round(y0+rico*j))=color;
            }
        }
    }
    if(rico>1.0){
        int a=y1-y0;
        for (int j = 0; j <=(y1-y0) ; ++j) {
            int i=a-j;
            double z=((i/a)/z0+(1-(i/a)/z1));
            if(z<zbuffer[round(x0+j/rico)][y0+j]){
                zbuffer[round(x0+j/rico)][y0+j]=z;
                (image)(round(x0+j/rico),y0+j)=color;
            }
        }
    }
    if(rico<-1.0){
        int a=y0-y1;
        for (int j = 0; j <=(y0-y1) ; ++j) {
            int i=a-j;
            double z=((i/a)/z0+(1-(i/a)/z1));
            if(z<zbuffer[round(x0-j/rico)][y0-j]){
                zbuffer[round(x0-j/rico)][y0-j]=z;
                (image)(round(x0-j/rico),y0-j)=color;
            }
        }
    }
}