#include "tuples.h"
#include "canvas.h"
#include <fstream>
#include <iostream>

Canvas::Canvas(unsigned int width, unsigned int height):
height{height}, width{width}
{
    Color** canvas = new Color* [height];
    for(int i=0; i < height; i++)
    {
        Color* row = new Color[width];
        for(int j=0; j < width; j++)
        {
            row[j] = Color(); 
        }
        canvas[i] = row;
    }
    this->canvas = canvas;
}

//Can pass arrays as a pointer/ compile-time length or unspecified length

void Canvas::write_pixel(int w, int h, Color c)
{
    if((w>=0 && w<=this->getWidth()-1) && (h>=0 && h<=this->getHeight()-1))
    {
        this->canvas[h][w] = c;
    }
    

}

int scale_color(double c)
{
    if(c < 0)
    {
        return 0;
    }else if(c > 1)
    {
        return 255;
    }else
    {
        return int((c*255));
    }
}

int Canvas::canvas_to_ppm()
{
    std::ofstream fs("/Users/arnav25/Desktop/3D_Renderer/src/out.ppm",std::ios_base::out | std::ios_base::binary);
    if(!fs.is_open()){
        std::cout<<"ERROR opening file\n";
    }
    fs<<"P3\n"<<this->getWidth()<<" "<<this->getHeight()<<"\n255\n";
    for(int i=0; i < this->getHeight(); i++)
    {
        for(int j=0; j<this->getWidth(); j++)
        {
            Color temp = this->canvas[i][j];
            fs<<scale_color(temp.red()) << ' ' << scale_color(temp.green()) << ' ' << scale_color(temp.blue()) << "\n";
        }
    }
    fs.close();
    return 0;
}

struct Proj{
    Tuple position;
    Tuple velocity;
};
struct Env{
    Tuple gravity;
    Tuple wind;
    
};
Proj& tick(Env& env, Proj& proj, Canvas& c){
    c.write_pixel((int)proj.position.get_x(), c.getHeight()-((int)proj.position.get_y()), Color(1,0,0));
    
    proj.position = tuples::add(proj.position, proj.velocity);
    proj.velocity = tuples::add(tuples::add(proj.velocity, env.gravity), env.wind);
    return proj;
}

int main(){
    Proj p;
    Canvas* canv = new Canvas(900,550);
    p.position = tuples::point(0,1,0);
    Tuple vVect = tuples::vector(1,1.8,0);
    p.velocity = tuples::multiply(tuples::normalise(vVect),11.25);
    Env e;
    e.gravity = tuples::vector(0, -0.1, 0);
    e.wind = tuples::vector(-0.01, 0, 0);
    int i{};
    std::cout<<canv->getHeight()<<' '<< canv->getWidth()<<std::endl;
    while(p.position.get_y() > 0) 
    {
        tick(e, p, *canv);
        std::cout<<p.position.get_x()<< ' ' << p.position.get_y() <<' ' <<std::endl;
        
        i++;
    }
    std::cout<<canv->canvas[540][5].red();
    canv->canvas_to_ppm();
    
    delete canv;
    std::cout<<i<<std::endl;
}

