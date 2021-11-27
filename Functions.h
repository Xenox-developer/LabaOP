#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//������� �������� ������������ �����
long double Cheker(long double& x);

//������� ����� �������
void Matrix_Input(long double** matrix, long double matrix_size);

//������� ��������� ������
long double** Subtraction(long double** matrix, long double** b, int matrix_size);

//������� �������� ������
long double** Summation(long double** matrix, long double** matrix2, int matrix_size);

//������� ��������� ������� �� �����
long double** Multiply_on_num(long double** matrix, long double matrix_size, long double num);

//������� ��������� ������
long double** Matrix_Multiply(long double** matrix, long double** matrix2, long double matrix_size);

//������� ���������� ������� � �������
long double** Matrix_Power(long double** matrix, long double matrix_size, int num);

//��������� �������
void Identity_matrix(long double** identity_matrix, long double matrix_size);

//������� ���������� ������ ��� ������
long double** Memory_for_array(long double** array, long double matrix_size);

//������� ������ �������
void Output(long double** matrix, int matrix_size);

//������� ������� ������ ������
void Clean_matrix(long double** matrix, int matrix_size);

#endif // FUNCTIONS_H