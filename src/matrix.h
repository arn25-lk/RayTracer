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

        Matrix operator+(Matrix&);
        Matrix operator-(Matrix&);
        Matrix operator*(Matrix&);
        bool operator==(Matrix&);
        // Scalar Operations
        // Matrix operator+(double);
        // Matrix operator-(double);
        // Matrix operator*(double);
        // Matrix operator/(double);
        //Tuple Operations
        Tuple operator*(Tuple&);
        //Operations
        Matrix transpose();
        double cofactor4(const int& , const int&);
        Matrix submatrix4(const int& , const int&);
        double minor4(const int& , const int&);
        double determinant4();
        Matrix inverse();
        
        double& operator()(const unsigned &, const unsigned &);
        

        unsigned getRows();
        unsigned getCols();
        void print();
        
        

};
extern Matrix IDENTITY_MATRIX; 

#endif
