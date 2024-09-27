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
    static void fill_list(LinkedList<T> *list);
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
void Scanner::fill_list(LinkedList<T> *list) {
    std::cout << "Enter the list elements: (enter . to stop)\n";
    std::string input;
    while (true) {
        std::cin >> input;
        if (input == ".") {
            break;
        }

        std::stringstream ss(input);
        T data;
        ss >> data;

        if (!ss.fail()) {
            list->add(data);
        } else {
            std::cerr << "Invalid input, please try again.\n";
        }
    }
}


#endif //SCANNER_H
