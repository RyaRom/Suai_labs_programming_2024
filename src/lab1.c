#include <stdio.h>
#include <stdlib.h>

#include "utils/Printer.h"
#include "utils/Scanner.h"

int find_first_max_negative(const int *array, int size);

int find_last_negative_before_n(const int *array, int n);

int array_sum_of_even_i(const int *array, int lower_bound, int upper_bound);

void lab1_first() {
    int n;
    printf("Enter the n. Size of the array is n * 2: \n");
    scanf("%d", &n);
    n = n * 2;
    int *array = malloc(n * sizeof(int));
    fill_int_array(array, n);

    printf("Original array: ");
    print_array(array, n);

    const int lower_bound = find_first_max_negative(array, n);
    const int upper_bound = find_last_negative_before_n(array, n);
    if (lower_bound == -1 || upper_bound == -1 || lower_bound > upper_bound) {
        printf("No suitable elements found.\n");
        return;
    }

    int sum = array_sum_of_even_i(array, lower_bound, upper_bound);
    printf("Sum of even elements between the first and last negative elements: %d\n", sum);
}

int find_first_max_negative(const int *array, const int size) {
    if (array == NULL || size <= 0) {
        return -1;
    }
    int max_index = 0;
    int max = array[0];
    for (int i = size - 1; i > 0; i--) {
        if (array[i] <= 0 && array[i] > max) {
            max_index = i;
            max = array[i];
        }
    }
    return max_index;
}

int find_last_negative_before_n(const int *array, int n) {
    if (array == NULL || n <= 0) {
        return -1;
    }
    int last_index = -1;
    for (int i = 0; i < n; i++) {
        if (array[i] < 0) {
            last_index = i;
        }
    }
    return last_index;
}

int array_sum_of_even_i(const int *array, int lower_bound, int upper_bound) {
    if (array == NULL) {
        return -1;
    }
    int sum = 0;
    for (int i = lower_bound; i < upper_bound; i++) {
        if (i % 2 == 0) sum += array[i];
    }
    return sum;
}
