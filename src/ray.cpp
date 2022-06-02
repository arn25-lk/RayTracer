#include "ray.h"
#include "tuples.h"
#include <utility>
#include <cmath>

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
    std::pair< std::pair<double, double>, int>  Sphere::intersect(Ray ray)
    {
        std::pair<double, double> collisions;
        int count = 0;
        Tuple origin = ray.getOrigin();
        Tuple sphereToRay = tuples::subtract(ray.getOrigin(), tuples::ZERO);
        Tuple direction = ray.getDirection();
        double a = tuples::dot(direction, direction);
        double b = 2 * tuples::dot(direction, sphereToRay);
        double c = tuples::dot(sphereToRay, sphereToRay) - 1;

        double discriminant = b * b - 4 * a * c;
        if (discriminant < 0)
        {
            collisions.first = -1;
            collisions.second = -1;
        }
        else
        {
            double t1 = (-b - sqrt(discriminant)) / (2 * a);
            double t2 = (-b + sqrt(discriminant)) / (2 * a);
            count = 2;
            if (t1 > t2)
            {
                collisions.first = t2;
                collisions.second = t1;
            }
            else
            {
                collisions.first = t1;
                collisions.second = t2;
            }
        }
        std::pair< std::pair<double, double>, int > result;
        result.first = collisions;
        result.second = count;
        return result;
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
}