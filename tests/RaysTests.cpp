#include "../src/ray.h"
#include<gtest/gtest.h>


TEST(RayInitTests, RayInit)
{

    Tuple origin = tuples::point(1, 2, 3);
    Tuple direction = tuples::vector(4, 5, 6);
    Ray ray{origin, direction};

    ASSERT_TRUE(origin == ray.getOrigin());
    ASSERT_TRUE(direction == ray.getDirection());
}

TEST(RayInitTests, RayInit2)
{
    
        Tuple origin = tuples::point(2, 3, 4);
        Tuple direction = tuples::vector(1, 0, 0);
        Ray ray{origin, direction};
        ASSERT_TRUE(ray.position(0) == tuples::point(2,3,4));
        ASSERT_TRUE(ray.position(1) == tuples::point(3,3,4));
        ASSERT_TRUE(ray.position(-1) == tuples::point(1,3,4));
        ASSERT_TRUE(ray.position(2.5) == tuples::point(4.5,3,4));

}
TEST(SphereTest, SphereIntersect1)
{
    Tuple origin = tuples::point(0, 0, -5);
    Tuple direction = tuples::vector(0, 0, 1);
    Ray ray{origin, direction};
    Shapes::Sphere sphere{};
    std::pair< std::pair<double, double>, int> count = sphere.intersect(ray);
    ASSERT_TRUE(count.first.first == 4.0);
    ASSERT_TRUE(count.first.second == 6.0);
    ASSERT_TRUE(count.second == 2);
}
TEST(SphereTest, SphereIntersect2)
{
    Tuple origin = tuples::point(0, 1, -5);
    Tuple direction = tuples::vector(0, 0, 1);
    Ray ray{origin, direction};
    Shapes::Sphere sphere{};
    std::pair< std::pair<double, double>, int> count = sphere.intersect(ray);
    ASSERT_TRUE(count.first.first == 5.0);
    ASSERT_TRUE(count.first.second == 5.0);
    ASSERT_TRUE(count.second == 2);
}

TEST(SphereTest, SphereIntersect3)
{
    Tuple origin = tuples::point(0, 2, -5);
    Tuple direction = tuples::vector(0, 0, 1);
    Ray ray{origin, direction};
    Shapes::Sphere sphere{};
    std::pair< std::pair<double, double>, int> count = sphere.intersect(ray);
    ASSERT_TRUE(count.first.first == -1.0);
    ASSERT_TRUE(count.first.second == -1.0);
    ASSERT_TRUE(count.second == 0);
}

TEST(SphereTest, SphereIntersect4)
{
    Tuple origin = tuples::point(0, 0, 0);
    Tuple direction = tuples::vector(0, 0, 1);
    Ray ray{origin, direction};
    Shapes::Sphere sphere{};
    std::pair< std::pair<double, double>, int> count = sphere.intersect(ray);
    ASSERT_TRUE(count.first.first == -1.0);
    ASSERT_TRUE(count.first.second == 1.0);
    ASSERT_TRUE(count.second == 2);
}

TEST(SphereTest, SphereIntersect5)
{
    Tuple origin = tuples::point(0, 0, 5);
    Tuple direction = tuples::vector(0, 0, 1);
    Ray ray{origin, direction};
    Shapes::Sphere sphere{};
    std::pair< std::pair<double, double>, int> count = sphere.intersect(ray);
    ASSERT_TRUE(count.first.first == -6.0);
    ASSERT_TRUE(count.first.second == -4.0);
    ASSERT_TRUE(count.second == 2);
}

TEST(IntersectionTest, Intersect1)
{
    Shapes::Sphere s{};
    Shapes::intersection i1{3.5, s};
    ASSERT_EQ(i1.t, 3.5);
    ASSERT_EQ(i1.object.getId(), s.getId());
    
    
}

TEST(IntersectionTest, Intersect2)
{
    Shapes::Sphere s{};
    Shapes::Sphere t{};
    Shapes::intersection i1{1, s};
    Shapes::intersection i2{2, s};
    

    
}