#ifndef RAY_H
#define RAY_H
#include <utility>
#include <vector> 
#include "tuples.h"

class Ray
{
    private:
        Tuple origin;
        Tuple direction;
    public:
        Ray(Tuple origin, Tuple direction);
        Tuple getOrigin();
        Tuple getDirection();
        Tuple position(double);
    

};


namespace Shapes
{
    class Shape 
    {   
        protected:
            static inline unsigned int id = 0; 
            unsigned int current_id;
        public:
            virtual std::pair< std::pair<double, double>, int> intersect(Ray ray) = 0;
            unsigned int getId();
    };

    


    class Sphere : public Shape
    {
       
    public:
        Sphere();
        std::pair< std::pair<double, double>, int>intersect(Ray ray);
        
    };

    struct intersection{
        double t;
        Shape& object;
    };
    struct intersections{
        std::vector<intersection> list;
        double operator[](int i);
        
    };
    
}


#endif