#include<iostream>
#include "tuples.h"
#include <cmath>
#include "matrix.h"

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

const Tuple tuples::ZERO = Tuple{0.0,0.0,0.0,1.0};

Tuple tuples::point(double x, double y, double z)
{ 
    return Tuple{x, y, z, 1.0};
}

Tuple tuples::vector(double x, double y, double z)
{
    return Tuple{x, y, z, 0.0};
}
Tuple Tuple::operator-() const
{
    Tuple a{-this->get_x(), -this->get_y(), -this->get_z(), -this->get_w()};
    return a;
}
Tuple Tuple::operator-(const Tuple& b) const
{
    double x_1 = this->get_x() - b.get_x();
    double y_1 = this->get_y() - b.get_y();
    double z_1 = this->get_z() - b.get_z();
    double w_1 = this->get_w() - b.get_w();
    if(w_1 == -1){
        throw std::invalid_argument("Subtracting a point from a vector");
    }
    return Tuple(x_1, y_1, z_1, w_1);
}
Tuple Tuple::operator+(const Tuple& b) const
{
    double x_1 = this->get_x() + b.get_x();
    double y_1 = this->get_y() + b.get_y();
    double z_1 = this->get_z() + b.get_z();
    double w_1 = this->get_w() + b.get_w();
    if(w_1 == 2){
        throw std::invalid_argument("Adding two points");
    }
    return Tuple(x_1, y_1, z_1, w_1);
}
Tuple Tuple::operator*(const double scale) const
{
    Tuple result{this->get_x() * scale, this->get_y() * scale, this->get_z() * scale, this->get_w() * scale};
    return result;
}
Tuple Tuple::operator/(const double scale) const
{
    if(scale == 0)
    {
        throw std::invalid_argument("Dividing by Zero");
    }
    Tuple result{this->get_x() / scale, this->get_y() / scale, this->get_z() / scale, this->get_w() / scale};

    return result;
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
Tuple tuples::negate(Tuple a)
{

    Tuple t{-a.get_x(), -a.get_y(), -a.get_z(), -a.get_w()};
    return t;

}

Tuple tuples::multiply(const Tuple& a, double scale)
{
    Tuple result{a.get_x() * scale, a.get_y() * scale, a.get_z() * scale, a.get_w() * scale};
    return result;
}
Tuple tuples::divide(const Tuple& a, double scale)
{
    if(scale == 0)
    {
        throw std::invalid_argument("Dividing by Zero");
    }
    Tuple result{a.get_x() / scale, a.get_y() / scale, a.get_z() / scale, a.get_w() / scale};

    return result;
}

double tuples::magnitude(const Tuple& a)
{
    return sqrt((a.get_x()*a.get_x()) +  (a.get_y()*a.get_y()) + (a.get_z()*a.get_z()) + (a.get_w()*a.get_w()));
}
Tuple tuples::normalise(const Tuple& a)
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
Tuple tuples::cross(Tuple a, Tuple b)
{
    return vector(
    a.get_y()*b.get_z() - a.get_z()*b.get_y(),
    a.get_z() * b.get_x() - a.get_x() * b.get_z(),
    a.get_x() * b.get_y() - a.get_y() * b.get_x()
    
    );   
}

bool Tuple::operator==(const Tuple& rhs) const
{
    
    return util::approximatelyEqual(this->x, rhs.x, 0.0001) && 
    util::approximatelyEqual(this->y, rhs.y, 0.0001) &&
    util::approximatelyEqual(this->z, rhs.z, 0.0001) && 
    util::approximatelyEqual(this->w, rhs.w, 0.0001);
}
Tuple tuples::reflect(Tuple in, Tuple normal)
{
    // reflectedVector = in - normal * 2 * dot(in, normal)
    auto reflectedVector = tuples::multiply(normal, 2 * tuples::dot(in, normal));
    return tuples::subtract(in, reflectedVector); //in to normal
}
Color::Color(double r, double g, double b):
    r{r}, g{g}, b{b}
{
    
}


Color::Color():
    r{0}, g{0}, b{0}
{

}
    
/*Color color::c_add(Color a, Color b)
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
*/
Color Color::operator/(const double val) const
{
    Color c1{this->red() / val, this->green() / val, this->blue() / val};
    return c1;
}
Color Color::operator*(const double val) const
{
    Color c1{this->red() * val, this->green() * val, this->blue() * val};
    return c1;
}
Color Color::operator*(const Color b) const
{
    Color c1 {this->red() * b.red(), this->green() * b.green(), this->blue() * b.blue()};
    return c1;
}
Color Color::operator+(const double val) const
{
    Color c1{this->red() + val, this->green() + val, this->blue() + val};
    return c1;
}

Color Color::operator+(const Color b) const
{
    Color c1{this->red() + b.red(), this->green() + b.green(), this->blue() + b.blue()};
    return c1;
}
Color Color::operator-(const double val) const
{
    Color c1{this->red() - val, this->green() - val, this->blue() - val};
    return c1;
}
Color Color::operator-(const Color b) const
{
    Color c1{this->red() - b.red(), this->green() - b.green(), this->blue() - b.blue()};
    return c1;
}

bool Color::operator==(const Color& rhs) const
{
    
    return rhs.red() == this->red() && rhs.green() == this->green() && rhs.blue() == this->blue();
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
