//Сума, добуток, різниця матриць

#include <iostream>
#include "matrix.h"

using namespace arma;

int main()
{
    setlocale(LC_ALL, "ru");

    Mat<double> matrix_a = randu(3, 3);
    Mat<double> matrix_b = randu(3, 3);

    cout << "Меню" << endl;
    cout << "1. Додавання матриць \n" "2. Вiднiмання матриць\n" "3. Транспонована матриця\n"
        "4. Помножити матрицю на скаляр/n" "5.Найбiльший елемент матрицi\n" << endl;;
 
         int number_of_menu = 0;

         cin >> number_of_menu;

        switch (number_of_menu) {

        case 1:
            cout << "Матриця добуток:" << endl;
            cout << matrix_a + matrix_b << endl;

        case 2:
            cout << "Матриця рiзниця:" << endl;
            cout << matrix_a - matrix_b << endl;

        case 3:
            cout << "Матриця до транспонування :" << endl;
            cout << matrix_a << endl;
            cout << "Транспонована матриця:" << endl;
            cout << matrix_a.t() << endl;

        case 4:

            cout << "Матриця до множення :" << endl;
            cout << matrix_a << endl;

            cout << "Уведiть число, на яке потрiбно помножити матрицю: " << endl;
            double k;
            cin >> k;
            cout << "Матриця помножена на:" << k << endl;
            cout << matrix_a * k << endl;

        case 5:
            cout << "Найбiльший елемент матрицi:" << endl;
            cout << matrix_a << endl;
            cout << "Дорiвнює :"<<matrix_a.max() << endl;

            
        
 return 0;
 
}
