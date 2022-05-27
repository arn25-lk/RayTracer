#ifndef MATRIX_H
#define MATRIX_H

#include<iostream>
#include<vector>
#include "tuples.h"

class Matrix
{
    private:
        unsigned int m_rowSize, m_colSize;
        std::vector<std::vector<double>> m_matrix;
    public:
        Matrix(unsigned, unsigned, double);
        Matrix operator+(Matrix&);
        Matrix operator-(Matrix&);
        Matrix operator*(Matrix&);
        bool operator=(Matrix&);
        // Scalar Operations
        Matrix operator+(double);
        Matrix operator-(double);
        Matrix operator*(double);
        Matrix operator/(double);
        
        Matrix transpose();
        double& operator()(const unsigned &, const unsigned &);

        unsigned getRows() const;
        unsigned getCols() const;
        
        

};
#endif
