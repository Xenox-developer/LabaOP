#ifndef WORKING_ON_MATRIX_H
#define WORKING_ON_MATRIX_H
//Функция ввода матрицы
void matrix_input(long double** matrix, long double matrix_size);

//Функция проверки корректности ввода
long double cheker(long double& x);

//Функция вычитания матриц
long double** subtraction(long double** matrix, long double** matrix2, int matrix_size);

//Функция сложения матриц
long double** summation(long double** matrix, long double** matrix2, int matrix_size);

//Функция умножения матрицы на число
long double** multiply_on_num(long double** matrix, long double matrix_size, long double num);

//Функция умножения матриц
long double** matrix_multiply(long double** matrix, long double** matrix2, long double matrix_size);

//Функция возведения матрицы в степень
long double** matrix_power(long double** matrix, long double matrix_size, int num);

//Единичная матрица
void identity_matrix_create(long double** identity_matrix, long double matrix_size);

//Функция подготовки памяти для матриц
long double** memory_for_array(long double** array, long double matrix_size);

//Функция вывода матрицы
void output(long double** matrix, int matrix_size);

void matrix_output(long double** orig_matr, int n);

//Функция очистки памяти матриц
void clean_matrix(long double** matrix, int matrix_size);

//Функция решения заданного полинома
long double** polynomial_solution(long double** matrix, long double matrix_size);

//Рекурсивная функция для нахождения определителя матрицы. 
long double matrix_det(long double** matr, int n);

//создание нулевой квадратной матрицы
long double** matrix_nul_create(int n);

//Возвращает матрицу для нахождения минора, путем вырчеркивания row-ой строки и col-того столбца матрицы matr;
void matrix_minor(long double** matrix, int n, int row, int col, long double** minor_matr);

#endif // WORKING_ON_MATRIX_H