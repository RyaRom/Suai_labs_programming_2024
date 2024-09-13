#include <stdio.h>
#include <stdlib.h>

#include "utils/Printer.h"
#include "utils/Scanner.h"

#define SWAP_MATRIX(matrix, i,j) \
    int temp = matrix[i][j]; \
    matrix[i][j] = matrix[j][i]; \
    matrix[j][i] = temp;

#define SWAP_ARRAY(array, i,j) \
    int temp = array[i]; \
    array[i] = array[j]; \
    array[j] = temp;

double matrix_find_average(int **matrix, int size);

void swap_array_elem(int *array, int size);

void lab1_first() {
    int n;
    printf("Enter the n. Size of the array is n * 2: \n");
    scanf("%d", &n);
    n = n * 2;
    int *array = malloc(n * sizeof(int));
    fill_int_array(array, n);

    printf("Original array: ");
    print_array(array, n);

    swap_array_elem(array, n);

    printf("Modified array: ");
    print_array(array, n);
    free(array);
}

void lab1_second() {
    int n;
    printf("Enter the n. Size of the matrix is (n * 2) * (n * 2): \n");
    scanf("%d", &n);
    n = n * 2;
    int **matrix = malloc(n * sizeof(int *));
    fill_int_matrix(matrix, n, n);

    printf("Original matrix: \n");
    print_matrix(matrix, n, n);
    const double avg = matrix_find_average(matrix, n);

    printf("Average in [5+6+7] region %f: \n", avg);
    free(matrix);
}

double matrix_find_average(int **matrix, const int size) {
    if (matrix == NULL || size <= 0) {
        return 0;
    }
    int count = 0;
    int sum = 0;
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

void swap_array_elem(int *array, const int size) {
    const int n = size / 2;
    for (int i = 0; i < size; i++) {
        if (i < n) {
            SWAP_ARRAY(array, i, size - i - 1);
        } else if (i < n + n / 2) {
            SWAP_ARRAY(array, i, size - i - 1 + n);
        }
    }
}
