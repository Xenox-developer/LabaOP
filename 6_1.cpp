//На вход поступает квадратная матрица размером не более [1000,1000]. 
//Программа ищет значение характеристического полинома (A^3 - 3*A^2 - 3*A + 8E)^2
//Выполнил Чиндин Никита, ПМИ-13БО

#include <iostream>
#include <iomanip>
#include "matrix.h"
#include "correct_input.h"
#include "Working_on_matrix.h"
using namespace std;



int main()
{
    int n = 0;
    double det = 0;
    double matrix_size;

    cout << "Please, enter the size of a square matrix A: ";
    correct_input_N(n);

    //матрица пользователя
    double** original_matrix = matrix_input(n, n);

    //Вывод характеристического полинома (A^3 - 3*A^2 - 3*A + 8E)^2
    polynomial_solution(original_matrix, n);
    cout << "\n";

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