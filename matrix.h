#include <armadillo>
#ifndef MATRIX_H
#define MATRIX_H
using namespace std;


class matrix
{
public:
    matrix();
    ~matrix();
    void get_matrix();
    void subtraction_matrix(matrix matrix_1, matrix matrix_2);
    void add_matrix(matrix matrix_1, matrix matrix_2);
    void multiplic_number(int num);
    void mult(matrix matrix_1, matrix matrix_2);
    double det();
    double det_for(double** z, int p);
    void memory();
    void  solve();
    void single_matrix();


protected:

private:
    int row, column; // кількість рядків так стовпчиків матриці
    double** matr;
    double** elementary;
};
#endif