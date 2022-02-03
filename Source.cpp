//На вход поступает квадратная матрица размером не более [1000,1000]. 
//Программа ищет значение характеристического полинома (A^3 - 3*A^2 - 3*A + 8E)^2
//Выполнил Чиндин Никита, ПМИ-13БО

/*#include <iostream>
#include <algorithm>
#include <math.h>
#include <windows.h>
#include "Working_on_matrix.h"
using namespace std;

//Функция проверки корректности ввода
long double cheker(long double& x) {
    std::cin >> x;
    while (std::cin.fail()) {
        std::cout << "That input is invalid. Please try again." << std::endl;
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        std::cin >> x;
    }
    return x;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    long double det = 0;
    long double matrix_size;
    cout << "Введите размер квадратной матрицы: ";
    cheker(matrix_size);

    //единичная матрица
    long double** identity_matrix = new long double* [matrix_size];

    //матрица пользователя
    long double** matrix = new long double* [matrix_size];
    memory_for_array(matrix, matrix_size);
    cout << "Введите матрицу:" << "\n";
    matrix_input(matrix, matrix_size);

    //Вывод характеристического полинома (A^3 - 3*A^2 - 3*A + 8E)^2
    polynomial_solution(matrix, matrix_size);
    cout << "\n";

    det = matrix_det(matrix, matrix_size);
    //cout << "Определитель матрицы A = " << det<<"\n";
    printf("Определитель матрицы А = %Lf\n", det);
        
    //Очистка памяти
    clean_matrix(matrix, matrix_size);

    system("pause");
    return 0;
}

/*
2
1 2
3 4
*/

/*
2
1.3 2.1
3.7 4.32
*/

/*
4
345 421 321 544
423 921 476 843
912 432 532 678
901 538 791 252
*/

/*
4
34 41 32 54
43 92 47 83
92 42 52 67
91 53 71 25
*/

/*
4
1.3 2.1 1.8 2.9
3.7 4.52 3.37 4.39
3.73 4.12 3.74 4.82
3.13 4.53 3.72 4.12
*/


//Программа решает систему из двух уравнений, находя матрицы A и B
//для системы 3A - B = C1 и 6A + B = C2
#include <iostream>
#include <iomanip>
#include "matrix.h"
#include "correct_input.h"
using namespace std;

int main() {
    setlocale(0, "RUS");
    int n, m;
    cout << "The program solves a system of two equations, finding matrices A and B!\n";
    cout << "Given a system:\n{3A - B = C1\n|\n{6A + B = C2\n";
    cout << "Enter the dimension of the matrices:";
    correct_input_N(n);
    correct_input_N(m);
    double** A_matrix = matrix_nul_create(n, m);
    double** B_matrix = matrix_nul_create(n, m);
    cout << "Enter matrix C1: \n";
    double** C1_matrix = matrix_input(n, m);
    cout << "Enter matrix C2:\n";
    double** C2_matrix = matrix_input(n, m);
    cout << "______________________\n";
    cout << "\nMatrix C1:\n";
    matrix_output(C1_matrix, n, m);
    cout << "\nMatrix C1:\n";
    matrix_output(C2_matrix, n, m);
    cout << "______________________\n";
    matrix_system_solution(A_matrix, B_matrix, C1_matrix, C2_matrix, n, m);
    cout << "========Answer========\n";
    cout << "\nMatrix A = \n";
    matrix_output(A_matrix, n, m);
    cout << "\nMatrix B = \n";
    matrix_output(B_matrix, n, m);
    cout << "======================\n";
    matrix_memory_clear(A_matrix, n);
    matrix_memory_clear(B_matrix, n);
    matrix_memory_clear(C1_matrix, n);
    matrix_memory_clear(C2_matrix, n);
    return 0;
}