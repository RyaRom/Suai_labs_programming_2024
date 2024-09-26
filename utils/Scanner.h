//
// Created by locadm on 9/13/2024.
//

#ifndef SCANNER_H
#define SCANNER_H
#include <iostream>
#include <bits/basic_ios.h>
#include <vector>

#include "../collections/LinkedList.h"


class Scanner {
public:
    template<typename T>
    static void fill_array(std::vector<T> &array);

    template<typename T>
    static void fill_matrix(std::vector<std::vector<T> > &matrix);

    template<typename T>
    static void fill_list(LinkedList<T> *list, int count);
};

template<typename T>
void Scanner::fill_array(std::vector<T> &array) {
    std::cout << "Enter the array elements:\n";
    for (int i = 0; i < array.size(); i++) {
        std::cin >> array[i];
    }
}

template<typename T>
void Scanner::fill_matrix(std::vector<std::vector<T> > &matrix) {
    std::cout << "Enter the matrix elements:\n";
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            std::cin >> matrix[i][j];
        }
    }
}

template<typename T>
void Scanner::fill_list(LinkedList<T> *list, const int count) {
    std::cout << "Enter the list elements:\n";
    T data;
    for (int i = 0; i < count; ++i) {
        std::cin >> data;
        list->add(data);
    }
}


#endif //SCANNER_H
