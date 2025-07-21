#include "../src/reflection.h"
#include "../src/tuples.h"
#include "../src/matrix.h"
#include "../src/ray.h"
#include "../src/canvas.h"
#include<gtest/gtest.h>


TEST(IntegrationCheckpoint, SphereWithReflectionToCanvas)
{
    auto ray_origin = tuples::point(0,0,-5);
    int wall_z = 10;
    double wall_size = 7;
    unsigned int canvas_pixels = 300;
    double pixel_size = wall_size / canvas_pixels;
    double half = wall_size / 2;
    Canvas can{canvas_pixels, canvas_pixels};
    Color red{1,0,0};
    Shapes::Sphere sphere{};
    sphere.material.setColor(Color(1, 0.2, 1));
    auto light = PointLight();
    light.intensity = Color(1,1,1);
    light.position = tuples::point(-10,-10,-10);
    
    
    //auto transform = util::scaling(1,1.35,1) * util::shearing(1,0,0,0,0,0);
    //sphere.setTransform(transform);
    
    for(int y = 0; y < canvas_pixels; y++){
        auto world_y = half - pixel_size * y;
        for(int x = 0; x < canvas_pixels; x++){
            auto world_x = -half + pixel_size * x;
            auto position = tuples::point(world_x, world_y, wall_z);
            Ray r{ray_origin, tuples::normalise(tuples::subtract(position, ray_origin))};
            auto xs = sphere.intersect(r);
            auto hitT = hit(xs);
            if(hitT){
                auto point = r.position(hitT->t);
                auto normal = hitT->object.normalAt(point);
                auto eye = -r.getDirection();
                auto color = lighting(hitT->object.material, light, point, eye, normal);
                can.write_pixel(x, y, color);
            }
        }
    }
    if(!(can.canvas_to_ppm())) std::cout << "Print Successful" << std::endl;


}