
#ifndef GRAPHICENGINE_ZBUFFER_H
#define GRAPHICENGINE_ZBUFFER_H

#include <limits>
#include <vector>
#include "easy_image.h"
#include <math.h>

using namespace std;

class ZBuffer: public vector<vector<double>>{
    public:
        ZBuffer(const int width,const int height);
        void draw_zbuf_line(ZBuffer &zbuffer,img::EasyImage & image,
                             unsigned int x0, unsigned int y0, double z0,
                             unsigned int x1, unsigned int y1,
                             double z1,
                            const img::Color& color);
    };


#endif //GRAPHICENGINE_ZBUFFER_H
