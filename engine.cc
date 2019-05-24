#include "easy_image.h"
#include "ini_configuration.h"
#include "L2D_systemen.h"

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include "Line_drawings_3D.h";
#include "Figure3D.h"
#include "Lsystemen_3D.h"
#include "ZBuffer.h"

using namespace std;



img::EasyImage generate_image(const ini::Configuration &configuration)
{
    string type = configuration["General"]["type"].as_string_or_die();
    int size=configuration["General"]["size"].as_int_or_die();
    vector<double> rgbValue = configuration["General"]["backgroundcolor"].as_double_tuple_or_die();
    img::Color backgroundColor((int)(rgbValue[0]*255 + 0.5),(int)(rgbValue[1]*255 + 0.5), (int)(rgbValue[2]*255 + 0.5));
    Lines2D lines;
    if(type=="2DLSystem"){
        LParser::LSystem2D l_system;
        std::ifstream input_stream(configuration["2DLSystem"]["inputfile"]);
        input_stream >> l_system;
        input_stream.close();
        vector<double> rgbKleur = configuration["2DLSystem"]["color"].as_double_tuple_or_die();
        Color kleur;kleur.red=rgbKleur[0];kleur.green=rgbKleur[1];kleur.blue=rgbKleur[2];
        lines=drawLSystem(l_system,kleur);
    }

    if(type=="Wireframe"||type=="ZBufferedWireframe"){
        Line_drawings_3D result;
        Figures3D figures3D;
        int nrFigures= configuration["General"]["nrFigures"].as_int_or_die();
        for (int i = 0; i <nrFigures ; ++i) {
            if(configuration["Figure"+to_string(i)]["type"].as_string_or_die()=="3DLSystem"){
                LParser::LSystem3D l_system;
                std::ifstream input_stream(configuration["Figure"+to_string(i)]["inputfile"]);
                input_stream >> l_system;
                input_stream.close();
                Figure newFigure=lsysteem3D(l_system,"Figure"+to_string(i));
                vector<double> rgbKleur = configuration["Figure"+to_string(i)]["color"].as_double_tuple_or_die();
                Color kleurlijn;kleurlijn.red=rgbKleur[0];kleurlijn.green=rgbKleur[1];kleurlijn.blue=rgbKleur[2];
                newFigure.color=kleurlijn;
                result.fixFigure(figures3D,newFigure,configuration,i);
            }
            if(configuration["Figure"+to_string(i)]["type"].as_string_or_die()=="Cube"){
                Figure newFigure=createCube();
                vector<double> rgbKleur = configuration["Figure"+to_string(i)]["color"].as_double_tuple_or_die();
                Color kleurlijn;kleurlijn.red=rgbKleur[0];kleurlijn.green=rgbKleur[1];kleurlijn.blue=rgbKleur[2];
                newFigure.color=kleurlijn;
                result.fixFigure(figures3D,newFigure,configuration,i);
            }
            if(configuration["Figure"+to_string(i)]["type"].as_string_or_die()=="Tetrahedron"){
                Figure newFigure=createTetrahedron();
                vector<double> rgbKleur = configuration["Figure"+to_string(i)]["color"].as_double_tuple_or_die();
                Color kleurlijn;kleurlijn.red=rgbKleur[0];kleurlijn.green=rgbKleur[1];kleurlijn.blue=rgbKleur[2];
                newFigure.color=kleurlijn;
                result.fixFigure(figures3D,newFigure,configuration,i);
            }
            if(configuration["Figure"+to_string(i)]["type"].as_string_or_die()=="Octahedron"){
                Figure newFigure=createOctahedron();
                vector<double> rgbKleur = configuration["Figure"+to_string(i)]["color"].as_double_tuple_or_die();
                Color kleurlijn;kleurlijn.red=rgbKleur[0];kleurlijn.green=rgbKleur[1];kleurlijn.blue=rgbKleur[2];
                newFigure.color=kleurlijn;
                result.fixFigure(figures3D,newFigure,configuration,i);
            }
            if(configuration["Figure"+to_string(i)]["type"].as_string_or_die()=="Icosahedron"){
                Figure newFigure=createIcosahedron();
                vector<double> rgbKleur = configuration["Figure"+to_string(i)]["color"].as_double_tuple_or_die();
                Color kleurlijn;kleurlijn.red=rgbKleur[0];kleurlijn.green=rgbKleur[1];kleurlijn.blue=rgbKleur[2];
                newFigure.color=kleurlijn;
                result.fixFigure(figures3D,newFigure,configuration,i);
            }
            if(configuration["Figure"+to_string(i)]["type"].as_string_or_die()=="Dodecahedron"){
                Figure newFigure=createDodecahedron();
                vector<double> rgbKleur = configuration["Figure"+to_string(i)]["color"].as_double_tuple_or_die();
                Color kleurlijn;kleurlijn.red=rgbKleur[0];kleurlijn.green=rgbKleur[1];kleurlijn.blue=rgbKleur[2];
                newFigure.color=kleurlijn;
                result.fixFigure(figures3D,newFigure,configuration,i);
            }
            if(configuration["Figure"+to_string(i)]["type"].as_string_or_die()=="Sphere"){
                const int n=configuration["Figure"+to_string(i)]["n"].as_int_or_die();
                Figure newFigure=createBol(1.0,n);
                vector<double> rgbKleur = configuration["Figure"+to_string(i)]["color"].as_double_tuple_or_die();
                Color kleurlijn;kleurlijn.red=rgbKleur[0];kleurlijn.green=rgbKleur[1];kleurlijn.blue=rgbKleur[2];
                newFigure.color=kleurlijn;
                result.fixFigure(figures3D,newFigure,configuration,i);
            }
            if(configuration["Figure"+to_string(i)]["type"].as_string_or_die()=="Cone"){
                const int n=configuration["Figure"+to_string(i)]["n"].as_int_or_die();
                const double height=configuration["Figure"+to_string(i)]["height"].as_double_or_die();
                Figure newFigure=createKegel(n,height);
                vector<double> rgbKleur = configuration["Figure"+to_string(i)]["color"].as_double_tuple_or_die();
                Color kleurlijn;kleurlijn.red=rgbKleur[0];kleurlijn.green=rgbKleur[1];kleurlijn.blue=rgbKleur[2];
                newFigure.color=kleurlijn;
                result.fixFigure(figures3D,newFigure,configuration,i);
            }
            if(configuration["Figure"+to_string(i)]["type"].as_string_or_die()=="Cylinder"){
                const int n=configuration["Figure"+to_string(i)]["n"].as_int_or_die();
                const double height=configuration["Figure"+to_string(i)]["height"].as_double_or_die();
                Figure newFigure=createCilinder(n,height);
                vector<double> rgbKleur = configuration["Figure"+to_string(i)]["color"].as_double_tuple_or_die();
                Color kleurlijn;kleurlijn.red=rgbKleur[0];kleurlijn.green=rgbKleur[1];kleurlijn.blue=rgbKleur[2];
                newFigure.color=kleurlijn;
                result.fixFigure(figures3D,newFigure,configuration,i);
            }
            if(configuration["Figure"+to_string(i)]["type"].as_string_or_die()=="Torus"){
                const double r=configuration["Figure"+to_string(i)]["r"].as_double_or_die();
                const double R=configuration["Figure"+to_string(i)]["R"].as_double_or_die();
                const int n=configuration["Figure"+to_string(i)]["n"].as_int_or_die();
                const int m=configuration["Figure"+to_string(i)]["m"].as_int_or_die();
                Figure newFigure=createTorus(r,R,n,m);
                vector<double> rgbKleur = configuration["Figure"+to_string(i)]["color"].as_double_tuple_or_die();
                Color kleurlijn;kleurlijn.red=rgbKleur[0];kleurlijn.green=rgbKleur[1];kleurlijn.blue=rgbKleur[2];
                newFigure.color=kleurlijn;
                result.fixFigure(figures3D,newFigure,configuration,i);
            }

            if(configuration["Figure"+to_string(i)]["type"].as_string_or_die()=="LineDrawing"){
                Figure newFigure;
                int nrLines=configuration["Figure"+to_string(i)]["nrLines"].as_int_or_die();
                int nrPoints=configuration["Figure"+to_string(i)]["nrPoints"].as_int_or_die();
                vector<double> rgbKleur = configuration["Figure"+to_string(i)]["color"].as_double_tuple_or_die();
                Color kleurlijn;kleurlijn.red=rgbKleur[0];kleurlijn.green=rgbKleur[1];kleurlijn.blue=rgbKleur[2];
                newFigure.color=kleurlijn;
                for (int j = 0; j < nrPoints ; ++j) {
                    vector<double> points=configuration["Figure"+to_string(i)]["point"+to_string(j)].as_double_tuple_or_die();
                    Vector3D newPoint=Vector3D::point(points[0],points[1],points[2]);
                    newFigure.points.push_back(newPoint);
                }
                for (int k = 0; k <nrLines ; ++k) {
                    vector<int> lines=configuration["Figure"+to_string(i)]["line"+to_string(k)].as_int_tuple_or_die();
                    Face newFace;
                    for(int point:lines){
                        newFace.point_indexes.push_back(point);
                    }
                    newFigure.faces.push_back(newFace);
                }
                result.fixFigure(figures3D,newFigure,configuration,i);
            }
        }
        vector<double>eyePoints=configuration["General"]["eye"].as_double_tuple_or_die();
        const Vector3D eyePoint=Vector3D::point(eyePoints[0],eyePoints[1],eyePoints[2]);
        Matrix eyePointMatrix=result.eyePointTrans(eyePoint);
        for (Figure& figure:figures3D){
            result.applyTransformation(figure,eyePointMatrix);
        }

        lines=result.doProjection(figures3D);
    }
    if(type=="ZBufferedWireframe"){
        return draw2DLines(lines,size,backgroundColor, true);

    }

	return draw2DLines(lines,size,backgroundColor, false);
}

int main(int argc, char const* argv[])
{
        int retVal = 0;
        try
        {
                for(int i = 1; i < argc; ++i)
                {
                        ini::Configuration conf;
                        try
                        {
                                std::ifstream fin(argv[i]);
                                fin >> conf;
                                fin.close();
                        }
                        catch(ini::ParseException& ex)
                        {
                                std::cerr << "Error parsing file: " << argv[i] << ": " << ex.what() << std::endl;
                                retVal = 1;
                                continue;
                        }

                        img::EasyImage image = generate_image(conf);
                        if(image.get_height() > 0 && image.get_width() > 0)
                        {
                                std::string fileName(argv[i]);
                                std::string::size_type pos = fileName.rfind('.');
                                if(pos == std::string::npos)
                                {
                                        //filename does not contain a '.' --> append a '.bmp' suffix
                                        fileName += ".bmp";
                                }
                                else
                                {
                                        fileName = fileName.substr(0,pos) + ".bmp";
                                }
                                try
                                {
                                        std::ofstream f_out(fileName.c_str(),std::ios::trunc | std::ios::out | std::ios::binary);
                                        f_out << image;

                                }
                                catch(std::exception& ex)
                                {
                                        std::cerr << "Failed to write image to file: " << ex.what() << std::endl;
                                        retVal = 1;
                                }
                        }
                        else
                        {
                                std::cout << "Could not generate image for " << argv[i] << std::endl;
                        }
                }
        }
        catch(const std::bad_alloc &exception)
        {
    		//When you run out of memory this exception is thrown. When this happens the return value of the program MUST be '100'.
    		//Basically this return value tells our automated test scripts to run your engine on a pc with more memory.
    		//(Unless of course you are already consuming the maximum allowed amount of memory)
    		//If your engine does NOT adhere to this requirement you risk losing points because then our scripts will
		//mark the test as failed while in reality it just needed a bit more memory
                std::cerr << "Error: insufficient memory" << std::endl;
                retVal = 100;
        }
        return retVal;
}
