#ifndef WORKING_ON_MATRIX_H
#define WORKING_ON_MATRIX_H
//������� ����� �������
void matrix_input(long double** matrix, long double matrix_size);

//������� �������� ������������ �����
long double cheker(long double& x);

//������� ��������� ������
long double** subtraction(long double** matrix, long double** matrix2, int matrix_size);

//������� �������� ������
long double** summation(long double** matrix, long double** matrix2, int matrix_size);

//������� ��������� ������� �� �����
long double** multiply_on_num(long double** matrix, long double matrix_size, long double num);

//������� ��������� ������
long double** matrix_multiply(long double** matrix, long double** matrix2, long double matrix_size);

//������� ���������� ������� � �������
long double** matrix_power(long double** matrix, long double matrix_size, int num);

//��������� �������
void identity_matrix_create(long double** identity_matrix, long double matrix_size);

//������� ���������� ������ ��� ������
long double** memory_for_array(long double** array, long double matrix_size);

//������� ������ �������
void output(long double** matrix, int matrix_size);

void matrix_output(long double** orig_matr, int n);

//������� ������� ������ ������
void clean_matrix(long double** matrix, int matrix_size);

//������� ������� ��������� ��������
long double** polynomial_solution(long double** matrix, long double matrix_size);

//����������� ������� ��� ���������� ������������ �������. 
long double matrix_det(long double** matr, int n);

//�������� ������� ���������� �������
long double** matrix_nul_create(int n);

//���������� ������� ��� ���������� ������, ����� ������������� row-�� ������ � col-���� ������� ������� matr;
void matrix_minor(long double** matrix, int n, int row, int col, long double** minor_matr);

#endif // WORKING_ON_MATRIX_H