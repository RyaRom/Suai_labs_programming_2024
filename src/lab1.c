#include <stdio.h>
#include <stdlib.h>

#include "utils/Scanner.h"


void lab1() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    n = n * 2 - 1;
    int *array = malloc(n * sizeof(int));
    fill_int_array(array, n);
}


void print_matrix(const int **matrix, const int rows, const int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void read_matrix(int **matrix, const int cols, const int rows) {
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: \n", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

