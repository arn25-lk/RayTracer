#ifndef MATRIX_H
#define MATRIX_H

#include "tuples.h"
#include <vector>



class Matrix
{
    private: 
        unsigned int nr_rows, nr_cols;
        std::vector<std::vector<double> > m_matrix;
    public:
        Matrix(unsigned, unsigned, double a = 0.0);
        Matrix(double[][4]);

        Matrix operator+(const Matrix&) const;
        Matrix operator-(const Matrix&) const;
        Matrix operator*(const Matrix&) const;
        bool operator==(const Matrix&) const;
        // Scalar Operations
        // Matrix operator+(double);
        // Matrix operator-(double);
        // Matrix operator*(double);
        // Matrix operator/(double);
        Matrix operator/(const double) const;
        //Tuple Operations
        Tuple operator*(const Tuple&) const;
        //Operations
        Matrix transpose() const;
        double cofactor4(const int& , const int&);
        Matrix submatrix4(const int& , const int&);
        //Minors of 4x4 matrix
        double minor4(const int& , const int&);
        //Determinant of 4x4 matrix
        double determinant4();
        Matrix inverse();
        
        double& operator()(const unsigned &, const unsigned &);
        

        unsigned getRows();
        unsigned getCols();
        void print();
        
        

};
extern const Matrix IDENTITY_MATRIX;

namespace util 
{ 
    bool approximatelyEqual(double a, double b, float epsilon = 0.0001);
    Matrix translation(double x, double y, double z); 
    Matrix scaling(double x, double y, double z);
    Matrix shearing(double x, double y, double z);
    double degree_to_radians(double degrees);
    double radians_to_degree(double radians);
    Matrix rotationX(double theta);
    Matrix rotationY(double theta);
    Matrix rotationZ(double theta);
    Matrix shearing(double xTy, double xTz, double yTx, double yTz, double zTx, double zTy);
}

#endif
