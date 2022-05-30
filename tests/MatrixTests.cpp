#include "../src/matrix.h"
#include<gtest/gtest.h>

TEST(MatrixTest , Init)
{
    Matrix m(4,5,0.0);
    ASSERT_EQ(m.getRows(), 4);
    ASSERT_EQ(m.getCols(), 5);
    EXPECT_EQ(m(0,0), 0);
}

TEST(MatrixTest , Init2  )
{

    double arr[4][4]{
        {1,2,3,4},
        {5.5,6.5,7.5,8.5},
        {9,10,11,12},
        {13.5,14.5,15.5,16.5}
    };
    Matrix m(4,4,0.0);
    ASSERT_EQ(m.getRows(), 4);
    ASSERT_EQ(m.getCols(), 4);
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            m(i,j) = arr[i][j];
        }
    }
    EXPECT_EQ(m(0,0), 1);
    ASSERT_EQ(m(1,2), 7.5);
    ASSERT_EQ(m(3,3), 16.5);
    ASSERT_EQ(m(3,2), 15.5);
}

TEST(MatrixTest , InitTest  )
{

    double arr[4][4]{
        {1,2,3,4},
        {5.5,6.5,7.5,8.5},
        {9,10,11,12},
        {13.5,14.5,15.5,16.5}
    };
    Matrix m(4,4,0.0);
    ASSERT_EQ(m.getRows(), 4);
    ASSERT_EQ(m.getCols(), 4);
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            m(i,j) = arr[i][j];
        }
    }
    EXPECT_EQ(m(0,0), 1);
    ASSERT_EQ(m(1,2), 7.5);
    ASSERT_EQ(m(3,3), 16.5);
    ASSERT_EQ(m(3,2), 15.5);

}
TEST(MatrixTest, Eq1)
{
    Matrix m1(4,4,0.0);
    Matrix m2(4,4,0.0);
    ASSERT_EQ(true, m1 == m2);
    double arr[4][4] {
        {1,2,3,4},
        {5,6,7,8},
        {9,8,7,6},
        {5,4,3,2}
    };
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            m1(i,j) = arr[i][j];
            m2(i,j) = arr[i][j];
        }
    }
    ASSERT_EQ(true, m1==m2);
    m2(0,0) = 8;
    ASSERT_EQ(false, m1==m2);
}

TEST(MatrixTest, MatMult1 )
{
    Matrix m1(4,4,0.0);
    Matrix m2(4,4,0.0);
    double arr1[4][4] {
        {1,2,3,4},
        {5,6,7,8},
        {9,8,7,6},
        {5,4,3,2}
    };
    double arr2[4][4] {
        {-2,1,2,3},
        {3,2,1,-1},
        {4,3,6,5},
        {1,2,7,8}
    };
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            m1(i,j) = arr1[i][j];
            m2(i,j) = arr2[i][j];
        }
    }
    double result[4][4] {
        {20,22,50,48},
        {44,54,114,108},
        {40,58,110,102},
        {16,26,46,42}
    };
    Matrix m3 = m1 * m2;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            ASSERT_EQ(result[i][j], m3(i,j));
        }
    }
    
}

TEST(MatrixTest, TupleMultiplication)
{
    Tuple b{1,2,3,1};
    double arr[4][4] {
        {1,2,3,4},
        {2,4,4,2},
        {8,6,4,1},
        {0,0,0,1}
    };
    Matrix m1(arr);
    Tuple a = m1 * b;
    ASSERT_EQ(a.get_x(), 18);
    ASSERT_EQ(a.get_y(), 24);
    ASSERT_EQ(a.get_z(), 33);
    ASSERT_EQ(a.get_w(), 1);   
}

TEST(MatrixTest, IdentityMultiplication)
{
    double arr[4][4] {
        {0,1,2,4},
        {1,2,4,8},
        {2,4,8,16},
        {4,8,16,32}
    };
    Matrix m1(arr);
    Matrix result = m1 * (IDENTITY_MATRIX);
    ASSERT_EQ(true ,result == m1);
    Tuple b{1,2,3,4};
    Tuple tupRes = (IDENTITY_MATRIX) * b;
    ASSERT_EQ(tupRes.get_x(), 1);
    ASSERT_EQ(tupRes.get_y(), 2);
    ASSERT_EQ(tupRes.get_z(), 3);
    ASSERT_EQ(tupRes.get_w(), 4);   
}

TEST(MatrixTest, TransposeMatrix)
{
    double arr[4][4] {
        {0,9,3,0},
        {9,8,0,8},
        {1,8,5,3},
        {0,0,5,8}
    };
    Matrix m1(arr);
    double arr1[4][4] {
        {0,9,1,0},
        {9,8,8,0},
        {3,0,5,5},
        {0,8,3,8}
    };
    Matrix result = m1.transpose();
    Matrix temp(arr1);
    ASSERT_EQ(true ,result == temp );
    temp = result.transpose();
    ASSERT_EQ(true, temp == m1);
}

TEST(MatrixTest, TransposeIdentityMatrix)
{
    Matrix result = IDENTITY_MATRIX.transpose();
    ASSERT_EQ(true ,result == IDENTITY_MATRIX);

}

TEST(MatrixTest, ManipulatingMinors)
{
    Matrix m1(3,3,0);
    double arr[3][3] {
        {3,5,0},
        {2,-1,-7},
        {6, -1, 5}
    };
    for(int i = 0; i < 3; i++) 
    {
        for(int j = 0; j < 3; j++)
        {
            m1(i,j) = arr[i][j];
        }
    }
    ASSERT_EQ(25,m1.minor4(1,0));
}


TEST(MatrixTest, ComputingCofactors)
{
    Matrix m1(3,3,0);
    double arr[3][3] {
        {3,5,0},
        {2,-1,-7},
        {6, -1, 5}
    };
    for(int i = 0; i < 3; i++) 
    {
        for(int j = 0; j < 3; j++)
        {
            m1(i,j) = arr[i][j];
        }
    }
    ASSERT_EQ(-12, m1.minor4(0,0));
    ASSERT_EQ(-12, m1.cofactor4(0,0));
    ASSERT_EQ(25, m1.minor4(1,0));
    ASSERT_EQ(-25, m1.cofactor4(1,0));
}

TEST(MatrixTests, DeterminantTest)
{
    Matrix m1(3,3,0);
    double arr[3][3] {
        {1,2,6},
        {-5,8,-4},
        {2,6,4}
    };
    for(int i = 0; i < 3; i++) 
    {
        for(int j = 0; j < 3; j++)
        {
            m1(i,j) = arr[i][j];
        }
    }
    ASSERT_EQ(m1.cofactor4(0,0), 56);
    ASSERT_EQ(m1.cofactor4(0,1), 12);
    ASSERT_EQ(m1.cofactor4(0,2), -46);
    ASSERT_EQ(m1.determinant4(), -196);


    double arr1[4][4] {
        {-2,-8,3,5},
        {-3,1,7,3},
        {1,2,-9,6},
        {-6,7,7,-9}
    };
    Matrix m2(arr1);
    ASSERT_EQ(m2.cofactor4(0,0), 690);
    ASSERT_EQ(m2.cofactor4(0,1), 447);
    ASSERT_EQ(m2.cofactor4(0,2), 210);
    ASSERT_EQ(m2.cofactor4(0,3), 51);
    ASSERT_EQ(m2.determinant4(), -4071);
}

TEST(MatrixTests, DeterminantTest)
{
    double arr1[4][4] {
        {6,4,4,4},
        {5,5,7,6},
        {4,-9,3,-7},
        {9,1,7,-6}
    };
    Matrix m2(arr1);
    ASSERT_EQ(m2.determinant4(), -2120);
}


