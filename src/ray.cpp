#include "ray.h"
#include "tuples.h"
#include <utility>
#include <cmath>
#include <algorithm>
#include <float.h>
#include <memory>

Ray::Ray(Tuple origin, Tuple direction)
{
    this->origin = origin;
    this->direction = direction;
}
Tuple Ray::position(double t)
{
    return tuples::add(this->origin, tuples::multiply(this->direction, t));
}
Tuple Ray::getOrigin()
{
    return this->origin;
}
Tuple Ray::getDirection()
{
    return this->direction;
}


namespace Shapes 
{
    Intersections Sphere::intersect(Ray ray)
    {
        Intersections collisions;
        int count = 0;
        Tuple origin = ray.getOrigin();
        Tuple sphereToRay = tuples::subtract(ray.getOrigin(), tuples::ZERO);
        Tuple direction = ray.getDirection();
        double a = tuples::dot(direction, direction);
        double b = 2 * tuples::dot(direction, sphereToRay);
        double c = tuples::dot(sphereToRay, sphereToRay) - 1;

        double discriminant = b * b - 4 * a * c;
        if (discriminant >= 0)
        {
            double t1 = (double) (-b - sqrt(discriminant)) / (2 * a);
            double t2 = (double) (-b + sqrt(discriminant)) / (2 * a);
            count = 2;
            if (t1 != t2)
            {

                Intersection i1{std::min(t1,t2), *this};
                Intersection i2{std::max(t1,t2), *this};
                collisions.add(i1);
                collisions.add(i2);
            }
            else 
            {
                Intersection i1{t1, *this};
                collisions.add(i1);
            }
        }

        return collisions;
    }
    Sphere::Sphere()
    {
        current_id = id;
        id++;
    }
    unsigned int Shape::getId()
    {
        return current_id;
    }
    Intersection::Intersection(double t, Shape& object) : object(object), t(t)
    {

    }


    std::unique_ptr<Intersection>& Intersections::operator[](int i)
    {
        return list[i];
    }

    void Intersections::add(Intersection& i)
    {
        auto p = std::make_unique<Intersection>(i);
        list.push_back(std::move(p));
    }
    int Intersections::getCount()
    {
        return list.size();
    }
    
    std::unique_ptr<Intersection> hit(Intersections& it)
    {
        double min_len = DBL_MAX;
        int min_index = -1;
        for(int i = 0; i < it.list.size(); i++){
            auto const& current_intersection = it[i];
            
            if(current_intersection->t <= min_len && current_intersection->t >= 0){
                min_len = current_intersection->t;
                min_index = i;
            }
        }
        if(min_index != -1){
            return std::move(it[min_index]);
        }else{
            return nullptr;
        }
        

    }
}
