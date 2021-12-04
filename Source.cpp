//На вход поступает квадратная матрица размером не более [1000,1000]. 
//Программа ищет значение характеристического полинома (A^3 - 3*A^2 - 3*A + 8E)^2
//Выполнил Чиндин Никита, ПМИ-13БО

#include <iostream>
#include <algorithm>
#include <math.h>
#include <windows.h>
#include "Functions.h"
using namespace std;
//Изменено
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
