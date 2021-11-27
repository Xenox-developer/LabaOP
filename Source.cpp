#include <iostream>
#include <math.h>
#include <algorithm>
#include <windows.h>
#include "Functions.h"
using namespace std;

int main()
{
    //Первое изменение 
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    long double matrix_size;
    cout << "Введите размер квадратной матрицы: ";
    Cheker(matrix_size);

    long double** matrix = new long double* [matrix_size];
    Memory_for_array(matrix, matrix_size);
    cout << "Введите матрицу:" << "\n";
    Matrix_Input(matrix, matrix_size);

    long double** characteristic_polynomial = new long double* [matrix_size];
    Memory_for_array(characteristic_polynomial, matrix_size);

    //Вычисление A^3
    characteristic_polynomial = Matrix_Power(matrix, matrix_size, 3);
    cout << "Значение A^3:\n";
    Output(characteristic_polynomial, matrix_size);

    //Вычисление A^2
    characteristic_polynomial = Matrix_Power(matrix, matrix_size, 2);
    cout << "Значение A^2:\n";
    Output(characteristic_polynomial, matrix_size);

    //Вычисление A^3 - 3*A^2
    characteristic_polynomial = Subtraction(Matrix_Power(matrix, matrix_size, 3), Multiply_on_num(characteristic_polynomial, matrix_size, 3), matrix_size);
    cout << "Занчение A^3 - 3*A^2:\n";
    Output(characteristic_polynomial, matrix_size);

    //Вычисление A^3 - 3*A^2 - 3*A
    characteristic_polynomial = Subtraction(characteristic_polynomial, Multiply_on_num(matrix, matrix_size, 3), matrix_size);
    cout << "Значение A^3 - 3*A^2 - 3*A:\n";
    Output(characteristic_polynomial, matrix_size);

    long double** identity_matrix = new long double* [matrix_size];
    Identity_matrix(identity_matrix, matrix_size);
    cout << "Единичная матрица E:\n";
    Output(identity_matrix, matrix_size);

    //Вычисление A^3 - 3*A^2 - 3*A + 8E
    characteristic_polynomial = Summation(characteristic_polynomial, Multiply_on_num(identity_matrix, matrix_size, 8), matrix_size);
    cout << "Значение A^3 - 3*A^2 - 3*A + 8E:\n";
    Output(characteristic_polynomial, matrix_size);

    //Вывод характеристического полинома (A^3 - 3*A^2 - 3*A + 8E)^2
    characteristic_polynomial = Matrix_Power(characteristic_polynomial, matrix_size, 2);
    cout << "Значение харктеристического полинома (A^3 - 3*A^2 - 3*A + 8E)^2:\n";
    Output(characteristic_polynomial, matrix_size);

    //Очистка памяти
    Clean_matrix(matrix, matrix_size);
    Clean_matrix(characteristic_polynomial, matrix_size);
    Clean_matrix(identity_matrix, matrix_size);

    system("pause");
    return 0;
}

/*
2
1 2
3 4
*/

/*
2
1.3 2.1
3.7 4.32
*/

/*
4
345 421 321 544
423 921 476 843
912 432 532 678
901 538 791 252
*/