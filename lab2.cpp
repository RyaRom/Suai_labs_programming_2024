#include <iostream>
#include <math.h>
#include <locale.h>
using namespace std;
const int RAZ = 20;
typedef int telem;
typedef telem *ptelem;
typedef ptelem *tmatr;

void inputMatrix(tmatr a, int n);

void output_matr(tmatr a, int n);

void bubbleSort(tmatr a, int start, int end, int column);

void matrixSort(tmatr a, int n);

void zeroing(tmatr a, int n);

int lab2_main() {
    setlocale(LC_ALL, "Russian");
    int exit = 0;
    while (exit != 1) {
        int size, n;
        tmatr matrix;
        cout << "Введите размер n и значения матрицы (2n)x(2n)\n";
        cin >> n;
        size = n * 2;
        matrix = new ptelem[size];
        for (int i = 0; i < size; i++)
            matrix[i] = new telem[size];
        inputMatrix(matrix, size);
        cout << "Матрица:\n";
        output_matr(matrix, size);
        matrixSort(matrix, size);
        cout << "Отсортированная матрица:\n";
        output_matr(matrix, size);
        zeroing(matrix, size);
        cout << "Отсортированная и обнуленная матрица:\n";
        output_matr(matrix, size);
        cout << "Введите 1 чтобы закончить выполнение программы, Введите 0 чтобы продолжить\n";
        cin >> exit;
    }
    return 0;
}

void zeroing(tmatr a, int n) {
    for (int i = 0; i < n; i++) {
        if (i < n / 2) {
            for (int j = 0; j < i; j++) {
                a[j][i] = 0;
            }
            for (int j = n - i; j < n; j++) {
                a[j][i] = 0;
            }
        } else {
            for (int j = 0; j < n - i - 1; j++) {
                a[j][i] = 0;
            }
            for (int j = i + 1; j < n; j++) {
                a[j][i] = 0;
            }
        }
    }
}

void matrixSort(tmatr a, int n) {
    for (int i = 0; i < n; i++) {
        if (i < n / 2) {
            bubbleSort(a, i, n - i - 1, i);
        } else {
            bubbleSort(a, n - i - 1, i, i);
        }
    }
}

void bubbleSort(tmatr a, int start, int end, int column) {
    for (int i = start; i <= end; i++) {
        for (int j = start; j <= start + end - 1 - i; j++) {
            if (a[j][column] > a[j + 1][column]) {
                telem sw = a[j][column];
                a[j][column] = a[j + 1][column];
                a[j + 1][column] = sw;
            }
        }
    }
}

void output_matr(tmatr a, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout.width(3);
            cout << a[i][j];
        }
        cout << endl;
    }
}

void inputMatrix(tmatr a, int n) {
    int i, j;
    cout << " Введите построчно через пробел элементы" << endl;
    cout << " матрицы размера " << n << "x" << n << endl;
    cout << " После ввода строки нажимайте <Enter>" << endl;
    for (i = 0; i < n; i++) {
        cout << " ";
        for (j = 0; j < n; j++) cin >> a[i][j];
    }
}
