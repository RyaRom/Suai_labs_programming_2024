//
// Created by locadm on 9/13/2024.
//

#ifndef PRINTER_H
#define PRINTER_H
#include <iostream>
#include <vector>

class PrintStream {
public:
    template<typename T>
    static void print_array(const std::vector<T> &array);

    template<typename T>
    static void print_matrix(const std::vector<std::vector<T> > &matrix);
};

template<typename T>
void PrintStream::print_array(const std::vector<T> &array) {
    for (const T &elem: array) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void PrintStream::print_matrix(const std::vector<std::vector<T> > &matrix) {
    for (const auto &row: matrix) {
        for (const T &elem: row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

#endif //PRINTER_H
