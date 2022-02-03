#ifndef MATRIX_H
#define MATRIX_H
//создание нулевой квадратной матрицы
double** sqr_matrix_nul_create(int columns_num);

//отчистка памяти после создания матрицы
void matrix_memory_clear(double** matr, int columns_num);

//ввод квадратной матрицы
double** sqr_matrix_input(int columns_num);

//вывод начальной квадратной матрицы
void sqr_matrix_output(double** orig_matr, int columns_num);

//функция сложения квадратной матрицы с числом
double** sqr_matrix_addition_num(double** matr, int columns_num, int num);

//функция умножения квадратной матрицы на число
double** sqr_matrix_multiply_num(double** matr, int columns_num, int num);

//функция сложения квадратных матриц
double** sqr_matrix_addition_matrix(double** matr_1, double** matr_2, int columns_num);

//функция перемножения квадратных матриц
double** sqr_matrix_multiply_matrix(double** matr_1, double** matr_2, int columns_num);

//функция возведения матрицы в квадрат
double** sqr_matrix_pow_2(double** orig_matr, int columns_num);

//Рекурсивная функция для нахождения определителя матрицы.
int matrix_det(double** matr, int columns_num);

//Возвращает матрицу minor_matr для нахождения минора, путем вырчеркивания row-ой строки и col-того столбца матрицы matr;
void matrix_for_minor(double** matr, int columns_num, int row, int col, double** minor_matr);

//создание нулевой матрицы любого размера
double** matrix_nul_create(int columns_num, int rows_num);

//ввод матрицы любого размера
double** matrix_input(int columns_num, int rows_num);

//вывод матрицы любого размера
void matrix_output(double** orig_matr, int columns_num, int rows_num);

//функция умножения матрицы любого размера на число
double** matrix_multiply_num(double** matr, int columns_num, int rows_num, int num);

//функция деления матрицы любого размера на число
double** matrix_division_num(double** matr, int columns_num, int rows_num, int num);

//функция сложения матриц любого размера
double** matrix_addition_matrix(double** matr_1, double** matr_2, int columns_num, int rows_num);

//функция перемножения матриц
double** matrix_multiply_matrix(double** matr_1, int columns_num1, int rows_num1, double** matr_2, int columns_num2, int rows_num2);

//вычисление обратной м-цы
double** matrix_inverse(double** matr, int columns_num);

//решение системы матриц
void matrix_system_solution(double**& matr_A, double**& matr_B, double** matr_C1, double** matr_C2, int columns_num, int rows_num);

#endif
