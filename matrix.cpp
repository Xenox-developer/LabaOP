#include "matrix.h"
#include "correct_input.h"
#include <iostream>
#include <iomanip>
using namespace std;

//Функция проверки корректности ввода
double cheker(double& x) {
	cin >> x;
	while (std::cin.fail()) {
		cout << "That input is invalid. Please try again." << endl;
		cin.clear();
		cin.ignore(32767, '\n');
		cin >> x;
	}
	return x;
}

//Функция подготовки памяти для матриц
double** memory_for_array(double** array, double matrix_size) {
	for (int i = 0; i < matrix_size; i++)
	{
		array[i] = new double[matrix_size];
	}
	return array;
}

//создание нулевой матрицы любого размера
double** matrix_nul_create(int columns_num, int rows_num) {
	double** out_matr = new double* [columns_num];
	for (int i = 0; i < columns_num; i++)
		out_matr[i] = new double[rows_num];

	for (int i = 0; i < columns_num; i++)
		for (int j = 0; j < rows_num; j++)
			out_matr[i][j] = 0;
	return out_matr;
}

//создание еденичной матрицы 
double** unit_matrix(int columns_num) {
	double** out_matr = new double* [columns_num];
	for (int i = 0; i < columns_num; i++)
		out_matr[i] = new double[columns_num];
	for (int i = 0; i < columns_num; i++)
		for (int j = 0; j < columns_num; j++)
			if (i != j)
				out_matr[i][j] = 0;
			else
				out_matr[i][j] = 1;
	return out_matr;
}

//ввод матрицы любого размера
double** matrix_input(double columns_num, double rows_num) {
	double** orig_matr = matrix_nul_create(columns_num, rows_num);
	double element;
	for (int i = 0; i < columns_num; i++)
		for (int j = 0; j < rows_num; j++) {
			cout << "A[" << i + 1 << "][" << j + 1 << "] = ";
			correct_input_R(element);
			orig_matr[i][j] = element;
		}
	return orig_matr;
}

//вывод матрицы любого размера
void matrix_output(double** orig_matr, int columns_num, int rows_num) {
	cout << endl;
	for (int i = 0; i < columns_num; i++) {
		for (int j = 0; j < rows_num; j++)
			cout << setw(10) << fixed << setprecision(0) << orig_matr[i][j];
		cout << endl;
	}
}

//отчистка памяти после создания матрицы
void matrix_memory_clear(double** matr, int columns_num) {
	for (int i = 0; i < columns_num; i++)
		delete[] matr[i];
	delete[] matr;
}

//функция возведения матрицы в квадрат
double** sqr_matrix_pow_2(double** orig_matr, int columns_num) {
	double** out_matr = sqr_matrix_nul_create(columns_num);

	out_matr = sqr_matrix_multiply_matrix(orig_matr, orig_matr, columns_num);
	return out_matr;
}

//функция умножения матрицы любого размера на число
double** matrix_multiply_num(double** matr, int columns_num, int rows_num, int num) {
	double** out_matr = matrix_nul_create(columns_num, rows_num);

	for (int i = 0; i < columns_num; i++)
		for (int j = 0; j < rows_num; j++)
			out_matr[i][j] = num * matr[i][j];
	return out_matr;
}

//функция деления матрицы на число
double** matrix_division_num(double** matr, int columns_num, int rows_num, int num) {
	double** out_matr = matrix_nul_create(columns_num, rows_num);

	for (int i = 0; i < columns_num; i++)
		for (int j = 0; j < rows_num; j++)
			out_matr[i][j] = matr[i][j] / num;
	return out_matr;
}

//функция сложения матриц любого размера
double** matrix_addition_matrix(double** matr_1, double** matr_2, int columns_num, int rows_num) {
	double** out_matr = matrix_nul_create(columns_num, rows_num);

	for (int i = 0; i < columns_num; i++)
		for (int j = 0; j < rows_num; j++)
			out_matr[i][j] = matr_1[i][j] + matr_2[i][j];
	return out_matr;
}

//функция перемножения матриц
double** matrix_multiply_matrix(double** matr_1, int columns_num1, int rows_num1, double** matr_2, int columns_num2, int rows_num2) {
	if (rows_num1 != columns_num2) {
		cout << "Выполнить умножение невозможно.";
		return 0;
	}
	double** out_matr = matrix_nul_create(columns_num1, rows_num2);
	for (int i = 0; i < columns_num1; i++)
		for (int j = 0; j < rows_num2; j++)
			for (int k = 0; k < rows_num1; k++)
				out_matr[i][j] += matr_1[i][k] * matr_2[k][j];
	return out_matr;
}

//Возвращает матрицу для нахождения минора, путем вырчеркивания row-ой строки и col-того столбца матрицы matr;
void matrix_for_minor(double** matr, int columns_num, int row, int col, double** minor_matr) {
	int row_shift = 0; //Смещение индекса строки в матрице
	int col_shift = 0; //Смещение индекса столбца в матрице
	for (int i = 0; i < columns_num - 1; i++) {
		//Пропустить row-ую строку
		if (i == row)
			row_shift = 1;
		for (int j = 0; j < columns_num - 1; j++) {
			//Пропустить col-ый столбец
			if (j == col)
				col_shift = 1;
			minor_matr[i][j] = matr[i + row_shift][j + col_shift];
		}
	}
}

//Рекурсивная функция для нахождения определителя матрицы. 
int matrix_det(double** matr, int columns_num) {
	//временная матрица, полученная вычеркиванием i-ой строки и 0-ого столбца
	double** temp = sqr_matrix_nul_create(columns_num - 1);
	double det = 0;
	double alg_dop = 0;
	//если дошли до минора 2х2, то возвращаекм его
	if (columns_num == 2) {
		alg_dop = matr[0][0] * matr[1][1] - matr[0][1] * matr[1][0];
		return alg_dop;
	}
	//условие выхода из рекурсии
	if (columns_num == 1) {
		return matr[0][0];
	}
	//знак для высчитывания алгебраического дополнения
	int sign = 1;
	for (int i = 0; i < columns_num; i++) {
		//Удаляем из матрицы i-ую строку и 0-ый столбец
		matrix_for_minor(matr, columns_num, i, 0, temp);

		double minor = matrix_det(temp, columns_num - 1);
		alg_dop = (sign * matr[i][0] * minor);

		//меняем знак
		sign *= -1;
		det += alg_dop;
	}
	matrix_memory_clear(temp, columns_num - 1);
	return det;
}


//вычисление обратной м-цы квадратной
double** matrix_inverse(double** matr, int columns_num) {
	int det = matrix_det(matr, columns_num);
	if (det == 0)
	{
		cout << "\nОпределитель равен 0. Решений для обратной м-цы нет или бесконечно много";
		return 0;
	}

	double** inverse_matr = sqr_matrix_nul_create(columns_num);
	//временная матрица, полученная вычеркиванием i-ой строки и 0-ого столбца
	double** temp = sqr_matrix_nul_create(columns_num - 1);
	int sign = 1;
	for (int i = 0; i < columns_num; i++)
		for (int j = 0; j < columns_num; j++) {
			matrix_for_minor(matr, columns_num, i, 0, temp);
			inverse_matr[i][j] = (1 / det) * sign * matrix_det(temp, columns_num - 1);
			if (abs(inverse_matr[i][j]) < 0.000000000001)
				inverse_matr[i][j] = 0;
		}

	return inverse_matr;
}

double** polynomial_solution(double** matrix, double matrix_size)
{
	double** characteristic_polynomial = new double* [matrix_size];
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
	 double** identity_matrix = new  double* [matrix_size];
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

//решение системы матриц только для матриц одного порядка
void matrix_system_solution(double** matr_A, double** matr_B, double** matr_C1, double** matr_C2, int columns_num, int rows_num) {
	cout << "Выражаем матрицу B:\nB = 2A - C2\n";
	cout << "Подставляем матрицу B в первое уравнение и получаем:\nA + 6A -3C2 = C1\n";
	cout << "Путём преобразований, получаем:\nA(1+6) = C1 + 3C2 ---> A = (C1 + 3C2) * (1 + 6)\n";
	//(1+6)A = 3С2 + С1
	cout << "______________________\n";
	
	cout << "Сумма матриц C1 + 3C2 = \n";
	matr_C2 = matrix_multiply_num(matr_C2, columns_num, rows_num, 3);
	double** C1_add_C2 = matrix_addition_matrix(matr_C1, matr_C2, columns_num, rows_num);
	matrix_output(C1_add_C2, columns_num, rows_num);
	
	cout << "______________________\n";
	//получаем еденичную матрицу для 1 + 6
	cout << "______________________\n";	
	cout << "A = (С1 + 3C2) * (1 + 6) * E = \n";
	matrix_output(C1_add_C2, columns_num, rows_num);
	
	cout << " * ";
	
	double** temp_matr = unit_matrix(rows_num);
	temp_matr = matrix_multiply_num(temp_matr, rows_num, rows_num, 7);
	matrix_output(temp_matr, rows_num, rows_num);
	
	cout << "______________________\n";
	//находим матрицу А
	cout << "______________________\n";
	cout << "Нашли матрицу А = \n";
	matr_A = matrix_multiply_matrix(C1_add_C2, columns_num, rows_num, temp_matr, rows_num, rows_num);
	matrix_output(matr_A, columns_num, rows_num);
	
	cout << "______________________\n";
	//имеем выражение 3A - B = С1
	//находим A*(-1)
	cout << "Находим матрицу В через первое уравнение:\nB = (C1 - A) / 3\n";
	cout << "______________________\n";
	cout << "Матрица A * (-1)= \n";
	double** negative_matrixA = matrix_multiply_num(matr_A, columns_num, rows_num, -1);
	matrix_output(negative_matrixA, columns_num, rows_num);
	
	cout << "______________________\n";
	//находим C1
	cout << "______________________\n";
	cout << "(C1 - A) / 3 = \n";
	matrix_output(matr_C1, columns_num, rows_num);
	cout << " + ";
	matrix_output(negative_matrixA, columns_num, rows_num);
	cout << "______________________\n";
	//находим матрицу B
	matr_B = matrix_addition_matrix(negative_matrixA, matr_C1, columns_num, rows_num);
	temp_matr = unit_matrix(rows_num);
	temp_matr = matrix_division_num(temp_matr,columns_num, rows_num, 3);
	matr_B = matrix_multiply_matrix(matr_B, columns_num, rows_num, temp_matr, rows_num, rows_num);

	matrix_memory_clear(C1_add_C2, columns_num);
	matrix_memory_clear(temp_matr, rows_num);
	matrix_memory_clear(negative_matrixA, columns_num);
}
