#ifndef RAY_H
#define RAY_H
#include <utility>
#include <vector> 
#include "tuples.h"
#include <memory>

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
   
    class Shape;
    struct Intersection{
        double t;
        Shape& object;
        Intersection(double t, Shape& object);

        
    };
    struct Intersections{
        std::vector<std::unique_ptr<Intersection> > list;
        std::unique_ptr<Intersection>& operator[](int i);
        void add(Intersection& i);
        int getCount();
    };
    std::unique_ptr<Intersection> hit(Intersections& it);

    
    class Shape 
    {   
        protected:
            static inline unsigned int id = 0; 
            unsigned int current_id;
        public:
            virtual Intersections intersect(Ray ray) = 0;
            unsigned int getId();
    };

    


    class Sphere : public Shape
    {
       
    public:
        Sphere();
        Intersections intersect(Ray ray);
        
    };

    
    

    
}


#endif