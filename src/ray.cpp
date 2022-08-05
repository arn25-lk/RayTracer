#include "ray.h"
#include "tuples.h"
#include "matrix.h"
#include "canvas.h"
#include <utility>
#include <cmath>
#include <algorithm>
#include <float.h>
#include <memory>
#include <iostream>


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

Ray Ray::transform(Matrix mat){
    auto n_origin = mat * this->origin;
    auto n_direction = mat * this->direction;
    Ray resultantRay{n_origin, n_direction};
    return resultantRay;
}


namespace Shapes 
{
    Intersections Sphere::intersect(Ray ray)
    {
        Intersections collisions;
        int count = 0;
        auto invertedTransformation = (this->getTransform()).inverse();
        auto rayN = ray.transform(invertedTransformation);
        Tuple origin = rayN.getOrigin();
        Tuple sphereToRay = tuples::subtract(rayN.getOrigin(), tuples::ZERO);
        Tuple direction = rayN.getDirection();
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
    unsigned int Shape::id = 0;
    Sphere::Sphere()
    {
        this->current_id = this->id;
        (this->id)++;
    }
    unsigned int Shape::getId()
    {
        return this->current_id;
    }
    Matrix Shape::getTransform()
    {
        return this->transform;
    }
    void Shape::setTransform(Matrix c)
    {
        this->transform = c;
    }
    //Input points only
    Tuple Sphere::normalAt(Tuple world_point){
        auto invTransform = (this->getTransform()).inverse();
        auto object_point = invTransform * world_point;
        auto object_normal = tuples::subtract(object_point, tuples::point(0,0,0));
        auto world_normal = invTransform.transpose() * object_normal;
        world_normal.set_w(0);
        return tuples::normalise(world_normal);
    } //fix
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

/*int main(){
    auto ray_origin = tuples::point(0,0,-5);
    int wall_z = 10;
    double wall_size = 7;
    unsigned int canvas_pixels = 100;
    double pixel_size = wall_size / canvas_pixels;
    double half = wall_size / 2;
    Canvas can{canvas_pixels, canvas_pixels};
    Color red{1,0,0};
    Shapes::Sphere sphere{};
    auto transform = util::scaling(1,0.5,1) * util::scaling(0.5,1,1) * util::shearing(1,0,0,0,0,0);
    sphere.setTransform(transform);
    for(int y = 0; y < canvas_pixels; y++){
        auto world_y = half - pixel_size * y;
        for(int x = 0; x < canvas_pixels; x++){
            auto world_x = -half + pixel_size * x;
            auto position = tuples::point(world_x, world_y, wall_z);
            Ray r{ray_origin, tuples::normalise(tuples::subtract(position, ray_origin))};
            auto xs = sphere.intersect(r);
            if(hit(xs)){
                can.write_pixel(x, y, red);
            }
        }
    }
    if(!(can.canvas_to_ppm())) std::cout << "Print Successful" << std::endl;
    return 0;
}*/
