//
// Created by locadm on 9/13/2024.
//
#include <iostream>
#include "Lab1.h"
#include "Utils/PrintStream.h"

#include "Utils/Scanner.h"
#define SWAP_ARRAY(array, i,j) \
int temp = array[i]; \
array[i] = array[j]; \
array[j] = temp;

template<typename T>
void Lab1<T>::main() {
    lab1_first();
    lab1_second();
}

template<typename T>
void Lab1<T>::lab1_first() {
    int n;
    printf("Enter the n. Size of the array is n * 2: \n");
    std::cin >> n;
    n = n * 2;
    std::vector<T> arr;
    arr.resize(n);
    Scanner::fill_array(arr);

    std::cout << "Original array: ";
    PrintStream::print_array(arr);

    Lab1::swap_array_elem(arr);

    std::cout << "Modified array: ";
    PrintStream::print_array(arr);
}

template<typename T>
void Lab1<T>::lab1_second() {
}

template<typename T>
void Lab1<T>::swap_array_elem(std::vector<T> &array) {
    const int size = array.size();
    const int n = size / 2;
    for (int i = 0; i < size; i++) {
        if (i < n) {
            SWAP_ARRAY(array, i, size - i - 1);
        } else if (i < n + n / 2) {
            SWAP_ARRAY(array, i, size - i - 1 + n);
        }
    }
}

template<typename T>
double Lab1<T>::matrix_find_average(std::vector<std::vector<T> > &matrix) {
    int count = 0;
    double sum = 0;
    const int size = matrix.size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j <= i && i >= size / 2 && matrix[i][j] < 0) {
                sum += matrix[i][j];
                count++;
            }
        }
    }
    if (count == 0) return 0;
    return sum / count;
}
