#include <iostream>
#include "Functions.h"
using namespace std;

//Функция проверки корректности ввода
long double Cheker(long double& x) {
    std::cin >> x;
    while (std::cin.fail()) {
        std::cout << "That input is invalid. Please try again." << std::endl;
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        std::cin >> x;
    }
    return x;
}


//Функция ввода матрицы
void Matrix_Input(long double** matrix, long double matrix_size)
{
    for (int i = 0; i < matrix_size; i++)
    {
        for (int j = 0; j < matrix_size; j++)
        {
            Cheker(matrix[i][j]);
        }
    }
}

//Функция вычитания матриц
long double** Subtraction(long double** matrix, long double** matrix2, int matrix_size) {
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
long double** Summation(long double** matrix, long double** matrix2, int matrix_size) {
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
long double** Multiply_on_num(long double** matrix, long double matrix_size, long double num) {
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
long double** Matrix_Multiply(long double** matrix, long double** matrix2, long double matrix_size)
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
long double** Matrix_Power(long double** matrix, long double matrix_size, int num)
{
    if (num == 1)
        return matrix;
    if (num % 2 == 1)
        return Matrix_Multiply(Matrix_Power(matrix, matrix_size, num - 1), matrix, matrix_size);
    else {
        matrix = Matrix_Power(matrix, matrix_size, num / 2);
        return Matrix_Multiply(matrix, matrix, matrix_size);
    }
}

//Единичная матрица
void Identity_matrix(long double** identity_matrix, long double matrix_size) {
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
long double** Memory_for_array(long double** array, long double matrix_size) {
    for (int i = 0; i < matrix_size; i++)
    {
        array[i] = new long double[matrix_size];
    }
    return array;
}

//Функция вывода матрицы
void Output(long double** matrix, int matrix_size) {
    for (int i = 0; i < matrix_size; i++)
    {
        for (int j = 0; j < matrix_size; j++)
        {
            cout.width(5);
            printf(" %Lf \t", matrix[i][j]);
            //cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
}

//Функция очистки памяти матриц
void Clean_matrix(long double** matrix, int matrix_size) {
    for (int i = 0; i < matrix_size; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

