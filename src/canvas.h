#ifndef CANVAS_H
#define CANVAS_H
#include "tuples.h"

class Canvas 
{
private:
    unsigned int width, height;
    
public:
    Canvas(unsigned int width, unsigned int height);
    Color** canvas;
    
    inline int getWidth() const {return width;}
    inline int getHeight() const {return height;}
    void write_pixel(int w, int h, Color c);
    int canvas_to_ppm();
};
namespace canvas
{
    

}
#endif