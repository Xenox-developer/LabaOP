//�� ���� ��������� ���������� ������� �������� �� ����� [1000,1000]. 
//��������� ��������� ������������ ������� ����������� �� ��������� ������ 
//�������� ������ ������, ���-13��

#include <iostream>
#include <algorithm>
#include <math.h>
#include <windows.h>
#include "matrix.h"
#include "correct_input.h"
using namespace std;

int main() {
	//����������� ���������� �������
	int n;
	//������������ �������
	double det = 0;

	cout << "Enter the size of a square matrix A: ";
	correct_input_N(n);
	cout << "Enter the matrix A: \n";
	double** original_matrix = matrix_input(n);

	det = matrix_det(original_matrix, n);
	cout << "Determinant of a matrix A = " << det;

	matrix_memory_clear(original_matrix, n);
	return 0;
}