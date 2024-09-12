#include "Scanner.h"

#include <stdlib.h>
#include <string.h>

#include "collections/AbstractList.h"

int is_integer_internal(const char *str) {
    errno = 0;
    char *endPointer;
    const long val = strtol(str, &endPointer, 10);

    if (errno != 0 || val < INT_MIN || val > INT_MAX) {
        return 0;
    }
    if (endPointer == str || *endPointer != '\0' || val == 0) {
        return 0;
    }
    return val;
}

char *read_line_stdin(const int bufferSize) {
    char *input = malloc(bufferSize * sizeof(char));
    if (input == NULL) return NULL;
    if (scanf("%s", input) != 1) {
        free(input);
        return NULL;
    }
    return input;
}

void read_int_sequence_stdin(const AbstractList *list, void *collection) {
    if (list == NULL || collection == NULL) return;
    char *str;
    do {
        printf("Enter sequence element (enter \"stop\" to stop; enter \"zero\" to add 0):\n");
        str = read_line_stdin(100);

        if (str == NULL) {
            printf("Error reading input.\n");
            continue;
        }

        if (strcmp("zero", str) == 0) {
            list->add_int_elem(collection, 0);
            continue;
        }

        const int data = is_integer_internal(str);
        if (data != 0) {
            list->add_int_elem(collection, data);
        }
    } while (strcmp("stop", str) != 0);
    free(str);
}

char *read_line(FILE *stream, const int bufferSize) {
    char *input = malloc(bufferSize * sizeof(char));
    if (input == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }
    if (fgets(input, bufferSize, stream) != NULL) {
        input[strcspn(input, "\n")] = '\0';
    } else {
        free(input);
        return NULL;
    }
    return input;
}

void fill_int_array(int *array, const int size) {
    if (array == NULL) {
        printf("Error: array is NULL.\n");
        return;
    }
    for (int i = 0; i < size; ++i) {
        printf("Enter the array elements:\n");
        scanf("%d", &array[i]);
    }
}

void fill_int_matrix(int **matrix, const int cols, const int rows) {
    if (matrix == NULL) {
        printf("Error: matrix is NULL.\n");
        return;
    }
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: \n", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}
