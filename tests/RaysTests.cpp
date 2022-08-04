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
    Shapes::Intersections obj = sphere.intersect(ray);
    ASSERT_TRUE(obj[0]->t == 4.0);
    ASSERT_TRUE(obj[1]->t == 6.0);
    ASSERT_TRUE(obj.getCount() == 2);
}
TEST(SphereTest, SphereIntersect2)
{
    Tuple origin = tuples::point(0, 1, -5);
    Tuple direction = tuples::vector(0, 0, 1);
    Ray ray{origin, direction};
    Shapes::Sphere sphere{};
    Shapes::Intersections obj = sphere.intersect(ray);
    ASSERT_TRUE(obj[0]->t == 5.0);
    ASSERT_TRUE(obj.getCount() == 1);
}

TEST(SphereTest, SphereIntersect3)
{
    Tuple origin = tuples::point(0, 2, -5);
    Tuple direction = tuples::vector(0, 0, 1);
    Ray ray{origin, direction};
    Shapes::Sphere sphere{};
    Shapes::Intersections obj = sphere.intersect(ray);
    ASSERT_TRUE(obj.getCount() == 0);
    
    
}

TEST(SphereTest, SphereIntersect4)
{
    Tuple origin = tuples::point(0, 0, 0);
    Tuple direction = tuples::vector(0, 0, 1);
    Ray ray{origin, direction};
    Shapes::Sphere sphere{};

    Shapes::Intersections obj = sphere.intersect(ray);
    ASSERT_TRUE(obj.getCount() == 2);
    ASSERT_TRUE( (obj[0]->t) == -1.0);
    ASSERT_TRUE( (obj[1]->t) == 1.0);
}

TEST(SphereTest, SphereIntersect5)
{
    Tuple origin = tuples::point(0, 0, 5);
    Tuple direction = tuples::vector(0, 0, 1);
    Ray ray{origin, direction};
    Shapes::Sphere sphere{};
    Shapes::Intersections obj = sphere.intersect(ray);
    ASSERT_TRUE(obj.getCount() == 2);
    ASSERT_TRUE( (obj[0]->t) == -6.0);
    ASSERT_TRUE( (obj[1]->t) == -4.0);
}

TEST(IntersectionTest, Intersect1)
{
    Shapes::Sphere s{};
    Shapes::Intersection i1{3.5, s};
    ASSERT_EQ(i1.t, 3.5);
    ASSERT_EQ(i1.object.getId(), s.getId());
}

TEST(IntersectionTest, Intersect2)
{
    using namespace Shapes;
    Sphere s{};
    Intersection i1{1,s};
    Intersection i2{2,s};
    Intersections intersections{};
    intersections.add(i1);
    intersections.add(i2);
    ASSERT_EQ(intersections.getCount(), 2);
    ASSERT_EQ(intersections[0]->t, 1);
    ASSERT_EQ(intersections[1]->t, 2);
    ASSERT_EQ(intersections[0]->object.getId(), s.getId());
    ASSERT_EQ(intersections[1]->object.getId(), s.getId());   
}
TEST(HitTest, Intersect1){
    using namespace Shapes;
    Sphere s{};
    Intersection i1{1, s};
    Intersection i2{2, s};
    Intersections intersections{};
    intersections.add(i1);
    intersections.add(i2);
    auto i = hit(intersections);
    ASSERT_EQ(i1.t, i->t);
    ASSERT_EQ(i1.object.getId(), i->object.getId());
}

TEST(HitTest, HitTest1){
    using namespace Shapes;
    Sphere s{};
    Intersection i1{1, s};
    Intersection i2{2, s};
    Intersections intersections{};
    intersections.add(i1);
    intersections.add(i2);
    auto i = hit(intersections);
    ASSERT_EQ(i1.t, i->t);
    ASSERT_EQ(i1.object.getId(), i->object.getId());
}

TEST(HitTest, HitTest2){
    using namespace Shapes;
    Sphere s{};
    Intersection i1{-1, s};
    Intersection i2{1, s};
    Intersections intersections{};
    intersections.add(i1);
    intersections.add(i2);
    auto i = hit(intersections);
    ASSERT_EQ(i2.t, i->t);
    ASSERT_EQ(i2.object.getId(), i->object.getId());
}

TEST(HitTest, Intersect3){
    using namespace Shapes;
    Sphere s{};
    Intersection i1{-1, s};
    Intersection i2{-2, s};
    Intersections intersections{};
    intersections.add(i1);
    intersections.add(i2);
    auto i = hit(intersections);
    EXPECT_FALSE(i);
}

TEST(HitTest, Intersect4){
    using namespace Shapes;
    Sphere s{};
    Intersection i1{5, s};
    Intersection i2{7, s};
    Intersection i3{-3, s};
    Intersection i4{2, s};
    Intersections intersections{};
    intersections.add(i1);
    intersections.add(i2);
    intersections.add(i3);
    intersections.add(i4);
    auto i = hit(intersections);
    ASSERT_EQ(i4.t, i->t);
}