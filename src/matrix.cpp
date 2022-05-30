#include "matrix.h"
#include <vector>
#include <iostream>

static double arr[4][4] =
{
    {1,0,0,0},
    {0,1,0,0},
    {0,0,1,0},
    {0,0,0,1}
};

Matrix IDENTITY_MATRIX = Matrix(arr);


Matrix::Matrix(unsigned int nr_rows, unsigned int nr_cols, double value)
{
    this->nr_rows = nr_rows;
    this->nr_cols = nr_cols;
    this->m_matrix.resize(nr_rows, std::vector<double>());
    for(unsigned int i = 0; i < nr_rows; i++){
        (this->m_matrix[i]).resize(nr_cols, value);
        
    }
}

Matrix::Matrix(double arr[][4])
{
    this->nr_rows = 4;
    this->nr_cols = 4;

    this->m_matrix.resize(4, std::vector<double>());
    for(unsigned int i = 0; i < nr_rows; i++){
        (this->m_matrix[i]).resize(nr_cols, 0.0);
    }
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            this->m_matrix[i][j] = arr[i][j];
        }
    }
}



Matrix Matrix::operator+(Matrix& a)
{   
    Matrix result{this->nr_rows, this->nr_cols, 0};

    //Evaluate a + b
    if(this->nr_rows != a.nr_rows || this->nr_cols != a.nr_cols){
        throw std::invalid_argument("Matrix dimensions do not match");
    }
    for(int i = 0; i < this->nr_rows; i++){
        for(int j = 0; j < this->nr_rows; j++){
            result(i, j) = this->m_matrix[i][j] + a.m_matrix[i][j];
        }
    }
    return result;
    
}

Matrix Matrix::operator-(Matrix& b)
{   
    Matrix result{this->nr_rows, this->nr_cols, 0};

    //Evaluate a + b
    if(this->nr_rows != b.nr_rows || this->nr_cols != b.nr_cols){
        throw std::invalid_argument("Matrix dimensions do not match");
    }
    for(int i = 0; i < this->nr_rows; i++){
        for(int j = 0; j < this->nr_rows; j++){
            result(i, j) = this->m_matrix[i][j] - b.m_matrix[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(Matrix& b)
{
    Matrix result{this->nr_rows, b.nr_cols};
    if(this->nr_cols != b.nr_rows){
        throw std::invalid_argument("Matrices Cannot be Multiplied");
    }
    for(int i = 0; i < this->nr_rows; i++){
        for(int j = 0; j < b.nr_cols; j++)
        {
            for(int k = 0; k < this->nr_cols; k++)
            {
                result(i, j) += this->m_matrix[i][k] * b.m_matrix[k][j];
            }
        }
    }
    return result;
}



bool Matrix::operator==(Matrix& a)
{
    for(int i = 0; i < this->nr_rows; i++)
    {
        for(int j = 0; j < this->nr_cols; j++)
        {
            if(this->m_matrix[i][j] != a(i,j))
            {
                return false;
            }
        }
    }
    return true;
}

Tuple Matrix::operator*(Tuple& b)
{
    if(this->nr_cols != 4 || this->nr_rows != 4){
        throw std::invalid_argument("Matrix Dimensions Don't Match");
    }
    double arr[4]{b.get_x(), b.get_y(), b.get_z(), b.get_w()};
    double res[4]{0,0,0,0};
    for(int i = 0; i < this->nr_rows; i++)
    {
        for(int j = 0; j < this->nr_cols; j++)
        {
            res[i] += this->m_matrix[i][j] * arr[j];
        }
    }
    Tuple result{res[0], res[1], res[2], res[3]};
    return result;

}
Matrix Matrix::transpose()
{
    Matrix result{this->nr_cols, this->nr_rows};
    for (int i = 0; i < this->nr_rows; i++)
    {
        for (int j = 0; j < this->nr_cols; j++)
        {
            result(j, i) = this->m_matrix[i][j];
        }
    }
    return result;
}
Matrix Matrix::submatrix4(const int& i, const int& j)
{
    Matrix result{this->nr_rows - 1, this->nr_cols - 1};
    int resX{0}; int resY{0};
    for(int x = 0; x < this->nr_rows; x++)
    {
        resY = 0;
        for(int y = 0; y < this->nr_cols; y++)
        {
            if(x != i && y != j)
            {
                result(resX, resY) = this->m_matrix[x][y];
                resY++;
            }
        }
        if(x!=i){
            resX++;
        }
        
    }
    return result;
}

double Matrix::minor4(const int& i, const int& j)
{
    Matrix b = this->submatrix4(i, j);
    return b.determinant4();
}

double Matrix::cofactor4(const int& i, const int& j)
{
    double det = this->minor4(i,j);
    return (i + j) % 2 == 0 ? det : -1 * det;
}
double Matrix::determinant4(){
    if(this->nr_rows != this->nr_cols){
        throw std::invalid_argument("Matrix is not square");
    }
    if(this->nr_rows == 2 && this->nr_cols == 2){
        return this->m_matrix[0][0] * this->m_matrix[1][1] - this->m_matrix[0][1] * this->m_matrix[1][0];
    }
    double result = 0;
    for(int i = 0; i < this->nr_cols; i++){
        result += this->m_matrix[0][i] * cofactor4(0, i);
    }
    return result;
}
Matrix Matrix::inverse()
{
    if(this->determinant4() == 0){
        throw std::invalid_argument("Matrix is not invertible");
    }
    Matrix result{this->nr_rows, this->nr_cols, 0};
    for(int i = 0; i < this->nr_rows; i++){
        for(int j = 0; j < this->nr_cols; j++){
            result(i, j) = this->cofactor4(i, j) / this->determinant4();
        }
    }
    return result.transpose();
}

double& Matrix::operator()(const unsigned& i , const unsigned& j){
    return this->m_matrix[i][j];
}
unsigned Matrix::getRows(){
    return this->nr_rows;
}
unsigned Matrix::getCols(){
    return this->nr_cols;
}
void Matrix::print(){
    for(int i = 0; i < this->nr_rows; i++){
        for(int j = 0; j < this->nr_cols; j++){
            std::cout << this->m_matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
