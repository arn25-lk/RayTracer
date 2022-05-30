#ifndef TUPLES_H
#define TUPLES_H

class Tuple
{
protected: 
    double x{}; double y{}; double z{}; double w{};
public:
    Tuple(double x, double y, double z, double w); 
    Tuple();
    inline double get_x(){return x;}
    inline double get_y(){return y;}
    inline double get_z(){return z;}
    inline double get_w(){return w;} // Read only access for w as it determines state
    inline void set_x(double x){this->x = x;}
    inline void set_y(double y){this->y = y;}
    inline void set_z(double z){this->z = z;}
    inline void set_w(double w){this->w = w;}
    
    
};

// class Color : public Tuple{
// private: 
    
// public: 
//     Color(double r, double g, double b);
//     Color();
//     inline double red(){return x;}
//     inline double green(){return y;}
//     inline double blue(){return z;}
    
// };

class Color {
private: 
    double r, g, b;
public:
    Color(double r, double g, double b);
    Color();
    inline double red(){return r;}
    inline double green(){return g;}
    inline double blue(){return b;}
    inline void set_r(double r){this->r = r;}
    inline void set_g(double g){this->g = g;}
    inline void set_b(double b){this->b = b;}

    
};

namespace tuples{

extern const Tuple ZERO;
Tuple point(double x, double y, double z);
Tuple vector(double x, double y, double z);
Tuple add(Tuple a, Tuple b);
Tuple subtract(Tuple a, Tuple b);
Tuple& negate(Tuple& a);
Tuple& multiply(Tuple& a, double scale);
Tuple& divide(Tuple& a, double scale);
double magnitude(Tuple& a);
Tuple& normalise(Tuple& a);
double dot(Tuple a, Tuple b);
Tuple cross(Tuple a, Tuple b);

}
namespace color{
Color c_add(Color a, Color b);
Color c_sub(Color a, Color b);
Color& c_mult(Color& a, double scale);
Color h_prod(Color a, Color b);
}

#endif