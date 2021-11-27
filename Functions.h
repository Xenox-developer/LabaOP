#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//Функция проверки корректности ввода
long double Cheker(long double& x);

//Функция ввода матрицы
void Matrix_Input(long double** matrix, long double matrix_size);

//Функция вычитания матриц
long double** Subtraction(long double** matrix, long double** b, int matrix_size);

//Функция сложения матриц
long double** Summation(long double** matrix, long double** matrix2, int matrix_size);

//Функция умножения матрицы на число
long double** Multiply_on_num(long double** matrix, long double matrix_size, long double num);

//Функция умножения матриц
long double** Matrix_Multiply(long double** matrix, long double** matrix2, long double matrix_size);

//Функция возведения матрицы в степень
long double** Matrix_Power(long double** matrix, long double matrix_size, int num);

//Единичная матрица
void Identity_matrix(long double** identity_matrix, long double matrix_size);

//Функция подготовки памяти для матриц
long double** Memory_for_array(long double** array, long double matrix_size);

//Функция вывода матрицы
void Output(long double** matrix, int matrix_size);

//Функция очистки памяти матриц
void Clean_matrix(long double** matrix, int matrix_size);

#endif // FUNCTIONS_H