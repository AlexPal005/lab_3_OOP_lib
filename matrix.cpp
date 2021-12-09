#include "matrix.h"
#include <iostream>



matrix::matrix()
{
    cout << endl << "It is possible to introduce an extended matrix to solve the system!" << endl;

    cout << "Enter the number of rows of the matrix! " << endl;

    cin >> row;

    cout << endl << "Enter the number of columns in the matrix:" << endl;

    cin >> column;

    cout << endl << "Enter the numbers:" << endl;

    matr = new double* [row];

    elementary = new double* [row];

    for (int i = 0; i < row; i++) {

        matr[i] = new double[column];

        elementary[i] = new double[row];

    }

    for (int i = 0; i < row; i++) {

        cout << "Enter" << " " << i + 1 << " " << " row" << endl;

        for (int j = 0; j < column; j++)

            cin >> matr[i][j];

    }
}
void matrix::get_matrix() {

    cout << "Matrix:" << endl;

    for (int i = 0; i < row; i++) {

        for (int j = 0; j < column; j++)

            cout << matr[i][j] << " ";

        cout << endl;
    }
}
void matrix::subtraction_matrix(matrix matrix_1, matrix matrix_2) {

    if (matrix_2.row == matrix_1.row && matrix_2.column == matrix_1.column) {

        for (int i = 0; i < row; i++) {

            for (int j = 0; j < column; j++)

                matr[i][j] = matrix_1.matr[i][j] - matrix_2.matr[i][j];

        }

        cout << "Subtraction done!" << endl;

        get_matrix();
    }
    else

        cout << "The dimensions of the matrices must be the same!" << endl;
}
void matrix::add_matrix(matrix matrix_1, matrix matrix_2) {

    if (matrix_2.row == matrix_1.row && matrix_2.column == matrix_1.column) {

        for (int i = 0; i < row; i++) {

            for (int j = 0; j < column; j++)

                matr[i][j] = matrix_1.matr[i][j] + matrix_2.matr[i][j];

        }

        cout << "Add complete!" << endl;

        get_matrix();
    }

    else

        cout << "The dimensions of the matrices must be the same!";
}
void matrix::multiplic_number(int num) {

    for (int i = 0; i < row; i++) {

        for (int j = 0; j < column; j++)

            matr[i][j] = num * matr[i][j];

    }

    cout << "Multiplication done!" << endl;

    get_matrix();
}
void matrix::mult(matrix matrix_1, matrix matrix_2) {

    if (matrix_1.column == matrix_2.row) { //умова, що кількість стовпців першої матриці = кількості рядків другої матриці

        double** mat1;

        mat1 = new double* [matrix_1.row];

        for (int i = 0; i < matrix_1.row; i++)

            mat1[i] = new double[matrix_2.column];

        float sum = 0.0;

        for (int i = 0; i < matrix_1.row; i++) {

            for (int j = 0; j < matrix_2.column; j++) {

                for (int k = 0; k < matrix_1.column; k++) {

                    sum += matrix_1.matr[i][k] * matrix_2.matr[k][j];

                }

                mat1[i][j] = sum;

                sum = 0;

            }
        }

        cout << "Multiplication done!" << endl;

        for (int i = 0; i < matrix_1.row; i++) {

            for (int j = 0; j < matrix_2.column; j++)

                cout << mat1[i][j] << " ";

            cout << endl;

        }

        for (int i = 0; i < matrix_1.row; i++)

            delete[]mat1[i];

        delete[]mat1;

    }

    else

        cout << "Dimensions error!" << endl;

}
double matrix::det() {

    if (row == column) {

        if (row == 1)

        {

            return matr[0][0];

        }

        else if (row == 2)
        {


            return matr[0][0] * matr[1][1] - matr[0][1] * matr[1][0];

        }

        else if (row == 3) {

            return (matr[0][0] * (matr[1][1] * matr[2][2] - matr[2][1] * matr[1][2])) - (matr[0][1] * (matr[1][0] * matr[2][2] - matr[1][2] * matr[2][0])) + (matr[0][2] * (matr[1][0] * matr[2][1] - matr[1][1] * matr[2][0]));

        }

        else {

            double sum = 0;

            double** z;

            z = new double* [row];

            for (int i = 0; i < row; i++) {

                z[i] = new double[row];
            }

            sum = det_for(matr, row);

            for (int i = 0; i < row; i++) {

                delete[] z[i];
            }
            delete[] z;

            return sum;
        }
    }

    else {

        cout << "Error..Please enter an NxN matrix" << endl;

        return false;
    }

}
double matrix::det_for(double** z, int p) {

    double sum = 0, product;

    int sign = 1, n, row;

    double** inner, member;

    inner = new double* [p - 1];

    for (int i = 0; i < p - 1; i++) {

        inner[i] = new double[p - 1];
    }
    for (int i = 0; i < p; i++) {

        row = 0;

        n = 0;
        for (int j = 0; j < p; j++) {

            for (int k = 0; k < p; k++) {

                member = z[j][k];

                inner[row][n] = member;

                n++;

                if (n == p - 1) {
                    n = 0;
                    row += 1;

                }
            }
        }

        product = sign * z[0][i] * det_for(inner, p - 1);

        sum += product;

        sign = sign * -1;
    }

    for (int i = 0; i < p - 1; i++)

        delete[] inner[i];

    delete[] inner;


    return sum;
}
void matrix::memory() {

    for (int i = 0; i < row; i++) {

        delete[] matr[i];

        delete[]elementary[i];
    }

    delete[] matr;

    delete[]elementary;
}



matrix::~matrix()
{
}

