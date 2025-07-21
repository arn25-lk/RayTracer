#include "reflection.h"
#include "tuples.h"
#include "matrix.h"
#include "ray.h"
#include "canvas.h"
#include <cmath>
#include <iostream>

Material::Material() : color(Color(1,1,1)), ambient(0.1), diffuse(0.9), specular(0.9), shininess(200.0)
{

}

Material::Material(Color color, double ambient, double diffuse, double specular, double shininess)
{
    this->color = color;
    this->ambient = ambient;
    this->diffuse = diffuse;
    this->specular = specular;
    this->shininess = shininess;
}
Color lighting(Material mat, PointLight light, Tuple point, Tuple eyev, Tuple normalv)
{
   const Color black{0,0,0};
   auto effective_color = mat.getColor()  * light.intensity;
   auto lightv = tuples::normalise(light.position - point);

   auto ambient = effective_color * mat.getAmbient();
   Color diffuse; Color specular;
   auto light_dot_normal = tuples::dot(lightv, normalv);
   
   if(light_dot_normal < 0)
   {   
        specular = black;
        diffuse = black;

   }else{
        diffuse = effective_color * mat.getDiffuse() * light_dot_normal;
        auto reflectv = tuples::reflect(tuples::negate(lightv), normalv);
        auto reflect_dot_eye = tuples::dot(reflectv, eyev);
        if (reflect_dot_eye <= 0)
        {
            specular = black;
        }else
        {
            auto factor = std::pow(reflect_dot_eye, mat.getShininess());
            specular = light.intensity * mat.getSpecular() * factor;
        }
   }
   
   return ambient + diffuse + specular;

}

// int main(){
//     auto ray_origin = tuples::point(0,0,-5);
//     int wall_z = 10;
//     double wall_size = 7;
//     unsigned int canvas_pixels = 300;
//     double pixel_size = wall_size / canvas_pixels;
//     double half = wall_size / 2;
//     Canvas can{canvas_pixels, canvas_pixels};
//     Color red{1,0,0};
//     Shapes::Sphere sphere{};
//     sphere.material.setColor(Color(1, 0.2, 1));
    
//     auto light = PointLight();
//     light.intensity = Color(1,1,1);
//     light.position = tuples::point(-10,-10,-10);
    
    
//     //auto transform = util::scaling(1,1.35,1) * util::shearing(1,0,0,0,0,0);
//     //sphere.setTransform(transform);
    
//     for(int y = 0; y < canvas_pixels; y++){
//         auto world_y = half - pixel_size * y;
//         for(int x = 0; x < canvas_pixels; x++){
//             auto world_x = -half + pixel_size * x;
//             auto position = tuples::point(world_x, world_y, wall_z);
//             Ray r{ray_origin, tuples::normalise(tuples::subtract(position, ray_origin))};
//             auto xs = sphere.intersect(r);
//             auto hitT = hit(xs);
//             if(hitT){
//                 auto point = r.position(hitT->t);
//                 auto normal = hitT->object.normalAt(point);
//                 auto eye = -r.getDirection();
//                 auto color = lighting(hitT->object.material, light, point, eye, normal);
//                 can.write_pixel(x, y, color);
//             }
//         }
//     }
//     if(!(can.canvas_to_ppm())) std::cout << "Print Successful" << std::endl;
//     return 0;
// }
