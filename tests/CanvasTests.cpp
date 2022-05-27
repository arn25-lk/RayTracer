#include "../src/tuples.h"
#include "../src/canvas.h"
#include <iostream>
#include<gtest/gtest.h>

TEST(CanvasTest, Init)
{  
    Canvas c(4,5);
    ASSERT_EQ(c.getHeight(), 5);
    EXPECT_EQ(c.canvas[0][0].red(), 0);
    
}
TEST(CanvasTest, Init2)
{  
    Canvas c(3,5);
    Color c1(1.5, 0, 0);
    Color c2(0, 0.5, 0);
    Color c3(-0.5, 0, 1);
    c.write_pixel(0, 0, c1);
    c.write_pixel(1, 2, c2);
    c.write_pixel(2, 4, c3);
    c.canvas_to_ppm();
    
    
}