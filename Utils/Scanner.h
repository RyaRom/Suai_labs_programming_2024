//
// Created by locadm on 9/13/2024.
//

#ifndef SCANNER_H
#define SCANNER_H
#include <iostream>
#include <bits/basic_ios.h>


class Scanner {
    Scanner() = default;

    ~Scanner() = default;

    template<typename T, std::size_t Size>
    static void fill_int_array(std::array<T, Size> &array);

    template<typename T, std::size_t Rows, std::size_t Cols>
    void fill_int_matrix(std::array<std::array<T, Cols>, Rows> &matrix);
};

template<typename T, std::size_t Size>
void Scanner::fill_int_array(std::array<T, Size> &array) {
    std::cout<<"Enter the array elements:\n";
    for (int i = 0; i < Size; i++) {
        std::cin >> array[i];
    }
}

template<typename T, std::size_t Rows, std::size_t Cols>
void Scanner::fill_int_matrix(std::array<std::array<T, Cols>, Rows> &matrix) {
    std::cout<<"Enter the matrix elements:\n";
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            std::cin >> matrix[i][j];
        }
    }
}


#endif //SCANNER_H
