#include "../src/reflection.h"
#include "../src/tuples.h"
#include "../src/matrix.h"
#include "../src/ray.h"
#include "../src/canvas.h"
#include<gtest/gtest.h>

/*Scenario: A point light has a position and intensity Given intensity ← color(1, 1, 1)
And position ← point(0, 0, 0)
When light ← point_light(position, intensity) Then light.position = position
And light.intensity = intensity*/

TEST(LightsFeature, PointLightProperties)
{
    Color intensity{1,1,1};
    auto position = tuples::point(0,0,0);
    auto light = PointLight();
    light.intensity = intensity;
    light.position = position;
    ASSERT_EQ(light.position,  position);
    ASSERT_EQ(light.intensity,  intensity);

}

/*
Scenario: The default material Given m ← material()
Then m.color = color(1, 1, 1)
And m.ambient = 0.1
And m.diffuse = 0.9
And m.specular = 0.9 And m.shininess = 200.0
*/

TEST(MaterialFeature, MaterialShape1)
{
    auto m = Material();
    ASSERT_EQ(m.getColor(), Color(1,1,1));
    ASSERT_EQ(m.getDiffuse(), 0.9);
    ASSERT_EQ(m.getSpecular(), 0.9);
    ASSERT_EQ(m.getAmbient(), 0.1);
    ASSERT_EQ(m.getShininess(), 200.0);
}

TEST(MaterialFeature, MaterialShape2)
{
    Shapes::Sphere s{};
    auto m = Material();
    m.setAmbient(1);
    s.material = m;
    ASSERT_EQ(1,  s.material.getAmbient());
    ASSERT_EQ(s.material.getDiffuse(), 0.9);
    ASSERT_EQ(s.material.getSpecular(), 0.9);
    ASSERT_EQ(s.material.getShininess(), 200.0);
    
}

TEST(MaterialFeature, LightingWithEyeBetweenLightAndSurface)
{
    auto m = Material();
    auto position = tuples::point(0,0,0);
    auto eyev = tuples::vector(0,0,-1);
    auto normalv = tuples::vector(0,0,-1);
    auto light = PointLight();
    light.intensity = Color(1,1,1);
    light.position = tuples::point(0,0,-10);
    auto result = lighting(m, light, position, eyev, normalv);
    ASSERT_EQ(result.red(), 1.9);
    ASSERT_EQ(result.blue(), 1.9);
    ASSERT_EQ(result.green(), 1.9);
}