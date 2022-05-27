#include<iostream>
#include "tuples.h"
#include "math.h"

Tuple::Tuple(double x, double y, double z, double w):
    x{x}, 
    y{y},
    z{z},
    w{w}

{
    
}
Tuple::Tuple():
    x{0}, 
    y{0},
    z{0},
    w{-1}
{

}



Tuple tuples::point(double x, double y, double z)
{ 
    return Tuple{x, y, z, 1.0};
}

Tuple tuples::vector(double x, double y, double z)
{
    return Tuple{x, y, z, 0.0};
}

Tuple tuples::add(Tuple a, Tuple b)
{
    
    double x_1 = a.get_x() + b.get_x();
    double y_1 = a.get_y() + b.get_y();
    double z_1 = a.get_z() + b.get_z();
    double w_1 = a.get_w() + b.get_w();
    if(w_1 == 2){
        throw std::invalid_argument("Adding two points");
    }
    return Tuple(x_1, y_1, z_1, w_1);
}

Tuple tuples::subtract(Tuple a, Tuple b)
{

    double x_1 = a.get_x() - b.get_x();
    double y_1 = a.get_y() - b.get_y();
    double z_1 = a.get_z() - b.get_z();
    double w_1 = a.get_w() - b.get_w();
    if(w_1 == -1){
        throw std::invalid_argument("Subtracting a point from a vector");
    }
    return Tuple(x_1, y_1, z_1, w_1);

}
Tuple& tuples::negate(Tuple& a)
{

    a.set_x(-a.get_x());
    a.set_y(-a.get_y());
    a.set_z(-a.get_z());
    a.set_w(-a.get_w());
    return a;

}

Tuple& tuples::multiply(Tuple& a, double scale)
{
    a.set_x(a.get_x()*scale);
    a.set_y(a.get_y()*scale);
    a.set_z(a.get_z()*scale);
    a.set_w(a.get_w()*scale);
    return a;
}
Tuple& tuples::divide(Tuple& a, double scale)
{
    if(scale == 0)
    {
        throw std::invalid_argument("Dividing by Zero");
    }
    a.set_x(a.get_x()/scale);
    a.set_y(a.get_y()/scale);
    a.set_z(a.get_z()/scale);
    a.set_w(a.get_w()/scale);
    return a;
}

double tuples::magnitude(Tuple& a)
{
    return sqrt((a.get_x()*a.get_x()) +  (a.get_y()*a.get_y()) + (a.get_z()*a.get_z()) + (a.get_w()*a.get_w()));
}
Tuple& tuples::normalise(Tuple& a)
{
    double scale{magnitude(a)};
    if(scale==0){
        throw std::invalid_argument("Cannot Normalize ZERO");
    }
    return tuples::divide(a, scale);
}

double tuples::dot(Tuple a, Tuple b)
{
    if(a.get_w() == 1 || b.get_w() == 1)
    {
        throw std::invalid_argument("Cannot dot two points");
    }
    return (a.get_x()*b.get_x() +  a.get_y()*b.get_y() + a.get_z()*b.get_z() + a.get_w()*b.get_w());
}
Tuple tuples::cross(Tuple a, Tuple b){
    return vector(
    a.get_y()*b.get_z() - a.get_z()*b.get_y(),
    a.get_z() * b.get_x() - a.get_x() * b.get_z(),
    a.get_x() * b.get_y() - a.get_y() * b.get_x()
    
    );   
}
Color::Color(double r, double g, double b):
    r{r}, g{g}, b{b}
{
    
}


Color::Color():
    r{0}, g{0}, b{0}
{

}
    
Color color::c_add(Color a, Color b)
{
    return Color(a.red()+b.red(), a.green()+b.green(), a.blue()+b.blue());
}
Color color::c_sub(Color a, Color b)
{
    return Color(a.red()-b.red(), a.green()-b.green(), a.blue()-b.blue());

}
Color& color::c_mult(Color& a, double scale)
{
    a.set_r(a.red()*scale);
    a.set_g(a.green()*scale);
    a.set_b(a.blue()*scale);
    return a;
}
Color color::h_prod(Color a, Color b)
{
    return Color(a.red()*b.red(), a.green()*b.green(), a.blue()*b.blue());
}


/*
//DEMO FOR TESTNG TUPLES CLASS

struct Proj{
    Tuple position;
    Tuple velocity;
};
struct Env{
    Tuple gravity;
    Tuple wind;
    
};
Proj& tick(Env& env, Proj& proj){
    
    proj.position = tuples::add(proj.position, proj.velocity);
    proj.velocity = tuples::add(tuples::add(proj.velocity, env.gravity), env.wind);
    return proj;
}

int main(){
    Proj p;
    p.position = tuples::point(0,1,0);
    Tuple vVect = tuples::vector(1,1,0);
    p.velocity = tuples::normalise(vVect);
    Env e;
    e.gravity = tuples::vector(0, -0.1, 0);
    e.wind = tuples::vector(-0.1, 0, 0);
    int i{};
    while(p.position.get_y() > 0)
    {
        tick(e, p);
        std::cout<<p.position.get_y()<<std::endl;
        i++;
    }
    std::cout<<i<<std::endl;
}
*/
