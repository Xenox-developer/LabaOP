#include "matrix.h"
#include "correct_input.h"
#include <iostream>
#include <iomanip>
using namespace std;

//������� �������� ������������ �����
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

//������� ���������� ������ ��� ������
double** memory_for_array(double** array, double matrix_size) {
	for (int i = 0; i < matrix_size; i++)
	{
		array[i] = new double[matrix_size];
	}
	return array;
}

//�������� ������� ������� ������ �������
double** matrix_nul_create(int columns_num, int rows_num) {
	double** out_matr = new double* [columns_num];
	for (int i = 0; i < columns_num; i++)
		out_matr[i] = new double[rows_num];

	for (int i = 0; i < columns_num; i++)
		for (int j = 0; j < rows_num; j++)
			out_matr[i][j] = 0;
	return out_matr;
}

//�������� ��������� ������� 
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

//���� ������� ������ �������
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

//����� ������� ������ �������
void matrix_output(double** orig_matr, int columns_num, int rows_num) {
	cout << endl;
	for (int i = 0; i < columns_num; i++) {
		for (int j = 0; j < rows_num; j++)
			cout << setw(10) << fixed << setprecision(0) << orig_matr[i][j];
		cout << endl;
	}
}

//�������� ������ ����� �������� �������
void matrix_memory_clear(double** matr, int columns_num) {
	for (int i = 0; i < columns_num; i++)
		delete[] matr[i];
	delete[] matr;
}

//������� ���������� ������� � �������
double** sqr_matrix_pow_2(double** orig_matr, int columns_num) {
	double** out_matr = sqr_matrix_nul_create(columns_num);

	out_matr = sqr_matrix_multiply_matrix(orig_matr, orig_matr, columns_num);
	return out_matr;
}

//������� ��������� ������� ������ ������� �� �����
double** matrix_multiply_num(double** matr, int columns_num, int rows_num, int num) {
	double** out_matr = matrix_nul_create(columns_num, rows_num);

	for (int i = 0; i < columns_num; i++)
		for (int j = 0; j < rows_num; j++)
			out_matr[i][j] = num * matr[i][j];
	return out_matr;
}

//������� ������� ������� �� �����
double** matrix_division_num(double** matr, int columns_num, int rows_num, int num) {
	double** out_matr = matrix_nul_create(columns_num, rows_num);

	for (int i = 0; i < columns_num; i++)
		for (int j = 0; j < rows_num; j++)
			out_matr[i][j] = matr[i][j] / num;
	return out_matr;
}

//������� �������� ������ ������ �������
double** matrix_addition_matrix(double** matr_1, double** matr_2, int columns_num, int rows_num) {
	double** out_matr = matrix_nul_create(columns_num, rows_num);

	for (int i = 0; i < columns_num; i++)
		for (int j = 0; j < rows_num; j++)
			out_matr[i][j] = matr_1[i][j] + matr_2[i][j];
	return out_matr;
}

//������� ������������ ������
double** matrix_multiply_matrix(double** matr_1, int columns_num1, int rows_num1, double** matr_2, int columns_num2, int rows_num2) {
	if (rows_num1 != columns_num2) {
		cout << "��������� ��������� ����������.";
		return 0;
	}
	double** out_matr = matrix_nul_create(columns_num1, rows_num2);
	for (int i = 0; i < columns_num1; i++)
		for (int j = 0; j < rows_num2; j++)
			for (int k = 0; k < rows_num1; k++)
				out_matr[i][j] += matr_1[i][k] * matr_2[k][j];
	return out_matr;
}

//���������� ������� ��� ���������� ������, ����� ������������� row-�� ������ � col-���� ������� ������� matr;
void matrix_for_minor(double** matr, int columns_num, int row, int col, double** minor_matr) {
	int row_shift = 0; //�������� ������� ������ � �������
	int col_shift = 0; //�������� ������� ������� � �������
	for (int i = 0; i < columns_num - 1; i++) {
		//���������� row-�� ������
		if (i == row)
			row_shift = 1;
		for (int j = 0; j < columns_num - 1; j++) {
			//���������� col-�� �������
			if (j == col)
				col_shift = 1;
			minor_matr[i][j] = matr[i + row_shift][j + col_shift];
		}
	}
}

//����������� ������� ��� ���������� ������������ �������. 
int matrix_det(double** matr, int columns_num) {
	//��������� �������, ���������� ������������� i-�� ������ � 0-��� �������
	double** temp = sqr_matrix_nul_create(columns_num - 1);
	double det = 0;
	double alg_dop = 0;
	//���� ����� �� ������ 2�2, �� ����������� ���
	if (columns_num == 2) {
		alg_dop = matr[0][0] * matr[1][1] - matr[0][1] * matr[1][0];
		return alg_dop;
	}
	//������� ������ �� ��������
	if (columns_num == 1) {
		return matr[0][0];
	}
	//���� ��� ������������ ��������������� ����������
	int sign = 1;
	for (int i = 0; i < columns_num; i++) {
		//������� �� ������� i-�� ������ � 0-�� �������
		matrix_for_minor(matr, columns_num, i, 0, temp);

		double minor = matrix_det(temp, columns_num - 1);
		alg_dop = (sign * matr[i][0] * minor);

		//������ ����
		sign *= -1;
		det += alg_dop;
	}
	matrix_memory_clear(temp, columns_num - 1);
	return det;
}


//���������� �������� �-�� ����������
double** matrix_inverse(double** matr, int columns_num) {
	int det = matrix_det(matr, columns_num);
	if (det == 0)
	{
		cout << "\n������������ ����� 0. ������� ��� �������� �-�� ��� ��� ���������� �����";
		return 0;
	}

	double** inverse_matr = sqr_matrix_nul_create(columns_num);
	//��������� �������, ���������� ������������� i-�� ������ � 0-��� �������
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

	//���������� A^3
	characteristic_polynomial = matrix_power(matrix, matrix_size, 3);
	cout << "�������� A^3:\n";
	output(characteristic_polynomial, matrix_size);

	//���������� A^2
	characteristic_polynomial = matrix_power(matrix, matrix_size, 2);
	cout << "�������� A^2:\n";
	output(characteristic_polynomial, matrix_size);

	//���������� A^3 - 3*A^2
	characteristic_polynomial = subtraction(matrix_power(matrix, matrix_size, 3), multiply_on_num(characteristic_polynomial, matrix_size, 3), matrix_size);
	cout << "�������� A^3 - 3*A^2:\n";
	output(characteristic_polynomial, matrix_size);

	//���������� A^3 - 3*A^2 - 3*A
	characteristic_polynomial = subtraction(characteristic_polynomial, multiply_on_num(matrix, matrix_size, 3), matrix_size);
	cout << "�������� A^3 - 3*A^2 - 3*A:\n";
	output(characteristic_polynomial, matrix_size);

	//�������� ��������� �������
	 double** identity_matrix = new  double* [matrix_size];
	identity_matrix_create(identity_matrix, matrix_size);
	cout << "��������� ������� E:\n";
	output(identity_matrix, matrix_size);

	//���������� A^3 - 3*A^2 - 3*A + 8E
	characteristic_polynomial = summation(characteristic_polynomial, multiply_on_num(identity_matrix, matrix_size, 8), matrix_size);
	cout << "�������� A^3 - 3*A^2 - 3*A + 8E:\n";
	output(characteristic_polynomial, matrix_size);

	//������� ��������� �������� (A^3 - 3*A^2 - 3*A + 8E)^2
	characteristic_polynomial = matrix_power(characteristic_polynomial, matrix_size, 2);
	cout << "�������� ������������������ �������� (A^3 - 3*A^2 - 3*A + 8E)^2:\n";
	output(characteristic_polynomial, matrix_size);
	return characteristic_polynomial;

	clean_matrix(characteristic_polynomial, matrix_size);
}

//������� ������� ������ ������ ��� ������ ������ �������
void matrix_system_solution(double** matr_A, double** matr_B, double** matr_C1, double** matr_C2, int columns_num, int rows_num) {
	cout << "�������� ������� B:\nB = 2A - C2\n";
	cout << "����������� ������� B � ������ ��������� � ��������:\nA + 6A -3C2 = C1\n";
	cout << "���� ��������������, ��������:\nA(1+6) = C1 + 3C2 ---> A = (C1 + 3C2) * (1 + 6)\n";
	//(1+6)A = 3�2 + �1
	cout << "______________________\n";
	
	cout << "����� ������ C1 + 3C2 = \n";
	matr_C2 = matrix_multiply_num(matr_C2, columns_num, rows_num, 3);
	double** C1_add_C2 = matrix_addition_matrix(matr_C1, matr_C2, columns_num, rows_num);
	matrix_output(C1_add_C2, columns_num, rows_num);
	
	cout << "______________________\n";
	//�������� ��������� ������� ��� 1 + 6
	cout << "______________________\n";	
	cout << "A = (�1 + 3C2) * (1 + 6) * E = \n";
	matrix_output(C1_add_C2, columns_num, rows_num);
	
	cout << " * ";
	
	double** temp_matr = unit_matrix(rows_num);
	temp_matr = matrix_multiply_num(temp_matr, rows_num, rows_num, 7);
	matrix_output(temp_matr, rows_num, rows_num);
	
	cout << "______________________\n";
	//������� ������� �
	cout << "______________________\n";
	cout << "����� ������� � = \n";
	matr_A = matrix_multiply_matrix(C1_add_C2, columns_num, rows_num, temp_matr, rows_num, rows_num);
	matrix_output(matr_A, columns_num, rows_num);
	
	cout << "______________________\n";
	//����� ��������� 3A - B = �1
	//������� A*(-1)
	cout << "������� ������� � ����� ������ ���������:\nB = (C1 - A) / 3\n";
	cout << "______________________\n";
	cout << "������� A * (-1)= \n";
	double** negative_matrixA = matrix_multiply_num(matr_A, columns_num, rows_num, -1);
	matrix_output(negative_matrixA, columns_num, rows_num);
	
	cout << "______________________\n";
	//������� C1
	cout << "______________________\n";
	cout << "(C1 - A) / 3 = \n";
	matrix_output(matr_C1, columns_num, rows_num);
	cout << " + ";
	matrix_output(negative_matrixA, columns_num, rows_num);
	cout << "______________________\n";
	//������� ������� B
	matr_B = matrix_addition_matrix(negative_matrixA, matr_C1, columns_num, rows_num);
	temp_matr = unit_matrix(rows_num);
	temp_matr = matrix_division_num(temp_matr,columns_num, rows_num, 3);
	matr_B = matrix_multiply_matrix(matr_B, columns_num, rows_num, temp_matr, rows_num, rows_num);

	matrix_memory_clear(C1_add_C2, columns_num);
	matrix_memory_clear(temp_matr, rows_num);
	matrix_memory_clear(negative_matrixA, columns_num);
}
