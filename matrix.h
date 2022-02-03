#ifndef MATRIX_H
#define MATRIX_H
//�������� ������� ���������� �������
double** sqr_matrix_nul_create(int columns_num);

//�������� ������ ����� �������� �������
void matrix_memory_clear(double** matr, int columns_num);

//���� ���������� �������
double** sqr_matrix_input(int columns_num);

//����� ��������� ���������� �������
void sqr_matrix_output(double** orig_matr, int columns_num);

//������� �������� ���������� ������� � ������
double** sqr_matrix_addition_num(double** matr, int columns_num, int num);

//������� ��������� ���������� ������� �� �����
double** sqr_matrix_multiply_num(double** matr, int columns_num, int num);

//������� �������� ���������� ������
double** sqr_matrix_addition_matrix(double** matr_1, double** matr_2, int columns_num);

//������� ������������ ���������� ������
double** sqr_matrix_multiply_matrix(double** matr_1, double** matr_2, int columns_num);

//������� ���������� ������� � �������
double** sqr_matrix_pow_2(double** orig_matr, int columns_num);

//����������� ������� ��� ���������� ������������ �������.
int matrix_det(double** matr, int columns_num);

//���������� ������� minor_matr ��� ���������� ������, ����� ������������� row-�� ������ � col-���� ������� ������� matr;
void matrix_for_minor(double** matr, int columns_num, int row, int col, double** minor_matr);

//�������� ������� ������� ������ �������
double** matrix_nul_create(int columns_num, int rows_num);

//���� ������� ������ �������
double** matrix_input(int columns_num, int rows_num);

//����� ������� ������ �������
void matrix_output(double** orig_matr, int columns_num, int rows_num);

//������� ��������� ������� ������ ������� �� �����
double** matrix_multiply_num(double** matr, int columns_num, int rows_num, int num);

//������� ������� ������� ������ ������� �� �����
double** matrix_division_num(double** matr, int columns_num, int rows_num, int num);

//������� �������� ������ ������ �������
double** matrix_addition_matrix(double** matr_1, double** matr_2, int columns_num, int rows_num);

//������� ������������ ������
double** matrix_multiply_matrix(double** matr_1, int columns_num1, int rows_num1, double** matr_2, int columns_num2, int rows_num2);

//���������� �������� �-��
double** matrix_inverse(double** matr, int columns_num);

//������� ������� ������
void matrix_system_solution(double**& matr_A, double**& matr_B, double** matr_C1, double** matr_C2, int columns_num, int rows_num);

#endif
