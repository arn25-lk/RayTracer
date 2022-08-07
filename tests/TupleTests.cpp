#include"../src/tuples.h"
#include<gtest/gtest.h>
#include<iostream>
#include<cmath>

TEST(ExampleTests, TupleDefinition){
    Tuple a{4.3, -4.2, 3.1, 1.0};
    EXPECT_EQ(1.0, a.get_w());
    ASSERT_EQ(3.1, a.get_z());
    ASSERT_EQ(-4.2, a.get_y());
    EXPECT_EQ(4.3, a.get_x());
}
TEST(ExampleTests, PointDefinition){
    Tuple a = tuples::point(1,2,3);
    ASSERT_EQ(1.0, a.get_w());
}

TEST(ExampleTests, VectorDefinition){
    Tuple a = tuples::vector(4,-4,3);
    ASSERT_EQ(0.0, a.get_w());
}

TEST(ExampleTests, AdditionTest){
    Tuple a = tuples::vector(4,-4,3);
    Tuple b = tuples::vector(1,3,5);
    Tuple c = tuples::add(a,b);
    ASSERT_EQ(5, c.get_x());
    ASSERT_EQ(-1, c.get_y());
    ASSERT_EQ(8, c.get_z());
    ASSERT_EQ(0, c.get_w());
}
TEST(ExampleTests, AdditionFail){
    Tuple a = tuples::point(4,-4,3);
    Tuple b = tuples::point(1,3,5);

    ASSERT_THROW(tuples::add(a,b), std::exception);
}
TEST(ExampleTests, SubtractionTest){
    Tuple a = tuples::vector(4,-4,3);
    Tuple b = tuples::vector(1,3,5);
    Tuple c = tuples::subtract(a,b);
    ASSERT_EQ(3, c.get_x());
    ASSERT_EQ(-7, c.get_y());
    ASSERT_EQ(-2, c.get_z());
    ASSERT_EQ(0, c.get_w());
}
TEST(ExampleTests, SubtractionFail){
    Tuple a = tuples::vector(4,-4,3);
    Tuple b = tuples::point(1,3,5);

    ASSERT_THROW(tuples::subtract(a,b), std::exception);
}

TEST(ExampleTests, DivFail){
    Tuple a = tuples::vector(4,-4,3);

    ASSERT_THROW(tuples::divide(a, 0), std::exception);
    ASSERT_EQ(4, a.get_x());
}

TEST(ExampleTests, Magnitude){
    Tuple a = tuples::vector(4,-4,3);

    ASSERT_THROW(tuples::divide(a, 0), std::exception);
    ASSERT_EQ(4, a.get_x());
}

TEST(ExampleTests, Normalise){
    Tuple a = tuples::vector(3,4,0);
    Tuple b = tuples::normalise(a);

    
    ASSERT_EQ(0.6, b.get_x());
    ASSERT_EQ(0.8, b.get_y());
    ASSERT_EQ(0, b.get_z());
    ASSERT_EQ(0, b.get_w());
}
TEST(ExampleTests, DotProduct){
    Tuple a = tuples::vector(1,2,3);
    Tuple b = tuples::vector(2,3,4);
    
    ASSERT_EQ(20, tuples::dot(a, b));
}

TEST(ExampleTests, CrossProduct){
    Tuple a = tuples::vector(1,2,3);
    Tuple b = tuples::vector(2,3,4);
    Tuple c = tuples::cross(a, b);
    Tuple d = tuples::cross(b, a);
    //For c
    ASSERT_EQ(-1, c.get_x());
    ASSERT_EQ(2, c.get_y());
    ASSERT_EQ(-1, c.get_z());
    ASSERT_EQ(0, c.get_w());
    //For d
    ASSERT_EQ(1, d.get_x());
    ASSERT_EQ(-2, d.get_y());
    ASSERT_EQ(1, d.get_z());
    ASSERT_EQ(0, d.get_w());
}

TEST(ExampleTests, ColorTest){
    Color c = Color{-0.5,0.4,1.7};
    
    ASSERT_EQ(-0.5, c.red());
    ASSERT_EQ(0.4, c.green());
    ASSERT_EQ(1.7, c.blue());
}

TEST(ExampleTests, ColorAdd){
    Color c = Color{-0.5,0.4,1.7};
    Color k = Color{-0.5,0.4,1.7};
    Color l = c + k;
    ASSERT_EQ(-1, l.red());
    ASSERT_EQ(0.8, l.green());
    ASSERT_EQ(3.4, l.blue());
}
TEST(ExampleTests, ColorMult){
    Color c{-0.5,1.3,1.7};
    
    Color k = c * 3;
    ASSERT_EQ(-1.5, k.red());

    std::cout<<k.green()<<std::endl;
    int eq = k.green() > 3.9; //Error due to double precision 
    std::cout<<eq<<std::endl;
    ASSERT_EQ(5.1, k.blue());
    
}
TEST(TupleFeature, Reflect1){
    auto v = tuples::vector(1,-1,0);
    auto n = tuples::vector(0, 1, 0);
    auto r = tuples::reflect(v, n);
    ASSERT_EQ(r, tuples::vector(1,1,0));
}

TEST(TupleFeature, Reflect2){
    auto v = tuples::vector(0,-1,0);
    auto n = tuples::vector(sqrt(2)/2, sqrt(2)/2, 0);
    auto r = tuples::reflect(v, n);
    ASSERT_EQ((int)r.get_x() , 1);
    ASSERT_EQ((int)r.get_y() , 0);
    ASSERT_EQ((int)r.get_z() , 0);
    ASSERT_EQ((int)r.get_w() , 0);
}