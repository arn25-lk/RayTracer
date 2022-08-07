#ifndef RAY_H
#define RAY_H
#include <utility>
#include <vector> 
#include "tuples.h"
#include "matrix.h"
#include <memory>
#include "reflection.h"

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
        Ray transform(Matrix);

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
            static unsigned int id;
            unsigned int current_id;
            Matrix transform;// = IDENTITY_MATRIX;
        public:
            Shape();
            Material material;
            virtual Intersections intersect(Ray ray) = 0;
            virtual Tuple normalAt(Tuple) = 0;
            unsigned int getId();
            Matrix getTransform();
            void setTransform(Matrix);
            
    };

    


    class Sphere : public Shape
    {
    public:
        Sphere();
        Intersections intersect(Ray ray);
        Tuple normalAt(Tuple);

        
    };

    
    

    
}


#endif