//
// Created by locadm on 9/13/2024.
//

#ifndef LAB1_H
#define LAB1_H
#include <vector>

template<typename T>
class Lab1 {
public:
    Lab1() = default;

    ~Lab1() = default;

    static void main();

private:
    static void lab1_first();

    static void lab1_second();

    static void swap_array_elem(std::vector<T> &array);

    static double matrix_find_average(std::vector<std::vector<T> > &matrix);
};


#include "Lab1.tpp"
#endif //LAB1_H
