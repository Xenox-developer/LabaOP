#include <iomanip>
#include <iostream>
#include "Working_on_matrix.h"
using namespace std;

//создание нулевой квадратной матрицы
long double** matrix_nul_create(int n) {
    long double** out_matr = new long double* [n];
    for (int i = 0; i < n; i++)
        out_matr[i] = new long double[n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            out_matr[i][j] = 0;
    return out_matr;
}

//Функция ввода матрицы
void matrix_input(long double** matrix, long double matrix_size)
{
    for (int i = 0; i < matrix_size; i++)
    {
        for (int j = 0; j < matrix_size; j++)
        {
            cheker(matrix[i][j]);
        }
    }
}

//Функция вычитания матриц
long double** subtraction(long double** matrix, long double** matrix2, int matrix_size) {
    long double** tmp_matrix = new long double* [matrix_size];
    for (int i = 0; i < matrix_size; i++)
    {
        tmp_matrix[i] = new long double[matrix_size];
    }
    for (int i = 0; i < matrix_size; i++)
    {
        for (int j = 0; j < matrix_size; j++)
        {
            tmp_matrix[i][j] = matrix[i][j] - matrix2[i][j];
        }
    }
    return tmp_matrix;
    for (int i = 0; i < matrix_size; i++)
    {
        delete[] tmp_matrix[i];
    }
    delete[] tmp_matrix;
}

//Функция сложения матриц
long double** summation(long double** matrix, long double** matrix2, int matrix_size) {
    long double** tmp_matrix = new long double* [matrix_size];
    for (int i = 0; i < matrix_size; i++)
    {
        tmp_matrix[i] = new long double[matrix_size];
    }
    for (int i = 0; i < matrix_size; i++)
    {
        for (int j = 0; j < matrix_size; j++)
        {
            tmp_matrix[i][j] = matrix[i][j] + matrix2[i][j];
        }
    }
    return tmp_matrix;
    for (int i = 0; i < matrix_size; i++)
    {
        delete[] tmp_matrix[i];
    }
    delete[] tmp_matrix;
}

//Функция умножения матрицы на число
long double** multiply_on_num(long double** matrix, long double matrix_size, long double num) {
    long double** tmp_matrix = new long double* [matrix_size];
    for (int i = 0; i < matrix_size; i++)
    {
        tmp_matrix[i] = new long double[matrix_size];
    }
    for (int i = 0; i < matrix_size; i++)
    {
        for (int j = 0; j < matrix_size; j++)
        {
            tmp_matrix[i][j] = num * matrix[i][j];
        }
    }
    return tmp_matrix;
    for (int i = 0; i < matrix_size; i++)
    {
        delete[] tmp_matrix[i];
    }
    delete[] tmp_matrix;
}

//Функция умножения матриц
long double** matrix_multiply(long double** matrix, long double** matrix2, long double matrix_size)
{
    long double sum;
    long double** tmp_matrix = new long double* [matrix_size];
    for (int i = 0; i < matrix_size; i++)
    {
        tmp_matrix[i] = new long double[matrix_size];
    }
    for (int j = 0; j < matrix_size; j++)
    {
        for (int i = 0; i < matrix_size; i++)
        {
            sum = 0;
            for (int r = 0; r < matrix_size; r++)
            {
                sum += matrix[j][r] * matrix2[r][i];
            }
            tmp_matrix[j][i] = sum;
        }
    }
    return tmp_matrix;
    for (int i = 0; i < matrix_size; i++)
    {
        delete[] tmp_matrix[i];
    }
    delete[] tmp_matrix;
}

//Функция возведения матрицы в степень
long double** matrix_power(long double** matrix, long double matrix_size, int num)
{
    if (num == 1)
        return matrix;
    if (num % 2 == 1)
        return matrix_multiply(matrix_power(matrix, matrix_size, num - 1), matrix, matrix_size);
    else {
        matrix = matrix_power(matrix, matrix_size, num / 2);
        return matrix_multiply(matrix, matrix, matrix_size);
    }
}

//Единичная матрица
void identity_matrix_create(long double** identity_matrix, long double matrix_size) {
    for (int i = 0; i < matrix_size; i++)
    {
        identity_matrix[i] = new long double[matrix_size];
    }
    for (int i = 0; i < matrix_size; i++)
    {
        for (int j = 0; j < matrix_size; j++)
        {
            if (i == j)
                identity_matrix[i][j] = 1;
            else
                identity_matrix[i][j] = 0;
        }
    }
}

//Функция подготовки памяти для матриц
long double** memory_for_array(long double** array, long double matrix_size) {
    for (int i = 0; i < matrix_size; i++)
    {
        array[i] = new long double[matrix_size];
    }
    return array;
}

//Функция вывода матрицы
void output(long double** matrix, int matrix_size) {
    for (int i = 0; i < matrix_size; i++)
    {
        for (int j = 0; j < matrix_size; j++)
        {
            cout.width(5);
            printf(" %Lf \t", matrix[i][j]);
        }
        cout << "\n";
    }
}

//Функция очистки памяти матриц
void clean_matrix(long double** matrix, int matrix_size) {
    for (int i = 0; i < matrix_size; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

long double** polynomial_solution(long double** matrix, long double matrix_size)
{
    long double** characteristic_polynomial = new long double* [matrix_size];
    memory_for_array(characteristic_polynomial, matrix_size);

    //Вычисление A^3
    characteristic_polynomial = matrix_power(matrix, matrix_size, 3);
    cout << "Значение A^3:\n";
    output(characteristic_polynomial, matrix_size);

    //Вычисление A^2
    characteristic_polynomial = matrix_power(matrix, matrix_size, 2);
    cout << "Значение A^2:\n";
    output(characteristic_polynomial, matrix_size);

    //Вычисление A^3 - 3*A^2
    characteristic_polynomial = subtraction(matrix_power(matrix, matrix_size, 3), multiply_on_num(characteristic_polynomial, matrix_size, 3), matrix_size);
    cout << "Занчение A^3 - 3*A^2:\n";
    output(characteristic_polynomial, matrix_size);

    //Вычисление A^3 - 3*A^2 - 3*A
    characteristic_polynomial = subtraction(characteristic_polynomial, multiply_on_num(matrix, matrix_size, 3), matrix_size);
    cout << "Значение A^3 - 3*A^2 - 3*A:\n";
    output(characteristic_polynomial, matrix_size);

    //Создание единичной матрицы
    long double** identity_matrix = new long double* [matrix_size];
    identity_matrix_create(identity_matrix, matrix_size);
    cout << "Единичная матрица E:\n";
    output(identity_matrix, matrix_size);

    //Вычисление A^3 - 3*A^2 - 3*A + 8E
    characteristic_polynomial = summation(characteristic_polynomial, multiply_on_num(identity_matrix, matrix_size, 8), matrix_size);
    cout << "Значение A^3 - 3*A^2 - 3*A + 8E:\n";
    output(characteristic_polynomial, matrix_size);

    //Решение заданного полинома (A^3 - 3*A^2 - 3*A + 8E)^2
    characteristic_polynomial = matrix_power(characteristic_polynomial, matrix_size, 2);
    cout << "Значение харктеристического полинома (A^3 - 3*A^2 - 3*A + 8E)^2:\n";
    output(characteristic_polynomial, matrix_size);
    return characteristic_polynomial;
    
    clean_matrix(characteristic_polynomial, matrix_size);
}

//Возвращает матрицу для нахождения минора, путем вырчеркивания row-ой строки и col-того столбца матрицы matrix;
void matrix_minor(long double** matrix, int matrix_size, int row, int col, long double** minor_matr) {
    int row_shift = 0; //Смещение индекса строки в матрице
    int col_shift = 0; //Смещение индекса столбца в матрице
    for (int i = 0; i < matrix_size - 1; i++) {
        //Пропустить row-ую строку
        if (i == row)
            row_shift = 1;
        col_shift = 0;
        for (int j = 0; j < matrix_size - 1; j++) {
            //Пропустить col-ый столбец
            if (j == col)
                col_shift = 1;
            minor_matr[i][j] = matrix[i + row_shift][j + col_shift];
        }
    }
}

//Рекурсивная функция для нахождения определителя матрицы. 
long double matrix_det(long double** matrix, int matrix_size) {
    //временная матрица, полученная вычеркиванием i-ой строки и 0-ого столбца
    long double** temp = matrix_nul_create(matrix_size - 1);
    double det = 0;
    double alg_dop = 0;
    //если дошли до минора 2х2, то возвращаекм его
    if (matrix_size == 2) {
        alg_dop = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
        return alg_dop;
    }
    //условие выхода из рекурсии
    if (matrix_size == 1) {
        return matrix[0][0];
    }
    //знак для высчитывания алгебраического дополнения
    int sign = 1;
    for (int i = 0; i < matrix_size; i++) {
        //Удаляем из матрицы 
        matrix_minor(matrix, matrix_size, matrix_size, i, temp);

        double det_minor = matrix_det(temp, matrix_size - 1);
        alg_dop = (sign * matrix[matrix_size-1][i] * det_minor);
        sign = -sign;
        //выводим минор 
        output(temp, matrix_size - 1);
        cout << endl;
        //пошаговый вывод
        //cout << sign << " * " << matrix[matrix_size-1][i] << " * " << det_minor << " = " << alg_dop << endl << endl;
        printf("%d * %Lf * %Lf = %Lf\t\n",sign, matrix[matrix_size - 1][i], det_minor, alg_dop);

        det += alg_dop;
    }
    clean_matrix(temp, matrix_size - 1);
    return det;
}