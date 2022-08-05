#include "../src/ray.h"
#include<gtest/gtest.h>
#include<cmath>

TEST(SphereInit, SphereInit1){
    Shapes::Sphere s1{};
    Shapes::Sphere s2{};
    Shapes::Sphere s3{};
    Shapes::Sphere s4{};
    Shapes::Sphere s5{};

    ASSERT_EQ(s1.getId(), 0);
    ASSERT_EQ(s2.getId(), 1);
    ASSERT_EQ(s3.getId(), 2);
    ASSERT_EQ(s4.getId(), 3);
    ASSERT_EQ(s5.getId(), 4);

}

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
TEST(TransformationTest, RayTranslate1){
    Tuple origin = tuples::point(1, 2, 3);
    Tuple direction = tuples::vector(1, 0, 0);
    Ray ray{origin, direction};
    auto translate = util::translation(3,4,5);
    auto resultantRay = ray.transform(translate);
    auto pt = tuples::point(4,6,8);
    EXPECT_EQ(resultantRay.getOrigin(), pt);
    EXPECT_EQ(resultantRay.getDirection(), direction);
}
TEST(TransformationTest, RayScale){
    Tuple origin = tuples::point(1, 2, 3);
    Tuple direction = tuples::vector(0, 1, 0);
    Ray ray{origin, direction};
    auto translate = util::scaling(2,3,4);
    auto resultantRay = ray.transform(translate);
    auto pt = tuples::point(2,6,12);
    auto vt = tuples::vector(0,3,0);
    EXPECT_EQ(resultantRay.getOrigin(), pt);
    EXPECT_EQ(resultantRay.getDirection(), vt);
}
TEST(SphereProperties, RTransform1){
    Shapes::Sphere s1{};
    auto m = s1.getTransform();
    EXPECT_TRUE(m == IDENTITY_MATRIX);
}

TEST(SphereProperties, RTransform2){
    Shapes::Sphere s1{};
    auto t = util::translation(2,3,4);
    s1.setTransform(t);
    auto m = s1.getTransform();
    EXPECT_TRUE(m == t);
}

TEST(SphereProperties, IntersectingScaledRayWithSphere){
    Ray r {tuples::point(0,0,-5), tuples::vector(0,0,1)};
    Shapes::Sphere s{};
    s.setTransform(util::scaling(2,2,2));
    auto xs = s.intersect(r);
    ASSERT_EQ(xs.getCount(), 2);
    ASSERT_EQ(xs[0]->t, 3);
    ASSERT_EQ(xs[1]->t, 7);
}
TEST(SphereProperties, ComputingNormal1){
    Shapes::Sphere s{};
    auto n = s.normalAt(tuples::point(1,0,0));
    ASSERT_EQ(n, tuples::vector(1,0,0));
}

TEST(SphereProperties, ComputingNormal2){
    Shapes::Sphere s{};
    auto n = s.normalAt(tuples::point(0,1,0));
    ASSERT_EQ(n, tuples::vector(0,1,0));
}
TEST(SphereProperties, ComputingNormal3){
    Shapes::Sphere s{};
    auto n = s.normalAt(tuples::point(0,0,1));
    ASSERT_EQ(n, tuples::vector(0,0,1));
}
TEST(SphereProperties, ComputingNormal4){
    Shapes::Sphere s{};
    EXPECT_TRUE(s.getTransform() == IDENTITY_MATRIX);
    auto n = s.normalAt(tuples::point(sqrt(3)/3,sqrt(3)/3,sqrt(3)/3));
    ASSERT_EQ(n, tuples::vector(sqrt(3)/3,sqrt(3)/3,sqrt(3)/3));
}

TEST(SphereProperties, ComputingNormalTranslatedSphere){
    Shapes::Sphere s{};
    s.setTransform(util::translation(0,1,0));
    auto n = s.normalAt(tuples::point(0,1.70711,-0.70711));
    auto resVec = tuples::vector(0,0.70711,-0.70711);
    ASSERT_EQ(n, resVec);
}
TEST(SphereProperties, ComputingNormalTranslatedSphere2){
    Shapes::Sphere s{};
    auto transform = util::scaling(1,0.5,1) * util::rotationZ(M_PI/5);
    s.setTransform(transform);
    auto n = s.normalAt(tuples::point(0,sqrt(2)/2,-sqrt(2)/2));
    ASSERT_EQ(n, tuples::vector(0, 0.97014, -0.24254));
}
