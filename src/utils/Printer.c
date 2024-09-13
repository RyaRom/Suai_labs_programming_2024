//
// Created by locadm on 9/12/2024.
//

#include "Printer.h"

#include <stdio.h>

void print_int_array(const int *array, const int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void print_int_matrix(const int **matrix, const int rows, const int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
