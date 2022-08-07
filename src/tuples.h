#ifndef TUPLES_H
#define TUPLES_H

class Tuple
{
protected: 
    double x{}; double y{}; double z{}; double w{};
public:
    Tuple(double x, double y, double z, double w); 
    Tuple();
    inline double get_x() const {return x;}
    inline double get_y() const{return y;}
    inline double get_z() const{return z;}
    inline double get_w() const{return w;} // Read only access for w as it determines state
    inline void set_x(double x){this->x = x;}
    inline void set_y(double y){this->y = y;}
    inline void set_z(double z){this->z = z;}
    inline void set_w(double w){this->w = w;}
    bool operator==(const Tuple& rhs) const;
    Tuple operator-() const;
    Tuple operator-(const Tuple& rhs) const;
    Tuple operator+(const Tuple& rhs) const;
    Tuple operator*(const double val) const;
    Tuple operator/(const double val) const;
    
    
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
    Color(double, double, double);
    Color();
    inline double red() const{return r;}
    inline double green()const {return g;}
    inline double blue() const{return b;}
    inline void set_r(double r){this->r = r;}
    inline void set_g(double g){this->g = g;}
    inline void set_b(double b){this->b = b;}
    Color operator/(const double val) const;
    Color operator/(const Color b) const;
    Color operator*(const double val) const;
    Color operator*(const Color b) const;
    Color operator+(const double val) const;
    Color operator+(const Color b) const;
    Color operator-(const double val) const;
    Color operator-(const Color b) const;
    bool operator==(const Color& rhs) const;
};

namespace tuples{

    extern const Tuple ZERO;
    Tuple point(double x, double y, double z);
    Tuple vector(double x, double y, double z);
    Tuple add(Tuple a, Tuple b);
    Tuple subtract(Tuple a, Tuple b);
    Tuple negate(Tuple a);
    Tuple multiply(const Tuple& a, double scale);
    Tuple divide(const Tuple& a, double scale);
    double magnitude(const Tuple& a);
    Tuple normalise(const Tuple& a);
    double dot(Tuple a, Tuple b); //Change to reference
    Tuple cross(Tuple a, Tuple b);
    Tuple reflect(Tuple, Tuple); //Change to reference



}


#endif